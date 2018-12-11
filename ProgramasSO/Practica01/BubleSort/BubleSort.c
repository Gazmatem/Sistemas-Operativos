/* Bubble sort code */
#include <stdio.h> //Importas librerias.
int main()
{
  int array[100], n, c, d, swap; //Generas los arreglos y variables necesarias.
  printf("Introduce la cantidad de elementos de la lista:\n"); //Imprimes instrucciones para usuario.
  scanf("%d", &n);
  printf("Introduce %d Elementos de la lista:\n", n);

  for (c = 0; c < n; c++) //Recibes los datos del usuario.
    scanf("%d", &array[c]);

  for (c = 0 ; c < n - 1; c++) //con dos for anidados haces los swaps para ordenar con Buble sort.
{
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1])
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
        printf("Hola");//Imprimes el numero en cada celda
      }
    }
    printf("%d\n", array[c]);//Imprimes el numero en cada celda
    printf("%p\n", &array[c]);//Imprime la localidad de memoria
  }
  printf("Lista ordenada por Buble Sort:\n"); //Despues de Ordenar imprimes valores y valores en memoria.
  for (c = 0; c < n; c++){
    printf("%d\n", array[c]);
    printf("%p\n", &array[c]);
  }
  return 0;
}
