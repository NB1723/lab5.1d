#pragma once
#include "Pair.h"

class Complex : public Pair
{
public:
	Complex();
	Complex(int x, int y) throw(logic_error);;
	Complex(const Complex& v);

	Complex& operator --() throw(MyDerivedException);
	Complex& operator ++() throw(MyException);
	Complex operator --(int) throw(MyDerivedException);
	Complex operator ++(int) throw(logic_error);

	friend  Complex operator + (const Complex Z1, const Complex Z2);
	friend  Complex operator * (const Complex Z1, const Complex Z2);
	friend  bool operator == (const Complex Z1, const Complex Z2);
};