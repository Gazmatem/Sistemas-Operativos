//Importas librerias correspondientes.
#include<stdio.h>

//creas un metodo main
void main(){

    //Inicializas variables necesarias para hacer el algoritmo de calendarizacion correspondiente.
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Intoduzca numero de procesos:"); //Preguntas cuantos procesos desea.
    scanf("%d",&n); // Abres scanner para tomar el numero

    printf("\nIntroduzca el tiempo de rafaja:\n");

    //Este ciclo inicializa en un arreglo los procesos.
    for(i=0;i<n;i++){
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //Contiene el numero de procesos
    }

    //Ordena el tiempo de rafaja en orden acendiente usando selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //Espera para que primer proceso este en cero.

    //Calcula el tiempo de espera.
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;      //Es el tiempo promedio de espera
    total=0;

    printf("\nProceso\t    Tiempo de Rafaja    \tTiempo de espera\t Tiempo de vuelta");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //Calcula el tiempo de vuelta
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;     //Tiempo promedio de vuelta.
    printf("\n\nTiempo Promedio de espera=%f",avg_wt); //imprime tiempo promedio de espera.
    printf("\nTiempo promedio de vuelta=%f\n",avg_tat); // Imprime tiempo promedio de vuelta.
}
