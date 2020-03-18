#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbolBB.h"

int main(void)
{ tipoArbolBB a=NULL, b=NULL;
  tipoNodo *buscado;
  int encontrado,eliminado;


 if(insertar(&a,25)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,35)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertar(&a,20)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,12)==-1)
 printf("No es posible insertar\n"); 
 if(insertar(&a,13)==-1)
 printf("No es posible insertar\n"); 
 if(insertar(&a,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertar(&a,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertar(&a,15)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,45)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,30)==-1)
 printf("No es posible insertar\n");
 if(insertar(&a,10)==-1)
 printf("No es posible insertar\n");
 printf("Secuencia de los nodos en orden: \n");
 enOrden(a);
 encontrado = buscar(15,a, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error (%d) \n", encontrado);

 encontrado = buscar(100,a, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error(%d) \n", encontrado);

 if(eliminar(&a,20))
	printf("Nodo eliminado correctamente\n");
		else
			printf("Problema al eliminar el nodo\n");

enOrden(a);
//EN ESTA PARTE VOY A INSERTAR NODOS CON CLAVE REPETIDA
if(insertarNodoClaveRepetida(&b,25)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,35)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertarNodoClaveRepetida(&b,20)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,12)==-1)
 printf("No es posible insertar\n"); 
 if(insertarNodoClaveRepetida(&b,13)==-1)
 printf("No es posible insertar\n"); 
 if(insertarNodoClaveRepetida(&b,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertarNodoClaveRepetida(&b,15)==-1)
 printf("No es posible insertar\n"); 
 if(insertarNodoClaveRepetida(&b,15)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,45)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,45)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,30)==-1)
 printf("No es posible insertar\n");
 if(insertarNodoClaveRepetida(&b,10)==-1)
 printf("No es posible insertar\n");
 printf("Secuencia de los nodos en orden: \n");
 enOrden(b);
 encontrado = buscar(15,b, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error (%d) \n", encontrado);

 encontrado = buscar(100,b, &buscado); 
 if (encontrado)
	printf("\nEncontrado nodo con clave %d e información %d \n", buscado->clave,buscado->info);
 else  printf("No existe nodo o error(%d) \n", encontrado);

 if(eliminar(&b,20))
	printf("Nodo eliminado correctamente\n");
		else
			printf("Problema al eliminar el nodo\n");
 enOrden(b);
 return 1;
}


