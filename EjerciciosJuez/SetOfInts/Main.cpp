#include<iostream>

//#include "DateTests.h"
//#include "SetTests.h"
#include "SetOfInts3.h"

using namespace std;

void ejercicio1Tema7()
{
	int elems, value;
	SetOfInts3 set;

	while (cin >> elems, elems != 0)
	{
		set = SetOfInts3();

		while (cin >> value, value != -1)
		{
			set.add(value);	
		}
		set.setSize(elems);
		cout << set << endl;
	}
}

int main(){
	//testSmallSet();
	//testSetOfInts();
	//testGenericSet();
	//testDate1();
	//testDate2();
	//testDate3();
	//testDate4();
	//ejercicio1Tema7();
}

