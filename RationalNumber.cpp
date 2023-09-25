#include "RationalNumber.h"

#include <string>
#include <cmath>
#include <typeinfo>

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
RationalNumber::~RationalNumber() {}

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
    char exception[] = "Denominator cannot be 0";
    char* zeroException = exception;
    try {
        if (num != 0) {
            this->denominator = num;
            return;
        } else {
            throw zeroException;
        }
    } catch (std::exception& e) {
        cout << "exception caught: " << e.what() << endl;
    }
}



bool RationalNumber::equals(RationalNumber rhs) {
    if (typeid(*this) == typeid(rhs)) {
        if (this->numerator == rhs.numerator && this->numerator == rhs.denominator) 
            return true;
    }
    return false;
}

string RationalNumber::toString() {
    int currentNumerator = this->getNumerator();
    int currentDenominator = this->getDenominator();

    // -- Checks for negative values
    bool isNegative = false;
    if (currentNumerator < 0) isNegative = !isNegative;
    if (currentDenominator < 0) isNegative = !isNegative;

    currentNumerator = std::abs(currentNumerator);
    currentDenominator = std::abs(currentDenominator);

    int wholeNumber = std::abs(currentNumerator / currentDenominator);
    int remainder = std::abs(currentNumerator % currentDenominator);

    // -- Reduce improper fractions
    int gcd = getGCD(remainder, currentDenominator);
    if (gcd > 1) {
        remainder = remainder / gcd;
        currentDenominator = currentDenominator / gcd;
    }

    if (isNegative) {
        if (wholeNumber == 0) {
            if (remainder == 0) {
                return "-" + to_string(wholeNumber);
            } else {
                return "-" + to_string(remainder) + "/" + to_string(currentDenominator);
            }
        } else {
            if (remainder == 0) {
                return "-" + to_string(wholeNumber);
            } else {
                return "-" + to_string(wholeNumber) + " " + to_string(remainder) + "/" + to_string(currentDenominator);
            }
        }
    } else {
        if (wholeNumber == 0) {
            if (remainder == 0) {
                return to_string(wholeNumber);
            } else {
                return to_string(remainder) + "/" + to_string(currentDenominator);
            }
        } else {
            if (remainder == 0) {
                return to_string(wholeNumber);
            } else {
                return to_string(wholeNumber) + " " + to_string(remainder) + "/" + to_string(currentDenominator);
            }
        }
    }
}

int RationalNumber::getGCD(int num1, int num2) {
    int gcd = 1;
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) 
            gcd = i;
    }
    return gcd;
}

RationalNumber RationalNumber::add(RationalNumber rhs) {
    int leftNumerator = this->getNumerator() * rhs.getDenominator();
    int rightNumerator = rhs.getNumerator() * this->getDenominator();

    int tempNumerator = leftNumerator + rightNumerator;
    int tempDenominator = this->getDenominator() * rhs.getDenominator();
    
    int endNumerator;
    int endDenominator;

    // -- Simplify
    int gcd = getGCD(tempNumerator, tempDenominator);
    if (gcd == 1) {
        RationalNumber output(tempNumerator, tempDenominator);
        return output;
    } else {
        tempNumerator = tempNumerator / gcd;
        tempDenominator = tempDenominator / gcd;
        RationalNumber output(tempNumerator, tempDenominator);
        return output;
    }
}

RationalNumber RationalNumber::sub(RationalNumber rhs) {
    int leftNumerator = this->getNumerator() * rhs.getDenominator();
    int rightNumerator = rhs.getNumerator() * this->getDenominator();

    int tempNumerator = leftNumerator - rightNumerator;
    int tempDenominator = this->getDenominator() * rhs.getDenominator();
    
    int endNumerator;
    int endDenominator;

    int gcd = getGCD(tempNumerator, tempDenominator);
    if (gcd == 1) {
        RationalNumber output(tempNumerator, tempDenominator);
        return output;
    } else {
        tempNumerator = tempNumerator / gcd;
        tempDenominator = tempDenominator / gcd;
        RationalNumber output(tempNumerator, tempDenominator);
        return output;
    }
}

RationalNumber RationalNumber::mult(RationalNumber rhs) {
    int currentNumerator = this->getNumerator() * rhs.getNumerator();
    int currentDenominator = this->getDenominator() * rhs.getDenominator();
    RationalNumber output(currentNumerator, currentDenominator);
    return output;
}

RationalNumber RationalNumber::div(RationalNumber rhs) {
    char divZeroMessage[] = "Not divisible by 0";
    char *divZeroException = divZeroMessage;
    try {
        int outNumerator = this->getNumerator() * rhs.getDenominator();
        int outDenominator = this->getDenominator() * rhs.getNumerator();
        if (outDenominator != 0) {
            RationalNumber output(outNumerator, outDenominator);
            return output;
        } else {
            throw divZeroException;
        }
    } catch (const char* exception) {
        cout << exception << endl;
    }
}

double RationalNumber::sqrt() {
    return 0.0;
}