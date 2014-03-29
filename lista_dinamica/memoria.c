void insercion(tsNODO **lista, int num, int num2){
 tsNODO *nodo1, *nodo2;
 nodo1 = (tsNODO*)malloc(sizeof(tsNODO));
 nodo2 = (struct Nodo*)malloc(sizeof(struct Nodo));
 nodo1->numero = num1; nodo2->numero = num2;
 nodo1->siguiente = NULL; nodo2->siguiente = NULL;
 if(*lista == NULL){
  *lista = nodo1; (*lista)->siguiente = nodo2;
 }else{
  (*lista)->siguiente = nodo1;
  nodo1->siguiente = nodo2;
  }
}
insercion(&Lista, 3, 7);
