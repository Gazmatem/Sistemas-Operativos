// Importas librerias necesarias.
#include<stdio.h>

int main(){

    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Introduce el numero de procesos:");//Pides a usuario por numero de procesos.
    scanf("%d",&n);//inicializas el numero de procesos.

    printf("\nIntroduce el tiempo de rafaja\n");
    //Este for genera un arreglo con la informacion de dichos procesos.
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;    //Esperas tiempo para que el proceso sea 0

    //Calculas tiempo de espera.
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("\nProceso\t\tTiempo de Rafaja\tTiempo de espeara\tTiempo de giro.");

    //Calculas tiempo de giro.
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]); //imprimes los valores calculados
    }

    avwt/=i;
    avtat/=i;
    printf("\n\nTiempo promedio de espera:%d",avwt); //imprimes los valores calculados
    printf("\nTiempo promedio de Giro.:%d",avtat); //imprimes los valores calculados

    return 0;
}
