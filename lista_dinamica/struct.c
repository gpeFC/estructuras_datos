struct Nodo{	// Nodo tipo struct.
	int numero;
	struct Nodo* siguiente;
};

typedef struct Nodo{	// Nodo de tipo tsNODO.
	int numero;
	struct Nodo *siguiente;
}tsNODO;

struct Nodo* ptr_nodo;	// Tipo struct Nodo.
tsNODO *ptrNodo;	// Tipo tsNODO.
