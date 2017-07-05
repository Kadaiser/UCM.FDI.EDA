#include<iostream>

using namespace std;

void procesar(const int v[], int elem)
{
	int max = v[0], veces = 0;

	for (int i = 0; i < elem; i++)
	{
		if (max < v[i])
		{
			max = v[i];
			veces = 0;
		}
		if (max == v[i])
		{
			veces++;
		}
	}
	cout << max << " " << veces << endl;
}

int main()
{
	int casos, elem;

	cin >> casos;
	while (casos > 0)
	{
		cin >> elem;
		if (elem > 0 && elem < 20001)
		{
			int *v = new int[elem];
			for (int i = 0; i < elem; i++)
			{
				cin >> v[i];
			}
			procesar(v, elem);
			delete[] v;
		}
		casos--;
	}
	return 0;
}