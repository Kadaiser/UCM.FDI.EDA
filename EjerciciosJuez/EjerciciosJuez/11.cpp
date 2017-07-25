#include<iostream>

using namespace std;

void paresImpares(const int v[], const int n, bool &existe, int &p)
{

}

int main()
{
	int casos, n, p;
	bool existe;
	cin >> casos;
	while (casos--)
	{
		cin >> n;
		if (n >= 0 && n <= 10000)
		{
			int *v = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}
			paresImpares(v, n, existe, p);
			if (existe) cout << "Si " << p << '\n';
			else cout << "No";

			delete v;
		}
	}

	return 0;
}