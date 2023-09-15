
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
        
        
    
};

#endif
// -- RationalNumber_h