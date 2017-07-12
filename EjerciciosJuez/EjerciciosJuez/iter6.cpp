#include<iostream>
#include<string>
using namespace std;
const int N = 1000;

string procesa(string str, int n)
{
	string response = "NO";
	int i = 1;

	//<= por < si quieres "aa" = NO
	while (i < n && str.at(i-1) <= str.at(i))
	{
		i++;
	}
	if (i == n) response = "SI";

	return response;
}

int main()
{
	string word;

	while (cin>>word, word.compare("XXX"))
	{
		cout << procesa(word, word.length()) << '\n';
	}
	return 0;
}