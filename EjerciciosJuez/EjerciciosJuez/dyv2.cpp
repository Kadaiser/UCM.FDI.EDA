#include<iostream>
using namespace std;

const int M = 31543;

int potencia(int x, int n)
{
	x = x % M;

	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return (potencia((x * x), n / 2) % M);
	else
		return (x * potencia(x, n - 1) % M);
}

int main()
{
	int x, n;

	while (cin >> x >> n, x>0 || n>0)
	{
		cout << potencia(x, n) << '\n';
	}
	return 0;
}