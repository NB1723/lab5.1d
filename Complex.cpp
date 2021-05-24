#include "Complex.h"

Complex::Complex()
	: Pair()
{}

Complex::Complex(int X, int Y) throw(logic_error)
{
	if (!(X > 0 && Y < 0))
		throw logic_error("Condition is not met");

	this->SetRe(X);
	this->SetIm(Y);
}

Complex::Complex(const Complex& v)
	: Pair(v)
{}

Complex& Complex::operator --() throw(MyDerivedException)
{
	this->SetIm(this->GetIm() - 1);
	if (this->GetIm() < -7)
		throw new MyDerivedException();
	return *this;
}

Complex& Complex::operator ++() throw(MyException)
{
	this->SetRe(this->GetRe() + 1);
	if (this->GetRe() > 7)
		throw MyException("Real part of number is bigger than 7");
	return *this;
}

Complex Complex::operator --(int) throw(MyDerivedException)
{
	Complex a(*this);
	this->SetIm(this->GetIm() - 1);
	if (this->GetIm() < -7)
		throw new MyDerivedException();
	return a;
}

Complex Complex::operator ++(int) throw(logic_error)
{
	Complex a(*this);
	this->SetIm(this->GetIm() + 1);
	if (this->GetRe() > 7)
		throw MyException("Real part of number is bigger than 7");
	return a;
}

Complex operator + (const Complex Z1, const Complex Z2)
{
	Complex tmp;
	tmp.SetRe(Z1.GetRe() + Z2.GetRe());
	tmp.SetIm(Z1.GetIm() + Z2.GetIm());
	return tmp;
}

Complex operator * (const Complex Z1, const Complex Z2)
{
	Complex tmp;
	tmp.SetRe(Z1.GetRe() * Z2.GetRe() - Z1.GetIm() * Z2.GetIm());
	tmp.SetIm(Z1.GetRe() * Z2.GetIm() + Z2.GetRe() * Z1.GetIm());
	return tmp;
}

bool operator == (const Complex Z1, const Complex Z2)
{
	return Z1.GetRe() == Z2.GetRe() && Z1.GetIm() == Z2.GetIm();
}