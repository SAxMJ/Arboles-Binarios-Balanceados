


	typedef int tipoClave;

		typedef int tipoInfo;

	typedef struct tipoNodo {
	        tipoClave clave;
	        tipoInfo info;
			int fe;
	        struct tipoNodo *izq,*der;
	} tipoNodo;

	typedef tipoNodo *tipoArbolBB;

	// Funciones proporcionadas en arbolBB.c

	tipoNodo *creaNodo(tipoClave clave,tipoInfo info);
	void enOrden(tipoArbolBB raiz);
	void preOrden(tipoArbolBB raiz);
	void posOrden(tipoArbolBB raiz);

	// Funciones a implementar por el alumno
	
		int insertar(tipoArbolBB *raiz, tipoClave clave);
		int insertarNodoClaveRepetida(tipoArbolBB *raiz, tipoClave k);
		int buscar(tipoClave clave,tipoArbolBB raiz, tipoNodo **nodo);
		int eliminar(tipoArbolBB *raiz, tipoClave clave);
	
