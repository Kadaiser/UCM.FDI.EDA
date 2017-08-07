#include<iostream>

using namespace std;

void procesa(int v[], int ini, int fin, int x,bool &found)
{

	if (fin - ini > 1) //Puedo partir?
	{
		int mitad = (fin - ini) / 2;
		procesa(v,ini,ini+mitad-1,x, found);
		procesa(v,ini + mitad,fin, x, found);
	}
	else if(fin - ini == 0) //caso atomico
	{
		if (v[ini] == x + ini)
		{
			cout << v[ini] << '\n';;
			found = true;
		}
	}
	else //caso pareja
	{
		if (v[ini] == x + ini) {
			cout << v[ini] << '\n';;
			found = true;
		}
		else if (v[fin] == x + fin) {
			cout << v[fin] << '\n';
			found = true;
		}
	}

}

int main()
{
	int casos, longitud, cantado;
	bool found;
	cin >> casos;
	while (casos--)
	{
		cin >> longitud >> cantado;
		if (longitud > 0)
		{
			found = false;
			int *v = new int[longitud];
			for (int i = 0; i < longitud; i++)
			{
				cin >> v[i];
			}
			procesa(v, 0, longitud - 1, cantado, found);
			if (!found) cout << "NO" << '\n';
			delete[] v;

		}

	}

	return 0;
}