#include "Complex.h"
#include <complex>
#include <string>
#include <cmath>
// TODO: Type your code here

using namespace std;

// Complex Complex::operator=(Complex& rhs) {

//     if (&rhs != this) {
//         this->setReal(rhs.getReal());
//         this->setImag(rhs.getImag());
//     }

//     return *this;
// }

Complex Complex::operator=(int realAssign) {

    this->setReal(static_cast<float>(realAssign));
    this->setImag(0.0);

    return *this;

}

string Complex::toString() {
    
    string returnString;
    returnString = "(" + to_string(static_cast<int>(this->getReal())) + ", " + to_string(static_cast<int>(this->getImag())) + ")";
    return returnString;
}
double Complex::norm() {

    double power = 2.0;
    double realSquared = pow(this->getReal(), power);
    double imagSquared = pow(this->getImag(), power);

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
    double recipImag = (this->getImag()/normValue);

    Complex *newComplex = new Complex(recipReal, recipImag);

    return *newComplex;
}

Complex operator+(const Complex& a, const Complex& b) {
    return a;
}

bool operator==(Complex& a, Complex& b) {
    
    if (a.getReal() != b.getReal()) {
        return false;
    }
    
    if (a.getImag() != b.getImag()) {
        return false;
    } 

    return true;

}

bool operator<(Complex& a, Complex& b) {
    
    double aNorm = a.norm();
    double bNorm = b.norm();

    if (bNorm > aNorm) {
        return true;
    }
    else {
        return false;
    }

}

Complex operator+(Complex& a, Complex& b) {

    double aReal = a.getReal();
    double aImag = a.getImag();

    double bReal = b.getReal();
    double bImag = b.getImag();

    double realSum = aReal + bReal;
    double imagSum = aImag + bImag;

    Complex* response = new Complex(realSum, imagSum);

    return *response;

}

Complex operator-(Complex& a, Complex& b) {

    double aReal = a.getReal();
    double aImag = a.getImag();

    double bReal = b.getReal();
    double bImag = b.getImag();

    double realSum = aReal - bReal;
    double imagSum = aImag - bImag;

    Complex* response = new Complex(realSum, imagSum);

    return *response;

}

Complex operator*(Complex& a, Complex& b) {


    double aReal = a.getReal();
    double aImag = a.getImag();

    double bReal = b.getReal();
    double bImag = b.getImag();


    //mult a real * b real 
    double abRealMultiply = aReal * bReal; 
    // mult a imag * b imag
    double abImagMultiply = aImag * bImag;

    double multReal = abRealMultiply - abImagMultiply;

    // mult a real * b imag
    double aRealbImagMultiply = aReal * bImag; 
    
    // mult a Imag * b Real
    double aImagbRealMultiply = aImag * bReal;

    double multImag = aRealbImagMultiply + aImagbRealMultiply;

    Complex* response = new Complex(multReal, multImag);

    return *response;



}
ostream& operator<<(ostream& os, string str) {

    os << str;
    return os;

}