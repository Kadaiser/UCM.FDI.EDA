#include<iostream>
using namespace std;

bool par(int n)
{
	if (n == 0)
	{
		return true;
	}
	return n % 2 == 0;
}

/*
P=	 { casos > 0 ^ 4ALL n >= 0 && n <= 100000}
	func segento(int casos, int[] v, int n) return str;
Q=	 str= if(n < 2 || !segmento(v,n) ? ) "Vacio" : "p -> [u, u + p-1]"

	segmento(v,n) return p,u
	p,u = 4 ALL u,w : 0 <= u < w < n: v[u] < v[w] ^ par(v[u]) ^ par(v[w]) ^ max(w - u) = p = max(w - u) 

*/

int main()
{
	int casos, n, l, longitud, posI, posI2 , valor;
	bool primero,ruptura;
	cin >> casos;
	for (int i = 0; i < casos; i++)
	{
		cin >> n;
		if (n < 2)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> valor;
			}
			cout << "Vacio" << '\n';
		}

		else if (n > 1 && n <= 100000)
		{
			posI = posI2 = l = longitud = 0;
			primero = false;
			for (int j = 0; j < n; j++)
			{
				cin >> valor;
				if (par(valor))
				{
					if (!primero)
					{
						posI = j;
						primero = true;
					}
					l++;
				}
				else
				{
					if (l >= longitud)
					{
						longitud = l;
						posI2 = posI;
					}
					l = 0;
					primero = false;
				}
				if (l >= longitud && j == n-1)
				{
					longitud = l;
					posI2 = posI;
				}

			}
			if (posI >= posI2 && longitud <= l)
				posI2 = posI;

			if (longitud <= 1)
				cout << "Vacio" << '\n';
			else if(longitud == n || longitud == 2)
				cout << longitud << " -> [" << posI2 << "," << posI2 + longitud - 1 << ")" << '\n';
			else
				cout << longitud << " -> [" << posI2 << "," << posI2 + longitud << ")" << '\n';
		}
	}
	return 0;
}
