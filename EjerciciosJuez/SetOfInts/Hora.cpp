#include<iostream>
#include "Hora.h"
#include "Error.h"

using namespace std;


bool Hora::correctTime()
{
	return (hour >= 0 || hour <= 23) || (min >= 0 || min <= 59) || (sec >= 0 || sec <= 59);
}

int Hora::timeToSec() const
{
	return (hour * 360) + (min * 60) + sec;
}

Hora::Hora(int h, int m, int s) throw (Error)
{
		hour = h;
		min = m;
		sec = s;
		if (!correctTime())
			throw Error("invalid time");
}

Hora::Hora(const Hora & time)
{
		hour = time.hour;
		min = time.min;
		sec = time.sec;
}


bool Hora::operator<(const Hora& time) const
{
	return timeToSec() < time.timeToSec();}

bool Hora::operator<=(const Hora & time) const
{
	return timeToSec() <= time.timeToSec();
}

bool Hora::operator>(const Hora & time) const
{
	return timeToSec() > time.timeToSec();
}

bool Hora::operator>=(const Hora & time) const
{
	return timeToSec() >= time.timeToSec();
}

bool Hora::operator==(const Hora & time) const
{
	return timeToSec() == time.timeToSec();
}

void Hora::print() const
{
	cout << hour << ":" << min << ":" << sec;
}