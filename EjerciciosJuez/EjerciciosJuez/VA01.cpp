#include<iostream>
#include<string>
using namespace std;


bool solution(int c, int v, int usedC, int usedV)
{
	return c == usedC && v == usedV;
}

void procesa(int c, int v, int usedC, int usedV, string parcial, string &response)
{
	usedC++;
	if (usedC <= c) //Si aun me quedan elementos diponibles de este tipo
	{
		if (solution(c, v, usedC, usedV)) //profundizo la llamada con el parcial acumulado
		{
			if (response == "") response = parcial + "C";
			else response += " " + parcial + "C";
		}
		else 
		{
			procesa(c, v, usedC, usedV, parcial + "C", response);
		}
	}
	usedC--;//Si no era solucion y no profundizo mas sobre k
	usedV++;

	if (usedV <= v)
	{
		if (solution(c, v, usedC, usedV))
		{
			if (response == "") response = parcial + "V";
			else response += " " + parcial + "V";
		}
		else
		{
			procesa(c, v, usedC, usedV, parcial + "V", response); //profundizo la llamada con el parcial acumulado
		}
	}
	usedV--;//si no erasolucion ni podia profuncidzar mas sobre k, se desapila la funcion
}

string procesa(int c, int v, int k)
{
	string result = "";
	procesa(c, v, 0, 0, "", result);
	return result;

}

int main()
{
	int casos, c, v;
	cin >> casos;

	while (casos--)
	{
		cin >> c >> v;

		if (c + v < 16)
		{
			cout << procesa(c, v, 0) << '\n';
		}
	}
	return 0;
}