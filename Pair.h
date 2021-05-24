#pragma once
#pragma pack(1)
#include "MyException.h"
#include "MyDerivedException.h"

using namespace std;

class Pair
{
private:
	int x, y;

public:
	Pair();
	Pair(const int x, const int y) throw(out_of_range);
	Pair(const Pair& a);

	int GetRe() const { return x; }
	int GetIm() const { return y; }

	void SetRe(int value) { x = value; }
	void SetIm(int value) { y = value; }

	Pair& operator =(const Pair& n);
	operator string() const;

	friend bool operator == (const Pair& l, const Pair& r);
	friend bool operator != (const Pair& l, const Pair& r);
	friend bool operator > (const Pair& l, const Pair& r);
	friend bool operator < (const Pair& l, const Pair& r);
	friend bool operator >= (const Pair& l, const Pair& r);
	friend bool operator <= (const Pair& l, const Pair& r);

	friend ostream& operator << (ostream& out, const Pair& a);
	friend istream& operator >> (istream& in, Pair& a);
};