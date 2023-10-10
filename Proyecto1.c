#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int numero;
    struct nodo *siguiente;
};

struct nodo *superior = NULL;

void agregar(int numero)
{
    printf("Agregando %d\n", numero);
    // El que se agregará; reservamos memoria
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
    // Le ponemos el dato
    nuevoNodo->numero = numero;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void imprimir(void)
{
    printf("Imprimiendo...\n");
    struct nodo *temporal = superior;
    while (temporal != NULL)
    {
        printf("%d\n", temporal->numero);
        temporal = temporal->siguiente;
    }
}

void eliminarUltimo(void)
{
    printf("Eliminando el ultimo\n");
    if (superior != NULL)
    {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo *temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;

        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
}

int tamanio(void) {
  int contador = 0;
  if (superior == NULL)
    return contador;
  struct nodo *temporal = superior;
  while (temporal != NULL) {
    contador++;
    temporal = temporal->siguiente;
  }
  return contador;
}

int ultimo() {
  if (superior == NULL)
    return -1;
  return superior->numero;
}

bool vacia(void) { return superior == NULL; }

int main()
{
    int eleccion;
	int numero;

	printf("Probando...");

	while(eleccion != -1)
    {
		printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir pila\n4.- Imprimir tamanio\n5.- Comprobar si está vacia\n6.- Mostrar ultimo elemento\n-1.- Salir\n\n\tElige: ");
		scanf("%d", &eleccion);
		switch(eleccion)
		{
			case 1:
				printf("Ingresa el numero que agregaremos:\n");
				scanf("%d", &numero);
				agregar(numero);
			break;
			case 2:
				eliminarUltimo();
			break;
			case 3:
				imprimir();
			break;
			case 4:
				printf("La pila mide %d\n", tamanio());
			break;
			case 5:
				if(vacia()){
					printf("La pila esta vacia\n");
				}else{
					printf("La pila NO esta vacia\n");
				}
			break;
			case 6:
				printf("El ultimo elemento es: %d\n", ultimo());
			break;
		}
	}


    return 0;
}
