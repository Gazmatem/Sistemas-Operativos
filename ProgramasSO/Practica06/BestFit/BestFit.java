// Algoritmo BestFit unidad de manejo de memoria.

class GFGBEST{
	//Este metodo sirve para manejar en bloques con algoritmo BestFit
	static void bestFit(int blockSize[], int m, int processSize[],int n){
		//Almacenas el id del bloque del bloque de localizacion a el proceso.
		int allocation[] = new int[n];

		//Inicialmente no hay bloques asignados a algun proceso.
		for (int i = 0; i < allocation.length; i++)
			allocation[i] = -1;

	//Tomas cada proceso y encuentras bloque disponible de acuerdo a su tamano y asignacion.
		for (int i=0; i<n; i++)
		{
			// Encuentra el mejor candidato para proceso actual
			int bestIdx = -1;
			for (int j=0; j<m; j++)
			{
				if (blockSize[j] >= processSize[i])
				{
					if (bestIdx == -1)
						bestIdx = j;
					else if (blockSize[bestIdx] > blockSize[j])
						bestIdx = j;
				}
			}

			//Si pudiste encontrar un bloque para proceso actual entonces.
			if (bestIdx != -1)
			{
				//Colocas bloque j en posicion en p[i] arreglo de procesos.
				allocation[i] = bestIdx;

				// Reduces memoria disponible en este bloque.
				blockSize[bestIdx] -= processSize[i];
			}
		}

		System.out.println("\nNumero de Proceso.\tTamano del Proceso\tNumero de bloque.");
		for (int i = 0; i < n; i++)
		{
			System.out.print(" " + (i+1) + "\t\t" + processSize[i] + "\t\t");
			if (allocation[i] != -1)
				System.out.print(allocation[i] + 1);
			else
				System.out.print("No Colocado");
			System.out.println();
		}
	}

	// Metodo main.
	public static void main(String[] args)
	{
		int blockSize[] = {100, 500, 200, 300, 600};
		int processSize[] = {212, 417, 112, 426};
		int m = blockSize.length;
		int n = processSize.length;
		bestFit(blockSize, m, processSize, n);
	}
}
