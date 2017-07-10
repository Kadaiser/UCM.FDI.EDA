#include<iostream>

using namespace std;

int procesa(int v[], int n)
{
	int colotas = 0;
	int pos = n - 1;
	int actual = v[pos];

	while (pos > 0) {
		if (v[pos - 1] < actual)
		{
			actual = v[pos - 1];
		}
		else
		{
			colotas++;
		}
		pos--;
	}
	return colotas;
}

int main()
{
	int casos, n;

	cin >> casos;
	if (casos > 100000)
	{
		while (casos > 0)
		{
			cin >> n;
			int *v = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			cout << procesa(v, n) << endl;
			delete v;
			casos--;
		}
	}
	return 0;
}