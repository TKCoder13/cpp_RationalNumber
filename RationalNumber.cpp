#include "RationalNumber.h"

using namespace std;

int numerator;
int denominator;

/* CONSTRUCTORS */

// -- Default Constructor
RationalNumber::RationalNumber() 
: numerator(0), denominator(1) {}

// -- Overload Constructor
RationalNumber::RationalNumber(int num, int denom) {
    this->numerator = num;
    this->denominator = denom;
}

// -- Copy Constructor
RationalNumber::RationalNumber(const RationalNumber &src) {
    this->numerator = src.numerator;
    this->denominator = src.denominator;
}

// -- Deconstructor
RationalNumber::~RationalNumber() {
    cout << "Deconstructor" << endl;
}

/* METHODS */

int RationalNumber::getNumerator() {
    return this->numerator;
}

int RationalNumber::getDenominator() {
    return this->denominator;
}

void RationalNumber::setNumerator(int num) {
    this->numerator = num;
}

void RationalNumber::setDenominator(int num) {
    this->denominator = num;
}

bool RationalNumber::equals(RationalNumber rhs) {
    if (typeid(this) == typeid(rhs)) {
        if (this->numerator == rhs.numerator && this->numerator == rhs.denominator) return true;
    }
    return false;
}

