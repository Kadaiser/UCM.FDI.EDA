#include<iostream>

using namespace std;

const int N = 10000;

void paresImpares(int v[], int n, bool &existe, int &p)
{
	bool change = false;
	int cont = 0;

	if (v[cont] % 2 == 0) //si primer elemento es par
	{
		cont++;
		while (!change && cont < n)
		{
			if (v[cont] % 2 != 0)
			{
				change = true;
				p = cont;
			}
			cont++;
		}
		while (change && cont < n)
		{
			if (v[cont] % 2 != 0)
				cont++;
			else
				change = false;
		}
		if (change)
			existe = true;
		else
			existe = false;

	}
	else
		existe = false;
}

int main()
{
	int casos, n, p;
	int v[N];
	bool existe;
	cin >> casos;
	while (casos--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		paresImpares(v, n, existe, p);
		if (existe)
			cout << "Si " << p << '\n';
		else
			cout << "No" << '\n';
	}
}