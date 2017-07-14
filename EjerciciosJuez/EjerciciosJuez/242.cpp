/*
Enunciado
Es conocida la afici�n existente entre los universitarios espa�oles al mus, un juego de cartas para cuatro personas con m�s de 200 a�os
de historia que tambi�n es muy jugado en algunos pa�ses de Hispanoam�rica e incluso en algunas regiones del sur de Francia.
Cuando esos espa�oles consiguen una beca erasmus para estudiar durante unos meses en otro pa�s de Europa, es f�cil entender,
pues, que no falte una baraja de cartas entre su equipaje, por lo que pueda ocurrir. En su af�n de evangelizaci�n muchos de
estos estudiantes de erasmus intentan que el juego se extienda, y se empe�an en explicar las reglas a sus compa�eros de otros pa�ses.
Como a buen seguro sabr�s, al mus se juega por parejas, de forma que una pareja de jugadores se enfrenta a otra. Desgraciadamente,
a la hora de hacer esas parejas la mayor�a de las veces los espa�oles "se buscan" entre s�, de forma que las partidas terminan
siendo competiciones entre pa�ses (juegan dos espa�oles contra dos italianos, por ejemplo).
En esta ocasi�n, sin embargo, un grupo de estudiantes de erasmus se ha propuesto formar parejas heterog�neas, por lo que no
van a aceptar parejas cuyos dos componentes sean de la misma nacionalidad. A la vista de cu�ntos estudiantes hay de cada pa�s,
�cu�ntas parejas distintas pueden formarse?

Entrada
La entrada estar� compuesta por varios casos de prueba terminados con una l�nea con un 0.
Cada caso de prueba tendr� dos l�neas. En la primera aparecer� un �nico entero que indica el n�mero de pa�ses totales representados
(un n�mero entre 1 y 100.000). La segunda l�nea contendr� un n�mero por cada pa�s, representando la cantidad de estudiantes de ese pa�s
que quieren jugar al mus. El n�mero de estudiantes de cada pa�s no exceder� nunca 10^9.

Salida
Por cada caso de prueba, el programa escribir� el n�mero de parejas distintas que pueden formarse sin que una pareja tenga a sus dos
integrantes de la misma nacionalidad. Se garantiza que la respuesta no ser� nunca superior a 10^18.

Ejemplo
--Entrada--
2
1 1
2
2 2
3
2 2 1
0

--Salida--
1
4
8

*/
#include<iostream>
using namespace std;

const int N = 10000;

int main()
{
	int casos;
	int pais[N];
	long long parejas, elementos;

	while (cin >> casos, casos > 0)
	{
		parejas = 0;
		elementos = 0;
		for (int i = 0; i < casos; i++)
		{
			cin >> pais[i];
			elementos += pais[i];
		}
		for (int i = 0; i < casos; i++)
		{
			elementos -= pais[i];
			parejas += pais[i] * elementos;
		}
		cout << parejas << '\n';
	}
	return 0;
}