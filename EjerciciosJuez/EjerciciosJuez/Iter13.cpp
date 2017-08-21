#include<iostream>
using namespace std;

int main()
{
	int cases, nTemp;
	int act, ant, picos, valles;
	bool baja, sube;

	cin >> cases;

	while (cases--)
	{
		picos = valles = 0;
		baja = false, sube = false;
		cin >> nTemp;

			cin >> ant; //tomo el primer valor

			for (int i = 1; i < nTemp; i++)
			{
				cin >> act;

				if (act < ant) //bajando
				{
					if (sube)
					{
						sube = false;
						picos++;
					}
					if (!baja) baja = true;
				}
				else if (act > ant) // subiendo;
				{
					if (baja)
					{
						baja = false;
						valles++;
					}
					if (!sube) sube = true;
				}
				else //Expalanada
				{
					sube = baja = false;
				}

				ant = act;
			}
			cout << picos << " " << valles << '\n';
	}
}