#include "Complex.h"
#include <complex>
#include <string>
#include <cmath>
// TODO: Type your code here

using namespace std;


string Complex::toString() {
    
    string returnString;
    returnString = "(" + to_string(this->getReal()) + ", " + to_string(this->getImaginary()) + ")";
    return returnString;
}
double Complex::norm() {

    float power = 2.0;
    double realSquared = pow(this->getReal(), power);
    double imagSquared = pow(this->getImaginary(), power);

    imagSquared = -imagSquared;

    return realSquared + imagSquared;

}

Complex Complex::reciprocal() {

    double normValue = this->norm();

    try {
        if (normValue < 1e-10) {
            throw Complex::DivByZeroException();
        }
    }
    catch (Complex::DivByZeroException &excpt) {
        cout << excpt.what() << endl;
    }


    double recipReal = (this->getReal()/normValue);
    double recipImag = (this->getImaginary()/normValue);

    Complex *newComplex = new Complex(recipReal, recipImag);

    // TODO: throw error if norm is less than "1e-10"

    return *newComplex;
}

Complex operator+(const Complex& a, const Complex& b) {
    return a;
}