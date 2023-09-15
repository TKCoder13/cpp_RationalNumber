
#include "RationalNumber.h"

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    RationalNumber lhs(1, 2);
    RationalNumber rhs(3, 4);

    RationalNumber result;

    result = lhs.add(rhs);
    cout << "(" << lhs.toString() + ") + (" + rhs.toString() << ") = ";
    cout << "(" << result.toString() << ")" << endl;

    result = lhs.sub(rhs);
    cout << "(" << lhs.toString() + ") - (" + rhs.toString() << ") = ";
    cout << "(" << result.toString() << ")" << endl;

    result = lhs.mult(rhs);
    cout << "(" << lhs.toString() + ") * (" + rhs.toString() << ") = ";
    cout << "(" << result.toString() << ")" << endl;

    result = lhs.div(rhs);
    cout << "(" << lhs.toString() + ") / (" + rhs.toString() << ") = ";
    cout << "(" << result.toString() << ")" << endl;

    try {
        rhs.setNumerator(0);
        rhs.setDenominator(1);
        cout << "(" << lhs.toString() + ") / (" << rhs.toString() << ") = ";
        result = lhs.div(rhs);
        cout << "(" << result.toString() << ")" << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }



    cout << "(" << lhs.toString() + ") == (" + rhs.toString() << ") = ";
    cout << (lhs.equals(rhs) ? "true" : "false") << endl;

    rhs.setNumerator(lhs.getNumerator());
    rhs.setDenominator(lhs.getDenominator());
    cout << "(" << lhs.toString() + ") == (" + rhs.toString() << ") = ";
    cout << (lhs.equals(rhs) ? "true" : "false") << endl;

    lhs.setNumerator(5);
    lhs.setDenominator(12);
    double dresult = lhs.sqrt();

    cout << std::sqrt((double)lhs.getNumerator() / (double)lhs.getDenominator()) << " == " << dresult << endl;

}
