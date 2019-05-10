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
		Complex() : real(0.0), imag(0.0) {}; // DONE
		Complex(double realInput, double imagInput) : real(realInput), imag(imagInput) {}; //DONE
		string toString(); //DONE

		// getters 
		double getReal() {return this->real;}; //DONE
		double getImaginary() {return this->imag;}; //DONE

		// setters 
		
		void setReal(double newReal) {this->real = newReal;}; //DONE
		void setImaginary(double newImag){this->imag = newImag;}; //DONE

		double norm(); // DONE
		Complex reciprocal();

		class DivByZeroException {
		public:
			string toString() {return "Divide by zero exception";};
			string what() {return toString();};
		};
		
		// operators (the first one's signature is below for reference)
		friend Complex operator+(const Complex& a, const Complex& b);
		friend Complex operator-(const Complex& a, const Complex& b);
		friend Complex operator*(const Complex& a, const Complex& b);
		friend Complex operator/(const Complex& a, const Complex& b);
		friend Complex operator==(const Complex& a, const Complex& b);
		//friend Complex operator<<(const Complex& a, const Complex &b);
		

};