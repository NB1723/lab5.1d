#include "Pair.h"

Pair::Pair()
	: x(0), y(0)
{}

Pair::Pair(const int x, const int y) throw(out_of_range)
{
	if (!((x > 0 && x < 10) || (y > -10 && y < 0)))
		throw out_of_range("Numbers must belong to x=[0;10], y=[-10;0]");

	this->x = x;
	this->y = y;
}

Pair::Pair(const Pair& A)
{
	SetRe(A.GetRe());
	SetIm(A.GetIm());
}

Pair& Pair::operator =(const Pair& n)
{
	SetRe(n.GetRe());
	SetIm(n.GetIm());
	return *this;
}

bool operator == (const Pair& A, const Pair& B)
{
	return (A.GetRe() == B.GetRe() && A.GetIm() == B.GetIm());
}

bool operator != (const Pair& A, const Pair& B)
{
	return !(A == B);
}

bool operator > (const Pair& A, const Pair& B)
{
	return (A.GetRe() > B.GetRe()) || (A.GetRe() == B.GetRe() && A.GetIm() > B.GetIm());
}

bool operator < (const Pair& A, const Pair& B)
{
	return (A.GetRe() < B.GetRe()) || (A.GetRe() == B.GetRe() && A.GetIm() < B.GetIm());
}

bool operator >= (const Pair& A, const Pair& B)
{
	return !(A < B);
}

bool operator <= (const Pair& A, const Pair& B)
{
	return !(A > B);
}

Pair::operator string() const
{
	stringstream ss;
	ss << x << " + i * " << y << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Pair& A)
{
	out << string(A);
	return out;
}

istream& operator >> (istream& in, Pair& A)
{
	int x, y;
	cout << "x = "; in >> x;
	cout << "y = "; in >> y;

	if (!((x > 0 && x < 10) || (y > -10 && y < 0)))
		throw out_of_range("Numbers must belong to x=[0;10], y=[-10;0]");

	A.SetRe(x); A.SetIm(y);
	return in;
}