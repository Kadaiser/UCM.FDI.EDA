#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include "Stack.h"

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

}

int main()
{
	ejercicio1Tema8();
	ejercicio2Tema8();
}