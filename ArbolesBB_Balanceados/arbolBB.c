#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolBB.h"



/******************************************************************
* Árboles Binarios de Búsqueda SIN CLAVES REPETIDAS
* Se incluye un poco de código para mostrar la diferencia entre   *
* insertar (paso por referencia) y buscar                         * 
*******************************************************************/

int insertar(tipoArbolBB *raiz,tipoClave clave)
{ tipoNodo *nuevo;
    
	

  	if (*raiz==NULL){
	nuevo=creaNodo(clave,0);
	*raiz=nuevo;
  	} else if((*raiz)->clave==clave){
		(*raiz)->info++;
	  }	else if (clave<(*raiz)->clave){
             return insertar(&((*raiz)->izq),clave);
  	  } else if(clave>(*raiz)->clave){
		  	 return insertar(&((*raiz)->der),clave);		
		}
}
											 //El tipo nodo con doble puntero realmente es un tipoArbolBB como raiz pasado por referencia
int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo){
	if (raiz==NULL){ 
	nodo=NULL;
	return 0;
	} else if(raiz->clave==clave){
		nodo=&raiz;
		//Apuntamos al puntero a tipoNodo y entramos en su información
		return (*nodo)->info;
	  } else if (clave < raiz->clave){
      		return buscar(clave,raiz->izq,nodo);
	  } else if(clave>raiz->clave){
			return buscar(clave,raiz->der,nodo);	
 		}
}


int eliminar(tipoArbolBB *raiz, tipoClave clave){

	tipoNodo *aux,*ant;
	
	if(*raiz==NULL){
	return -1;
	}  else if(clave==(*raiz)->clave){
	   aux=*raiz;
	   
	   		if(((*raiz)->izq==NULL && (*raiz)->der==NULL)||((*raiz)->izq!=NULL && (*raiz)->der==NULL)){
	   		*raiz=aux->izq;
	   		free(aux);
	   		}	else if((*raiz)->izq==NULL && (*raiz)->der!=NULL){
				*raiz=aux->der;
				free(aux);
				}	else{
					ant=aux;
					aux->izq;
					//Nodo mas a la derecha del subárbol izquierdo
					while(aux->der!=NULL){
					ant=aux;
					aux->der;
					}

					(*raiz)->clave=aux->clave;
					(*raiz)->info=aux->info;

					if((*raiz)=ant){
					(*raiz)->izq=aux->izq;
					}	else{
						ant->der=aux->izq;
						}
					
					free(aux);
					}

	   }   else if(clave>(*raiz)->clave){
		   return eliminar(&((*raiz)->der),clave);
	       }   else if(clave<(*raiz)->clave){
			   return eliminar(&((*raiz)->izq),clave);
	  		   }
return 1;
}



int insertarNodoClaveRepetida(tipoArbolBB *raiz, tipoClave k){

	tipoNodo *nuevo;
	tipoNodo *aux;

	if(*raiz==NULL){
	*raiz=creaNodo(k,0);
	}	else if((*raiz)->clave<k){
		return insertar(&((*raiz)->der),k);
		}	else if((*raiz)->clave>k){
			return insertar(&((*raiz)->izq),k);
			}	else if((*raiz)->clave==k){
				(*raiz)->info++;
	
				aux=*raiz;
				aux=aux->izq;
	
				nuevo=creaNodo(k,(*raiz)->info);
				(*raiz)->izq=nuevo;
				nuevo->izq=aux;
				return 1;
				}	else{
					return -1;
					}

return 1;				
}



int eliminar(tipoArbolBB *raiz, tipoClave clave){

	tipoNodo *aux,*ant;	


	if(*raiz==NULL){
	return -1;
	}	else if(clave<(*raiz)->clave){
		return eliminar(&((*raiz)->izq),clave);
		}	else if(clave>(*raiz)->clave){
			return eliminar(&((*raiz)->der),clave);
			}	else if((*raiz)->clave==clave){
					
					if((*raiz)->izq==NULL && (*raiz)->der==NULL){
					aux=*raiz;
					free(aux);
					}	else if((*raiz)->der!=NULL && (*raiz)->izq==NULL){
						aux=*raiz;
						*raiz=aux->der;
						free(aux);
							
							
						}		else if((*raiz)->izq!=NULL && (*raiz)->der==NULL){
								aux=*raiz;
								*raiz=aux->izq;
								free(aux);					
								}		else { //Para ambos!=null
										
										aux=(*raiz);
										ant=aux;
										aux=aux->izq;
				
										while(aux->izq!=NULL){
										aux=aux->izq;
										ant=ant->izq;
										}
										(*raiz)->clave=aux->clave;
										if(aux->der!=NULL){
										ant->izq=aux->der;
										}
										free(aux);
										}

										aux=*raiz;
										ant=aux;	
										aux=aux->der;
										
										while(aux->der!=NULL){
										aux=aux->der;
										ant=ant->der;
										}
										(*raiz)->clave=aux->clave;
										if(aux->izq!=NULL){
										ant->izq=aux->der;
										}
										free(aux);		
				}



}


/*****************************************************************************************
* Funciones GENERALES adaptadas a los dos ejercicios mediante DIRECTIVAS DE COMPILACIÓN  *
/*****************************************************************************************/ 
tipoNodo *creaNodo(tipoClave clave, tipoInfo info)
{ tipoNodo * nuevo;
  //   nuevo =(tipoNodo *)calloc(1, sizeof(tipoNodo));
  if ((nuevo =(tipoNodo *)malloc(sizeof(tipoNodo)))==NULL)
	return NULL;
  else 
	
  {	nuevo->clave = clave;
	nuevo->info=info;
  	nuevo->izq=NULL;
  	nuevo->der=NULL;
  return nuevo;
  }
}

void preOrden(tipoArbolBB a)
{ if (a) { 
	printf("%d %d \n", a->clave,a->info);
  	preOrden(a->izq);
  	preOrden(a->der);
  }
} 

void enOrden(tipoArbolBB a)
{ if (a) { 
	enOrden(a->izq);
	printf("%d %d \n", a->clave,a->info);
    enOrden(a->der);
  }
} 

void posOrden(tipoArbolBB a)
{ if (a) {
  	enOrden(a->izq);
  	enOrden(a->der);
	printf("%d %d \n", a->clave,a->info);
  }
} 

