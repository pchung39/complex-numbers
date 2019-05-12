#include "Complex.h"
#include <complex>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

// TODO: Type your code here

using namespace std;

Complex Complex::operator=(Complex& rhs) {

    if (&rhs != this) {
        this->setReal(rhs.getReal());
        this->setImag(rhs.getImag());
    }

    return *this;
}

// Complex Complex::operator=(int inputInt) {

//     //cout << "INPUT: " << realAssign << endl;
//     this->setReal(static_cast<float>(inputInt));
//     this->setImag(0.0);

//     cout << "GET: " << this->getReal() << endl;
//     cout << "GET: " << this->getImag() << endl;

//     return *this;

// }

bool Complex::determineRealWholeNumber() {

    float real = this->getReal();

    if (abs(real-int(real))>0) {
        return false;
    }
    return true;

}

bool Complex::determineImagWholeNumber() {
    
    float imag = this->getImag();

    if (abs(imag-int(imag))>0) {
        return false;
    }

    return true;

}

string Complex::toString() {
    
    bool ifRealWholeNum = determineRealWholeNumber();
    bool ifImagWholeNum = determineImagWholeNumber();
    string returnString;
    string realStr;
    string imagStr;

    if (ifRealWholeNum == true) {
        realStr = to_string(static_cast<int>(this->getReal()));
    }
    else {
        realStr = to_string(this->getReal());
        realStr.erase(realStr.find_last_not_of('0') + 1, string::npos );        
    }

    if (ifImagWholeNum == true) {
        imagStr = to_string(static_cast<int>(this->getImag()));
    }
    else {
        imagStr = to_string(this->getImag());
        imagStr.erase(imagStr.find_last_not_of('0') + 1, string::npos );        
    }

    returnString = "(" + realStr + ", " + imagStr + ")";

    return returnString;
}
double Complex::norm() {

    double power = 2.0;
    double realSquared = pow(this->getReal(), power);
    double imagSquared = pow(this->getImag(), power);

    //double sqrtSum = sqrt(realSquared + imagSquared);

    return realSquared + imagSquared;

}

Complex Complex::reciprocal() {

    double normValue = this->norm();
    cout << "NORM: " << normValue << endl;
    cout << "real: " << this->getReal() << endl;
    cout << "imag: " << this->getImag() << endl;

    // if (normValue == 0) {
    //     throw Complex::DivByZeroException();
    // }

    if (normValue < 1e-10) {
        throw Complex::DivByZeroException();
    }

    double recipReal = (this->getReal()/normValue);   
    double recipImag = -(this->getImag()/normValue);   

    //cout << "RECIP: " << recipReal << endl;
    //cout << "RECIP: " << recipImag << endl;

    Complex *newComplex = new Complex(recipReal, recipImag);

    // cout << "NEW: " << newComplex->toString() << endl; 

    return *newComplex;
}


bool operator==(const Complex& a, const Complex& b) {
    
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

Complex operator/(Complex& a, Complex& b) {

    // cout << "A real: " << a.getReal() << endl;
    // cout << "A imag: " << a.getImag() << endl;

    // cout << "B real: " << b.getReal() << endl;
    // cout << "B imag: " << b.getImag() << endl;

    Complex bRecip = b.reciprocal();

    // cout << "B Recip real: " << bRecip.getReal() << endl;
    // cout << "B Recip imag: " << bRecip.getImag() << endl;

    Complex response = a * bRecip;
    // cout << "imag: " << response.getImag() << endl;
    // cout << "RES: " << response.toString() << endl;
  
    return response;

}

string operator<<(stringstream& ss, Complex a) {

    ss << a.toString();
    return ss.str();

}