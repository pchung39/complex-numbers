#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <sstream> 
using namespace std;

class Complex {
	private:
    	double real, imag;
        
	public:
		// TODO: Type your code here
		Complex() : real(0.0), imag(0.0) {}; // DONE
		Complex(int inputInt) : real(static_cast<double>(inputInt)), imag(0.0) {};
		Complex(double realInput, double imagInput) : real(realInput), imag(imagInput) {}; //DONE
		Complex(double realInput) : real(realInput), imag(0.0) {};
		Complex operator=(Complex& rhs);
		string toString(); //DONE
		bool determineRealWholeNumber();
		bool determineImagWholeNumber();

		// getters 
		double getReal() const {return this->real;}; //DONE
		double getImag() const {return this->imag;}; //DONE

		// setters 
		
		void setReal(double newReal) {this->real = newReal;}; //DONE
		void setImag(double newImag){this->imag = newImag;}; //DONE

		double norm(); // DONE
		Complex reciprocal();

		class DivByZeroException {
		public:
			string toString() {return "Divide by zero exception";};
			string what() {return toString();};
		};
		// operators (the first one's signature is below for reference)
		friend Complex operator+(Complex& a, Complex& b);
		friend Complex operator+(Complex& a, int inputInt);
		friend Complex operator-(Complex& a, Complex& b);
		friend Complex operator*(Complex& a, Complex& b);
		friend Complex operator/(Complex& a, Complex& b);
		friend bool operator<(Complex& a, Complex& b);
		friend bool operator==(const Complex& a, const Complex& b);
		//friend bool operator==(Complex& a, int inputInt);
		friend string operator<<(stringstream& ss, Complex a);
		

};