#include<iostream>
#include<string.h>
#include <sstream>

//#include "DateTests.h"
//#include "SetTests.h"
#include "SetOfInts3.h"
#include "Set.h"
#include "Hora.h"

using namespace std;

void ejercicio1Tema7()
{
	int elems, value;
	SetOfInts3 set;

	while (cin >> elems, elems != 0)
	{
		set = SetOfInts3();

		while (cin >> value, value != -1)
		{
			set.add(value);	
		}
		set.setSize(elems);
		cout << set << endl;
	}
}

void ejercicio2Tema7()
{
	char type;
	int k,value;
	string str;

	while (cin >> type, !cin.fail())
	{
		cin >> k;
		if (type == 'N')
		{
			Set<int> *setInt = new Set<int>();
			for (int i = 0; i < k; i++) //rellena hasta la longitud esperada del vector respuesta
			{
				cin >> value;
				if (setInt->contains(value))
					i--;
				else
					setInt->add(value);
			}

			while (cin >> value, value != -1) //Si se lee un nuevo valor maximo, elimina el elemento minimo, desplaza los elementos a la izquierda e inserta
			{
				if (value > setInt->getMin() && !setInt->contains(value))
				{
					setInt->removeMin();
					setInt->add(value);
				}
			}
			cout << (*setInt) << '\n';
			delete setInt;
		}
		else if (type == 'P')
		{
			Set<string> *setStr = new Set<string>();
			for (int j = 0; j < k; j++)
			{
				cin >> str;
				if (setStr->contains(str))
					j--;
				else
					setStr->add(str);
			}
			while (cin >> str, str != "FIN")
			{
				if (str > setStr->getMin() && !setStr->contains(str))
				{
					setStr->removeMin();
					setStr->add(str);
				}
			}
			cout << (*setStr) << '\n';
			delete setStr;
		}
	}
}

void ejercicio3Tema7()
{
	int cases, needs, h, m, s;
	string str;
	while (cin >> cases >> needs, cases != 0 || needs != 0)
	{
		//Hora *arrivals = new Hora[cases];
		getline(cin, str);
		stringstream ss(str);
		int n;
		int cont = 0;
		int i = 0;
		while (ss >> n)
		{
			if (ss.peek() == ':' || ss.peek() == ' ')
				ss.ignore();
			else
			{
				switch (cont % 2)
				{
				case 0:
					h = n;
					break;
				case 1:
					m = n;
					break;
				case 2:
					s = n;
					//arrivals[i] = new Hora(h, m, s);
					i++;
					break;
				}
				cont++;
			}
		}
		//delete arrivals;
	}
}

int main(){
	//testSmallSet();
	//testSetOfInts();
	//testGenericSet();
	//testDate1();
	//testDate2();
	//testDate3();
	//testDate4();
	//ejercicio1Tema7();
	//ejercicio2Tema7();
	//ejercicio3Tema7();
}

