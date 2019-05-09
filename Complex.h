#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

class Complex {
	private:
    	double real, imag;
        
	public:
		// TODO: Type your code here
		Complex() : real(0.0), imag(0.0) {};
		Complex(double realInput, double imagInput) : real(realInput), imag(imagInput) {};
		string toString();

		// getters 
		double getReal() {return this->real;}
		double getImaginary() {return this->imag;}

		// setters 
		
		void setReal(double newReal) {this->real = newReal;}
		void setImaginary(double newImag){this->imag = newImag;}

	
		class DivByZeroException {
		public:
			string toString() {return "Divide by zero exception";}
			string what() {return toString();}
		};
		
	// operators (the first one's signature is below for reference)
	friend Complex operator+(const Complex& a, const Complex& b);
	friend Complex operator-(const Complex& a, const Complex& b);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend Complex operator/(const Complex& a, const Complex& b);
	friend Complex operator==(const Complex& a, const Complex& b);
	//friend Complex operator<<(const Complex& a, const Complex &b);
		

};