#include <iostream>
#include "posint.h"
#include <stdlib.h>
#include <chrono>
using namespace std;
typedef std::chrono::high_resolution_clock Clock;

int main() 
{

  // Set base to 16^4
  // This causes numbers to display in hex.  
  // However, base must be no greater than 2^15 when
  // using 32-bit integers, so we can only fit 3 hex 
  // digits (or 12 bits) per 32-bit int.  It is more
  // space-efficient to use the default, but then the
  // numbers will print in binary.
  	PosInt::setBase(10, 2);
	
  	// x = 2^128
  	PosInt x(2);
 	PosInt y(128);
  	x.pow(y);
	int mulTime, fastMulTime;

  	// z = random number between 0 and 2^128 - 1
  	srand(0);
  	srand(time(NULL));
  	PosInt z(12345678);
  	//z.rand(x);
  	PosInt a(z);

	cout << "****************************************************" << endl;
  	cout << "x = 2^128 = " << x << endl;
  	cout << "z = rand(x) = " << z << endl;
	cout << "****************************************************" << endl;
	// z = z^2
	a.set(z);
	
	auto begin = Clock::now();
	z.mul(z);
	auto end = Clock::now();
	
	mulTime = chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
	cout << "z^2 = " << z << endl;
	cout << "Mul runtime: " << mulTime << " nanoseconds." << endl;

	cout << "****************************************************" << endl;
	begin = Clock::now();
	a.fastMul(a);
	end = Clock::now();
	
	fastMulTime = chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
	cout << "Fast mul z^2 = " << a << endl;
	cout << "FastMul runtime: " << fastMulTime << " nanoseconds." << endl;

  	// z = z mod x
  	z.mod(x);
 	cout << "z^2 mod x = " << z << endl;
}
  
