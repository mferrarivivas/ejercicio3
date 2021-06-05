#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<mpi.h>

void main(int argc, char **argv){

int node, numtasks;

MPI_Status status;

MPI_Init(&argc, &argv);

MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

MPI_Comm_rank(MPI_COMM_WORLD, &node);

if(argc!=2) {
  printf("Falta especificar el tamaño de la matriz.\n"); 
  exit(1);
} 

int fila=atoi(argv[1]),col=fila,f=0,c=0,i=1,matriz[fila][col],vector[col],final[col];
int size= fila* (fila / numtasks);
int parte[size];
if (fila<numtasks){
  if(node==0)
    printf("El numero de filas debe ser mayor a la cantidad de procesos \n");
  exit(1);
}
if ((fila%numtasks)==0){
  if(node==0)
    printf("EL numero de filas no debe ser multiplo de la cantidad de procesos \n");
  exit(1);
}
if (node==0){ //armo matriz y vector
  for(f=0;f<fila;f++){
    for(c=0;c<col;c++){
      matriz[f][c]=i;
      i++;
    }
  }
  i=1;
  for(c=0;c<col;c++){
     vector[c]=i;
     i++;
  } 
}
MPI_Barrier(MPI_COMM_WORLD);
//reparto fila de matriz
MPI_Scatter(matriz,size,MPI_INT,parte,size,MPI_INT,0,MPI_COMM_WORLD);
//reparto vector
MPI_Bcast(vector,col,MPI_INT,0,MPI_COMM_WORLD);
size=fila/numtasks;
int buf[size], r=0;
for(f=0; f<size; f++){
  i=0;
  for(c=0;c<col;c++){
    i=i+(parte[r]*vector[c]);
    r++;
  }
  buf[f]=i;
}

MPI_Gather(buf,size,MPI_INT,final,size,MPI_INT,0,MPI_COMM_WORLD);
if(node==0){
 int falta= fila%numtasks;
 if(falta!=0){
   for(f=fila-falta;f<fila;f++){
      i=0;
     for(c=0;c<col;c++)
       i=i+(matriz[f][c]*vector[c]);
    final[f]=i;
    }
 }
 printf("el resultado es: \n");
  for(i=0;i<fila;i++)
      printf("%d\n",final[i]);
}

MPI_Finalize();

}
