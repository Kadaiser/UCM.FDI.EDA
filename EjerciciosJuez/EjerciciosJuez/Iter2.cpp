#include<iostream>
using namespace std;

/*
	Complejidad del procedimiento O(n);
*/
void procesa(const int v[], int elem)
{
	int cont = 0;
	for (int i = 0; i < elem; i++)
	{
		if (v[i] % 2 == 0)
			cont++;
	}
	cout << cont << endl;
}

int main()
{
	int casos, admin, boleto;

	cin >> casos;
	while (casos > 0)
	{
		cin >> admin;
		if (admin > 0 && admin < 10001)
		{
			int *v = new int[admin];
			for (int i = 0; i < admin; i++)
			{
				cin >> boleto;
				if (boleto >= 0 && boleto < 100000)
				{
					v[i] = boleto;
				}
				else 
				{
					v[i] = -1;
				}
			}
			procesa(v, admin);
			delete v;
		}
		casos--;
	}

	return 0;
}