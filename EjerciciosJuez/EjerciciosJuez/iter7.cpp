#include<iostream>
using namespace std;

int procesa(long n,long k,long ayer, long antesdeayer)
{
	int dias = 1;
	int hoy = 2 * antesdeayer + ayer;

	if (k < n)
	{
		k += hoy;
		dias += procesa(n, k, hoy, ayer);
	}
	return dias;
}

int main()
{
	int casos;
	long valor;
	cin >> casos;
	for (int i = 0; i < casos; i++)
	{
		cin >> valor;
		if (valor == 0)
		{
			cout << "0" << '\n';
		}
		else
		{
			cout << procesa(valor, 1, 1, 0) << '\n';
		}
	}
	return 0;
}