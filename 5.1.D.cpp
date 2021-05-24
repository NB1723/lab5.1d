#include "Complex.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

Complex makeComplex(Complex c)
{
	return c;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	int x, y;
	do
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
	} while (!(x > 0 && y < 0));

	Complex A(x, y);
	cout << A << endl;
	cout << "Size of class: " << sizeof(A) << endl;

	Complex B(5, -1);
	cout << B << endl;

	cout << "Sum of complex numbers" << endl;
	Complex C = A + B;
	cout << "C: " << endl;
	cout << C << endl;

	cout << "Product of complex numbers" << endl;
	Complex D = A * B;
	cout << "D: " << endl;
	cout << D << endl;

	cout << "Comparison of complex numbers" << endl;
	if (A == B)
		cout << "Complex numbers are equal" << endl << endl;
	else
		cout << "Complex numbers are not equal" << endl << endl;

	try
	{
		A--;
	}
	catch (MyDerivedException a)
	{
		cerr << a.What() << endl << endl;
	}
	catch (MyDerivedException* a)
	{
		cerr << a->What() << endl << endl;
	}

	do
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
	} while (!(x > 0 && y < 0));

	Complex N(x, y);

	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Pair K;
		cin >> K;
		cout << "K:" << endl;
		cout << K << endl;

		Pair M(4, -3);
		cout << "M:" << endl;
		cout << M << endl;
		cout << "Comparison of Pairs" << endl;
		if (K == M)
			cout << "Pairs are equal" << endl;
		else
			cout << "Pairs are not equal" << endl;

		if (K != M)
			cout << "Pairs are not equal" << endl;
		else
			cout << "Pairs are equal" << endl;

		if (K > M)
			cout << "Pair A is bigger than Pair B" << endl;
		else
			cout << "Pair A is smaller than Pair B" << endl;

		if (K < M)
			cout << "Pair A is smaller than Pair B" << endl;
		else
			cout << "Pair A is bigger than Pair B" << endl;

		if (K >= M)
			cout << "Pair A is bigger than/equal to Pair B" << endl;
		else
			cout << "Pair A is smaller than/equal to Pair B" << endl;

		if (K <= M)
			cout << "Pair A is smaller than/equal to Pair B" << endl;
		else
			cout << "Pair A is bigger than/equal to Pair B" << endl;
	}
	catch (MyException a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range& a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

}