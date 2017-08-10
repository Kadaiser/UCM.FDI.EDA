#include <stdio.h>
#include "iostream"

using namespace std;


void procesa(int** m, int n, int k, int acumulado, int &mejor, bool* marca)
{
	for (int i = 0; i < n; i++)
	{
		acumulado += m[k][i];//tomo el valor
		if (!marca[i]) 
		{
			if (k == n - 1)//es solucion?
			{
				if (acumulado < mejor) //es MEJOR solucion que la actual?
					mejor = acumulado;
			}
			else
			{
				marca[i] = true; //marco para que niveles mas profundos no usen ese valor
				procesa(m, n, k + 1, acumulado, mejor, marca);
				marca[i] = false;//Al regresar, estoy probando nuevas conbinaciones, desmarco
			}

		}
		acumulado -= m[k][i];//retiro el valor a la vuelta para probar nuevas combianciones
	}
}

int procesa(int **m, int casos)
{
	int mejor = 0;
	bool *marca = new bool[casos];

	for (int i = 0; i < casos; i++)
	{
		marca[i] = false;
		m[i] = new int[casos];
		for (int j = 0; j < casos; j++)
		{
			cin >> m[i][j];
			mejor += m[i][j];
		}
	}
	procesa(m,casos,0,0,mejor, marca);

	 return mejor;
}

int main()
{
	int casos;

	while (cin >> casos, casos > 0)
	{
		if (casos < 21)
		{
			int **m = new int*[casos];
			cout << procesa(m, casos) << '\n';
			delete[] m;
		
		}
	}
}