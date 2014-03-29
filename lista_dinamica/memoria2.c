int extraccion(tsNODO **lista){
 int num;
 tsNODO *nodo;
 if(*lista){
  nodo = *lista;
  *lista = (*lista)->siguiente;
  num = nodo->numero;
  free(nodo);
 }
 return num;
}

entero = extraccion(&Lista);
