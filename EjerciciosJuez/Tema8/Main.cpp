#include<iostream>
#include<string>
#include<sstream>
#include "Stack.h"
#include "Queue.h"
#include "List.h"

using namespace std;


bool isAperture(char c)
{
	return c == '[' || c == '{' || c == '(' || c == '<';
}

bool isClose(char c)
{
	return c == ']' || c == '}' || c == ')' || c == '>';
}

void ejercicio1Tema8()
{
	char aux, c;
	string str;
	bool result;
	while (getline(cin,str), str != ".")
	{
		Stack<char> *pila = new Stack<char>();
		result = true;
		
		for (size_t i = 0; i < str.length() && result; i++)
		{
			c = str[i];
			if (isAperture(c))
				pila->push(c);

			else if (isClose(c))
			{
				if (!pila->empty())
				{
					aux = pila->top();
					if (aux == '(')  //ASCII char '(' + 1 == ')' 
					{
						if (aux + 1 != c)
							result = false;
					}
					else
					{
						if (aux + 2 != c) //ASCII char '<,{,[' + 1 == '>,],}'
							result = false; 
					}
					pila->pop();
				}
				else {
					result = false;
				}
			}
		}
		if (result && pila->empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		delete pila;
	}
}

void ejercicio2Tema8()
{
	int cases, value, n;
	cin >> cases;
	while (cases--)
	{
		Queue<int> *cola = new Queue<int>();
		while (cin >> value, value != -1)
		{
			cola->push_back(value);
		}
		cin >> n;
		cout << (*cola) << '\n';
		cola->inversePositons(n);
		cout << (*cola) << '\n';
		delete cola;
	}
}

void ejercicio3Tema8()
{
	int cases, value, n;
	cin >> cases;
	while (cases--, cases > 0)
	{
		Queue<int> *cola = new Queue<int>();
		while (cin >> value, value != -1)
		{
			cola->push_back(value);
		}
		cin >> n; //elegimos pringado

		Queue<int> *buddies = new Queue<int>();
		while (cin >> value, value != -1)
		{
			buddies->push_back(value);
		}
		cout << (*cola) << '\n';
		cola->jumpTheQueue(n, *buddies);
		cout << (*cola) << '\n';
		delete cola;
		//delete buddies; //por ceporro no funciona
	}
}

void ejercicio4Tema8()
{
	int cases, n, value;
	cin >> cases;
	while (cases--)
	{
		List<int> *list = new List<int>;
		while (cin >> value, value != -1)
		{
			list->push_back(value);
		}
		cin >> n;
		cout << (*list);
		list->eraseDupicatesOf(n);
		cout << (*list);
		delete list;
	}

}

void ejercicio5Tema8()
{
	int totalValue;
	string num,c;
	while (getline(cin, num), num != "-1")
	{
		Stack<string> *lexicografic = new Stack<string>();
		totalValue = 0;

		for (size_t i = 0; i < num.length(); i++)
		{
			c = num[i];
			totalValue += stoi( c );
			lexicografic->push(c);
			if (i < num.length() - 1)
				lexicografic->push(" + ");
		}
		lexicografic->push(" = ");
		lexicografic->push(to_string(totalValue));
		cout << (*lexicografic) << '\n';
		delete lexicografic;
	}
}

void ejercicio6Tema8()
{
	int value;
	while (cin >> value, !cin.fail())
	{
		if (value)
		{
			Queue<int> *q = new Queue<int>();
			q->push_back(value);
			while (cin >> value, value != 0)
			{
				q->push_back(value);
			}
			q->duplicateElems();
			cout << (*q);
			delete q;
		}
		cout << "" << '\n';
	}
}

int main()
{
	//ejercicio1Tema8();
	//ejercicio2Tema8();
	//ejercicio3Tema8();
	//ejercicio4Tema8();
	//ejercicio5Tema8();
	ejercicio6Tema8();
	return 0;
}