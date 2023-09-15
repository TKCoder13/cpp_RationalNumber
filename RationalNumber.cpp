#include "RationalNumber.h"

using namespace std;

int currentNumerator;
int currentDenominator;

// -- default constructor
RationalNumber::RationalNumber() 
: currentNumerator(0), currentDenominator(1) {}

// -- overload constructor
RationalNumber::RationalNumber(int numerator, int denominator) {
    this.currentNumerator = numerator;
    this.currentDenominator = denominator;
}

// -- copy constructor
RationalNumber::RationalNumber(const RationalNumber &src) {

}