#include<iostream>
#include<string>

using namespace std;
const int N = 5;


bool procesa(int v[], int valor, int k, int parcial)
{
	if (k == N)
	{
		if (valor == parcial) return true;
		else return false;
	}
	else 
	{
		if (procesa(v, valor, k + 1, parcial + v[k]))
			return true;
		if (procesa(v, valor, k + 1, parcial - v[k]))
			return true;
		if (procesa(v, valor, k + 1, parcial * v[k]))
			return true;
		if (v[k] !=0 && parcial % v[k] == 0) //solo divisiones validas y de resto entero
		{
			if (procesa(v, valor, k + 1, parcial / v[k]))
				return true;
		}
		return false;
	}

}

string procesa(int v[], int valor)
{

	if (procesa(v, valor, 1, v[0]))
	{
		return "SI";
	}
	return "NO";
}

int main()
{
	int valor;
	int v[N];

	while (cin >> valor)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		cout << procesa(v, valor) << '\n'; 
	}

	return 0;
}