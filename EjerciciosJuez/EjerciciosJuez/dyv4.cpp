#include<iostream>
using namespace std;
const int N = 100000;

typedef struct
{
	int menor;
	int mayor;
}par;


par divide(int *v, int ini, int fin)
{	
	par p;

	if ((ini + 1) == fin) //vector de dos elementos
	{

		if (v[ini] <= v[fin])//decidir mayor/menor
		{
			p.menor = v[ini];
			p.mayor = v[fin];
		}
		else
		{
			p.menor = v[fin];
			p.mayor = v[ini];
		}
	}
	else //dividir y resolver
	{
		par izq, der;
		int mitad = ((fin - ini) / 2) + ini;
		izq = divide(v, ini, mitad);
		der = divide(v, mitad + 1, fin);

		(izq.menor <= der.menor) ? p.menor = izq.menor : p.menor = der.menor;
		(izq.mayor <= der.mayor) ? p.mayor = der.mayor : p.mayor = izq.mayor;

	}
	return p;
}



int main()
{
	int primero, longitud, valor;
	int v[N] = { 0 };
	par izq, der;

	while (cin >> primero, primero != 0)
	{
		longitud = 0;
		v[longitud] = primero;
		while (cin >> valor, valor != 0)
		{
			longitud++;
			v[longitud] = valor;
		}

		izq = divide(v, 0, longitud / 2);
		der = divide(v, (longitud / 2) + 1, longitud);
			
		if (izq.menor <= der.menor && izq.mayor<=der.mayor)
			cout << "SI" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}