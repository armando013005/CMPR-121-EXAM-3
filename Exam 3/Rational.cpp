#include "Rational.h"
#include <stdexcept>
#include <iomanip>
#include "input.h"

// Custom gcd function
static int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

void Rational::Normalize() {
	if (denominator == 0) {
		throw invalid_argument("EXEPTIONAL ERROR: Denominator cannot be zero.");
	}
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
	int gcdValue = gcd(abs(numerator), denominator);
	numerator /= gcdValue;
	denominator /= gcdValue;
}

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
	Normalize();
}

void Rational::setNumerator(int num) {
	numerator = num;
}

void Rational::setDenominator(int denom) {
	if (denom == 0) {
		throw invalid_argument("EXEPTION ERROR: Denominator cannot be zero.");
		return;
	}
	denominator = denom;
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

bool Rational::operator==(const Rational& other) const {
	return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator<(const Rational& other) const {
	return numerator * other.denominator < other.numerator * denominator;
}

ostream& operator<<(ostream& out, const Rational& r) {
	out << r.numerator << '/' << r.denominator ;
	return out;
}

istream& operator>>(istream& in, Rational& r)
{
	cout << "\n\t\tInput a Rational number [numerator/denominator] to be inserted...";
	int num = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
	int den = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

	r.setNumerator(num);
	r.setDenominator(den);
	r.Normalize();
	return in;
}
