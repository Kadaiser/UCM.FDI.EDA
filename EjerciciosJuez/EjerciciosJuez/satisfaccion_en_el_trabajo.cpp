#include<iostream>
using namespace std;

void procesa(int** S, int** B, bool* marcaS, bool* marcaB, int works, int& mejorB, int& maxS, int result, int k)
{
	marcaS[k] = true;

	


	marcaS[k] = false;


}


int procesa(int** S, int** B, bool* marcaS, bool* marcaB, int works)
{
	int mejorB = 0, maxS = 0, result = 0;

	procesa(S, B, marcaS, marcaB, works, mejorB, maxS, result,0);

	return result;
}

int main()
{

	int cases, works, result;

	int **S;
	int **B;

	cin >> cases;

	while (cases--)
	{
		cin >> works;
		S = new int*[works];
		B = new int*[works];
		bool *marcaS = new bool[works];
		bool *marcaB = new bool[works];

		for (int i = 0; i < works; i++)
		{
			S[i] = new int[works];
			marcaS[i] = false;
			for (int j = 0; j < works; j++)
			{
				cin >> S[i][j];
			}
		}
		for (int i = 0; i < works; i++)
		{
			B[i] = new int[works];
			marcaB[i] = false;
			for (int j = 0; j < works; j++)
			{
				cin >> B[i][j];
			}
		}
		result = procesa(S, B, marcaS, marcaB, works);

		if (result > 0)
			cout << result << '\n';
		else
			cout << "Sin solucion factible";

		delete[] S;
		delete[] B;
		delete[] marcaS;
		delete[] marcaB;
	}

	return 0;
}