/*
 n es mayor que 0 y menor que 10000
 p vale entre 0 y n-1

 se retorna un boleano tal que es cierto si para una posicion
 i-esima del vector, todos los elementos a la izquierda desde esa 
 posicion i-esima son menores que todos los elementos a la derecha
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int casos, n, p, value, max;
	bool pivote;
	string response;

	cin >> casos;
	while (casos > 0)
	{
		//restuarar variables de control por vuelta
		response = "SI";
		pivote = false;
		max = 0;

		cin >> n >> p;

		for(int i = 0; i < n; i++)
		{
			cin >> value;
			if (i > p) pivote = true; //ya no actualizo el maximo

			if (!pivote)
			{
				if (value > max) max = value;//actualizar maximo hasta encontrar pivote
			}
			else
			{
				if (value <= max) response = "NO";
			}

		}
		cout << response << '\n';
		casos--;
	}
	return 0;
}
