#include<iostream>
#include<string>

using namespace std;

bool move(int iniC, int iniR, int endC, int endR, int n, int max, bool** marcas, int **m)
{
	if ((endC >= 0 && endC < n) && (endR >= 0 && endR < n))
		return !marcas[endR][endC] && (abs(m[iniR][iniC] - m[endR][endC]) <= max);
	else
		return false;
}

void procesa(int** m, bool** marcas, int iniC, int iniR, int endC, int endR, int max, int acumulado, int& mejor, int dim)
{
	marcas[iniR][iniC] = true;
	if (iniR == endR && iniC == endC)  //Destino?
	{
		if (acumulado < mejor) mejor = acumulado; //mejor camino?
	}
	if (move(iniC, iniR, iniC, iniR - 1, dim, max, marcas, m)) //UP?
		procesa(m, marcas, iniC, iniR - 1, endC, endR, max, acumulado + 1, mejor, dim);
	if (move(iniC, iniR, iniC, iniR + 1, dim, max, marcas, m)) //DOWN?
		procesa(m, marcas, iniC, iniR + 1, endC, endR, max, acumulado + 1, mejor, dim);
	if (move(iniC, iniR, iniC - 1, iniR, dim, max, marcas, m)) //LEFT?
		procesa(m, marcas, iniC - 1, iniR, endC, endR, max, acumulado + 1, mejor, dim);
	if (move(iniC, iniR, iniC + 1, iniR, dim, max, marcas, m)) //RIGHT?
		procesa(m, marcas, iniC + 1, iniR, endC, endR, max, acumulado + 1, mejor, dim);

	marcas[iniR][iniC] = false; //Desmarco para descartar caminos
}

int procesa(int** m, bool** marcas, int iniC, int iniR, int endC, int endR, int max, int dim)
{
	int mejor = (dim * dim) + 1;

	procesa(m, marcas, iniC, iniR, endC, endR, max, 1, mejor, dim);

	return mejor;
}

int main()
{
	int n, h_max, iniRow, iniCol, endRow, endCol, response;
	

	while (cin >> n >> h_max >> iniRow >> iniCol >> endRow >> endCol)
	{
		int **m = new int*[n];
		bool **marcas = new bool*[n];

		for (int i = 0; i < n; i++)
		{
			m[i] = new int[n];
			marcas[i] = new bool[n];
			for (int j = 0; j < n; j++)
			{
				cin >> m[i][j];
				marcas[i][j] = false;
			}
		}
		response = procesa(m, marcas, iniCol, iniRow, endCol, endRow, h_max, n);
		if ( response > (n*n))
			cout << "NO" << '\n';
		else
		cout << response << '\n';

		delete[] m;
		delete[] marcas;
	}

	return 0;
}