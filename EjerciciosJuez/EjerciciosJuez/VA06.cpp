#include<iostream>
using namespace std;


void procesa(int** T, int n, int m, int price, int &bestPrice, int* M, int k)
{
	for (int i = 0; i < m; i++)
	{
		if (M[i] < 3)//Puedo coger un producto de este supermercado?
		{
			price += T[i][k];
			M[i]++;

			if (k== n -1) //es Solucion?
			{
				if (price < bestPrice)//es mejor solucion?
				{
					bestPrice = price;
				}
			}
			else //no es solucion
			{
				if (price < bestPrice) //aun no he superado mi mejor presupuesto? (descarte para mas eficiencia)
					procesa(T, n, m, price, bestPrice, M, k + 1);
			}
			M[i]--;
			price -= T[i][k];
		}
	}
}

int procesa(int** table, int products, int markets)
{
	int price = 0;
	int bestPrice = (markets*products) * 5000;
	int* perMarket = new int[markets];

	for (int i = 0; i < markets; i++)
	{
		perMarket[i] = 0;
	}

	procesa(table, products, markets, price, bestPrice, perMarket, 0);


	return bestPrice;
}

int main()
{
	int cases, markets, products;
	int** table;

	cin >> cases;

	while (cases--)
	{
		cin >> markets >> products;

		table = new int*[markets];
		for (int i = 0; i < markets; i++)
		{
			table[i] = new int[products];
			for (int j = 0; j < products; j++)
			{
				cin >> table[i][j];
			}
		}

		cout << procesa(table, products, markets) << '\n';

		for (int o = 0; o < markets; o++)
		{
			delete[] table[o];
		}
		delete[] table;

	}
	return 0;
}