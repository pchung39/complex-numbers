// Test driver for the Complex number class
// &: Dec 2018

#include "Complex.h"


int main () {
   Complex a(1,1), b(3,4), c, d(2,2);

   // cout << a.toString() << endl;
   // cout << d.norm() << endl;

   // Complex test = b / d;
   // cout << test.toString() << endl;

   cout << b.reciprocal().toString() << endl;

   Complex x = 10;
   cout << x.toString() << endl;

   // Complex hello = a/d;
   ///cout << hello.toString() << endl;

   // if (a/b == 10) {
   //    cout << "hi";;
   // }
   // cout << a.norm() << endl;
   // cout << a.reciprocal().toString() << endl;
   // Complex hello = 1;
   // cout << hello.toString() << endl;
    
   // c = a + b;
   // cout << a << " + " << b << " = " << c << endl;
   
   // c = a + 1;
   // cout << a << " + " << 1 << " = " << c << endl;

   // // TODO: Run more tests here

   // try {
   //    c = a / b;
   //    cout << a << " / " << b << " = " << c << endl;
   // } catch (Complex::DivByZeroException e) {
   //    cerr << e.what() <<endl;
   // }
   
   // TODO: Run more tests here
   
   return 0;
}