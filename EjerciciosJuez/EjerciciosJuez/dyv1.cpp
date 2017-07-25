#include <stdio.h>
#include "iostream"
#include <cstdlib>

using namespace std;

char Presos(char* v, int n, char inicial);
char Presos(char* v, int i, int j, char inicial);


int main() {
	int casos, n;
	char pri, ult;
	cin >> casos;

	while (casos--)
	{
		cin >> pri >> ult;
		n = ult - pri;

		char *v = new char[n];
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << Presos(v, n, pri) << endl;
		delete[] v;
	}
}

char Presos(char* v, int n, char pri) {
	if (n == 1) {
		if (v[0] != pri)
			return pri;
		else
			return pri + 1;
	}
	return Presos(v, 0, n - 1, pri);
}

char Presos(char* v, int i, int j, char pri) {
	int mitad = (j + i) / 2;

	if (i == j)
	{
		if (v[i] == pri + i)
			return pri + i + 1;
		else
			return pri + i;
	}
	else if (v[mitad] == pri + mitad) {
		return Presos(v, mitad + 1, j, pri);
	}
	else {
		return Presos(v, i, mitad, pri);
	}
}