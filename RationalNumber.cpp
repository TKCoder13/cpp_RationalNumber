#include "RationalNumber.h"

using namespace std;

int currentNumerator;
int currentDenominator;

// -- Default Constructor
RationalNumber::RationalNumber() 
: currentNumerator(0), currentDenominator(1) {}

// -- Overload Constructor
RationalNumber::RationalNumber(int numerator, int denominator) {
    this.currentNumerator = numerator;
    this.currentDenominator = denominator;
}

// -- Copy Constructor
RationalNumber::RationalNumber(const RationalNumber &src) {

}

// -- Deconstructor
RationalNumber::~RationalNumber() {
    cout << "Deconstructor" << endl;
}