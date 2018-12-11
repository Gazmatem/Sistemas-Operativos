// JImplementacion del algoritmo FirstFit


class GFG{
	// Metodo para manejo de memoria colocando bloques a procesos.

	static void firstFit(int blockSize[], int m,
						int processSize[], int n)
	{
		//Almacenas el id del bloque colocando a un proceso.
		int allocation[] = new int[n];

		//Inicialmente los bloques no estan asignados a ningun proceso.
		for (int i = 0; i < allocation.length; i++)
			allocation[i] = -1;

		//Tomas cada proceso y encuentras bloques disponibles de acuerdo al tamano y se lo asignas.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (blockSize[j] >= processSize[i])
				{
					//Colocas bloque en j a  p[i] arreglo de procesos
					allocation[i] = j;

					//Reduces memoria disponible en el bloque.
					blockSize[j] -= processSize[i];

					break;
				}
			}
		}

		System.out.println("\nNumero de Proceso.\tTamano de proceso\tNumero de Bloque.");
		for (int i = 0; i < n; i++)
		{
			System.out.print(" " + (i+1) + "\t\t" +
							processSize[i] + "\t\t");
			if (allocation[i] != -1)
				System.out.print(allocation[i] + 1);
			else
				System.out.print("No colocado");
			System.out.println();
		}
	}

	// Metodo main
	public static void main(String[] args)
	{
		int blockSize[] = {100, 500, 200, 300, 600};
		int processSize[] = {212, 417, 112, 426};
		int m = blockSize.length;
		int n = processSize.length;

		firstFit(blockSize, m, processSize, n);
	}
}
