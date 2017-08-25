#ifndef HORA_H_
#define HORA_H_

#include "Error.h"

using namespace std;

class Hora {
		//Dato compuesto por 3 valor enteros respresentativos de un formato de horas HH:MM:SS
	private:

		int hour;
		int min;
		int sec;
		bool correctTime();
		int timeToSec() const;

	public:

		Hora(int hour, int min, int sec) throw (Error);
		Hora(const Hora& time);
		bool operator<(const Hora& time)const;
		bool operator<=(const Hora& time)const;
		bool operator>(const Hora& time)const;
		bool operator>=(const Hora& time)const;
		bool operator==(const Hora& time)const;
		void print() const;
};

#endif // !HORA_H_
