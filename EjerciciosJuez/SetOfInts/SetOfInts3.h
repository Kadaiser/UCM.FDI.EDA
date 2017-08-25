#ifndef SETOFINTS3_H_
#define SETOFINTS3_H_

#include "Error.h"
#include <iostream>

class SetOfInts3 {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		static const int MAXSIZE = 50;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);

	public:
		SetOfInts3();
		bool isEmpty() const;
		void add(int x) throw (Error);
		bool contains(int x) const;
		void remove(int x);

		int getSize() const;
		void setSize(int value) throw (Error);
		int getMax() const throw (Error);
		void removeMax();
		int getMin() const throw (Error);
		void removeMin();

		bool operator==(const SetOfInts3& set) const;
		bool operator<(const SetOfInts3& set) const;
		bool operator<=(const SetOfInts3& set) const;
		bool operator>(const SetOfInts3& set) const;
		bool operator>=(const SetOfInts3& set) const;
		friend istream& operator>>(istream& sIn,SetOfInts3& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
};

#endif /* SETOFINTS3_H_ */
