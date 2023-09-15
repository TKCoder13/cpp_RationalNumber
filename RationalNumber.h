
#ifndef RationalNumber_h
#define RationalNumber_h

#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class RationalNumber {

    public:
        // -- Default Constructor
        RationalNumber();
        // -- Overload Constructor
        RationalNumber(int numerator, int denominator);
        // -- Copy Constructor
        RationalNumber(const RationalNumber);
        // -- Deconstructor
        ~RationalNumber();
        
        /* METHODS */

        string toString();

        int getNumerator();

        int getDenominator();
    
    private:
        int numerator;
        int denominator;
    
};

#endif
// -- RationalNumber_h