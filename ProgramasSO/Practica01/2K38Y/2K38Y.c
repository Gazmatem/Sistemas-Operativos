#include <stdio.h>//Importas librerias
#include <limits.h>//Importas librerias
#include <time.h>//Importas librerias

int main(void) {
  time_t x;//Inicializas variable de tipo tiempo.
  x = (time_t)(INT_MAX);//La inicializas con el maximo numero de segundos.
  printf("%s\n", ctime(&x));// Imprimes el valor
}
