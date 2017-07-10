#include<iostream>

using namespace std;

int log(int b, int n)
{
	int i = 0;
	while (!(pow(b,i) <= n && n < pow(b,i+1)))
	{
		i++;
	}
	return i;
}

int main() 
{
	int casos, b, n;

	cin >> casos;
	while (casos > 0)
	{
		cin >> b >> n;
		if (b > 1 && n > 0)
		{
			cout << log(b, n) << endl;
		}
		casos--;
	}

	
	return 0;
}