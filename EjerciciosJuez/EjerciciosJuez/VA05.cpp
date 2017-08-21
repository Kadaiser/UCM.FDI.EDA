#include<iostream>
using namespace std;

typedef struct 
{
	int time;
	int value;
} tSong;

void procesa(tSong* songs,bool* marcas, int side, int n, int &mejor, int acumulado, int sideA, int sideB ,int k)
{

	acumulado += songs[k].value;

	if ((sideA + songs[k].time) <= side) //Queda espacio en la caraA tras meter la cancion
	{
		if (k < n) //Quedan mas canciones diponibles?
		{
			procesa(songs, marcas, side, n, mejor, acumulado, sideA + songs[k].time, sideB, k + 1);
		}
		else
		{
			if (acumulado > mejor) mejor = acumulado;
		}
	}
	else
	{
		if ((sideB + songs[k].time) <= side) //Queda espacio en la caraA tras meter la cancion
		{
			if (k < n) //Quedan mas canciones diponibles?
			{
				procesa(songs, marcas, side, n, mejor, acumulado, sideA, sideB + songs[k].time, k + 1);
			}
			else
			{
				if (acumulado > mejor) mejor = acumulado;
			}
		}
	}
	acumulado -= songs[k].value;

}

int procesa(tSong* songs, bool* marcas, int side, int n)
{
	int mejor = 0;
	procesa(songs, marcas, side, n, mejor, 0, 0, 0, 0);
	return mejor;
}

int main()
{

	int casos, side;
	tSong *songs;
	bool* marcas;

	while (cin >> casos, casos > 0 && casos < 51)
	{
		songs = new tSong[casos];
		marcas = new bool[casos];

		cin >> side;
		for (int i = 0; i < casos; i++)
		{
			marcas = false;
			cin >> songs[i].time;
			cin >> songs[i].value;
		}
		cout << procesa(songs, marcas, side, casos) << '\n';
		delete[] songs;
		delete[] marcas;
	}
	return 0;
}