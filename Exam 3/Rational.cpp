#include "Rational.h"
#include <stdexcept>
#include <iomanip>

// Custom gcd function
static int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void Rational::Normalize() {
	if (denominator == 0) {
		throw invalid_argument("Denominator cannot be zero.");
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
	Normalize();
}

void Rational::setDenominator(int denom) {
	if (denom == 0) {
		throw invalid_argument("EXEPTION ERRO: Denominator cannot be zero.");
		return;
	}
	denominator = denom;
	Normalize();
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
	out << "\t" << string(1, 179) << setw(5) << right << r.numerator << '/' <<right<< r.denominator << string(1, 179);
	return out;
}

istream& operator>>(istream& in, Rational& r)
{
	int dem = 0;
	int num = 0;

	cout << "\n\tEnter numerator: ";
	cin >> num;
	cout << "\n\tEnter denominator: ";
	cin >> dem;

	try {
		r.setNumerator(num);
		r.setDenominator(dem);
	}
	catch (const exception& e)
	{
		cout<<'\n' << e.what() << '\n';
	}

	return in;
}
