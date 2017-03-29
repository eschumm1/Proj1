#include <iostream>
#include "posint.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {

  // Set base to 16^4
  // This causes numbers to display in hex.  
  // However, base must be no greater than 2^15 when
  // using 32-bit integers, so we can only fit 3 hex 
  // digits (or 12 bits) per 32-bit int.  It is more
  // space-efficient to use the default, but then the
  // numbers will print in binary.
  PosInt::setBase(16, 3);

  // x = 2^128
  PosInt x(2);
  PosInt y(128);
  x.pow(y);

  // z = random number between 0 and 2^128 - 1
  //  srand(0);
  srand(time(NULL));
  PosInt z(10);
  //z.rand(x);
  PosInt a(z);

  cout << "x = 2^128 = " << x << endl;
  //cout << "z = rand(x) = " << z << endl;
  cout << "z  = " << z << endl;

  // z = z^2
  z.mul(z);
  cout << "z^2 = " << z << endl;
	
	//z.set(10000000);
	cout << "a =  " << a << endl;
	a.fastMul(a);
	cout << "Fast mul A^2 = " << a << endl;

  // z = z mod x
  z.mod(x);

  cout << "z^2 mod x = " << z << endl;


}
  
