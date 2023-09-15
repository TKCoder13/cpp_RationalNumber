
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
        RationalNumber(const RationalNumber rhs);
        // -- Deconstructor
        ~RationalNumber();
        
        /* METHODS */

        string toString();
        bool equals(RationalNumber rhs);

        int getNumerator();
        int getDenominator();
    
        void setNumerator();
        void setDenominator();

        RationalNumber add(RationalNumber rhs);
        RationalNumber sub(RationalNumber rhs);
        RationalNumber mult(RationalNumber rhs);
        RationalNumber div(RationalNumber rhs);
        double sqrt();

    private:

        /* VARIABLES */
        int numerator;
        int denominator;
    
        /* METHODS */
        int getGCD(int num1, int num2);
};

#endif /* RationalNumber_h */