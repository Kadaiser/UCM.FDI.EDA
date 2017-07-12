#include<iostream>
using namespace std;
const int N = 10000;

void muestra(int v[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int *sumaVector(int v[], int n)
{
	int *v2 = new int[n];
	v2[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		v2[i] = v[i] + v2[i - 1];
	}
	return v2;
}

int main()
{
	bool exit = false;
	int next, i;

	do
	{
		cin >> next;
		if (next == 0)
		{
			exit = true;
		}
		else
		{
			int *v = new int[N];
			i = 0;
			do
			{
				v[i] = next;
				i++;
			} while (cin >> next, next > 0);

			muestra(sumaVector(v, i), i);
			delete v;
		}
	} while (!exit);

	return 0;
}