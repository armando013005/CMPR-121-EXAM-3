#pragma once
#include <iostream>

using namespace std;

class Rational {
private:
	int numerator;
	int denominator;

	void Normalize();

public:
	Rational();
	Rational(int num, int denom);

	void setNumerator(int num);
	void setDenominator(int denom);

	int getNumerator() const;
	int getDenominator() const;

	bool operator==(const Rational& other) const;
	bool operator<(const Rational& other) const;

	friend ostream& operator<<(ostream& out, const Rational& r);
};

