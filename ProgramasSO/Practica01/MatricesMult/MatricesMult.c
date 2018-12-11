#include <stdio.h>//Importas librerias.
#include <stdlib.h>
int main(int argc, char** args){
  int **p;	//Puntero representa una matriz
  int **q;	//Puntero representa una matriz
  int **r;	//Puntero representa matriz producto
  int af, ac, bf, bc, i, j, k; //Variables para definir las matrices y utilizar las en los ciclos for.
  printf("Numero de renglonesde la matriz  P-->");
  scanf("%d", &af);
  printf("Numero de columnas de la matriz  P-->");
  scanf("%d", &ac);
  printf("Numero de renglones de la matriz Q-->");
  scanf("%d", &bf);
  printf("Numero de columnas de la matriz  Q-->");
  scanf("%d", &bc);
//Verificacion de dimensiones de matrices para saber que es posible multiplicar dichas matrices.
  if(ac!=bf){
             printf("no es posible hacer la multiplicación\n");
             system("pause");
             return 0;
  }
  //Creamos las matrices con memoria dinamica.
  p = (int **) malloc(af * sizeof(int *));
  q = calloc(bf, sizeof(int));
  r = malloc(0);
  r = realloc(r,af * sizeof(int *));
  //Verificamos que tengan espacio suficiente.
  if(p==NULL)
  {
  printf("Insuficiente Espacio de Memoria"); exit(-1);
  }
  //Verificamos que tengan espacio suficiente.
  if(q==NULL)
  {
  printf("Insuficiente Espacio de Memoria"); exit(-1);
  }
  //Verificamos que tengan espacio suficiente.
  if(r==NULL)
  {
  printf("Insuficiente Espacio de Memoria"); exit(-1);
  }
  //Inicializas el apuntador como arreglo de arreglos con el valor que proporciono el usuario.
  for(i=0; i<af; i++)
  {
  p[i] = (int *)malloc(ac*sizeof (int));
  r[i] = (int *)malloc(bc*sizeof (int));
  if(p[i]==NULL)
  {
  printf("Insuficiente Espacio de Memoria"); exit(-1);
  }
  if(r[i]==NULL)
  {
  printf("Insuficiente Espacio de Memoria"); exit(-1);
  }
}
//Inicializas el apuntador como arreglo de arreglos con el valor que proporciono el usuario.
for(i=0; i<bf; i++)
{
q[i] = calloc(bc, sizeof(int));
if(q[i]==NULL)
{
printf("Insuficiente Espacio de Memoria"); exit(-1);
}
}
/*Rutina para cargar los valores*/
  for(i=0;i<af;i++){
      for(j=0;j<ac;j++){
          printf("Escribe el valor de la matriz P (%d, %d)-->",i+1, j+1);
          scanf ("%d",&p[i][j]);
      }
  }
  printf("\n\n");
  for(i=0;i<bf;i++){
      for(j=0;j<bc;j++){
          printf("Escribe el valor de la matriz Q (%d, %d)-->", i+1, j+1);
          scanf ("%d",&q[i][j]);
      }
  }
//For para calcular el producto de las matrices.
  for(i=0;i<af;i++){
      for(j=0;j<bc;j++){
          r[i][j]=0;
          for(k=0;k<ac;k++){
              r[i][j]=(r[i][j]+(p[i][k]*q[k][j]));
          }
      }
  }
/*Rutina para imprimir*/
  printf("\n\n\t\t\t Matriz P");
  printf("\n");
  for(i=0;i<af;i++){
      printf("\n\t\t");
      for(j=0;j<ac;j++){
          printf("  %6d  ", p[i][j]);
      }
  }
  //Imprimes los valores correspondientes.
  printf("\n\n\t\t\t Matriz Q");
  printf("\n");
  for(i=0;i<bf;i++){
      printf("\n\t\t");
      for(j=0;j<bc;j++){
          printf("  %6d  ", q[i][j]);
      }
  }
//Imprimes los valores correspondientes.
  printf("\n\n\t\t\t Matriz R");
  printf("\n");
  for(i=0;i<af;i++){
      printf("\n\t\t");
      for(j=0;j<bc;j++){
          printf("  %6d  ", r[i][j]);
      }
  }
  printf("\n");
  //Liberas memoria del apuntador p
  for (i=0; i<af; i++)
  free(p[i]) ;

//Liberas mamoria del apuntador q.
  for (i=0; i<bf; i++)
  free(q[i]) ;

  //Liberas memoria del apuntador r.
  for (i=0; i<af; i++)
  free(r[i]) ;
}
