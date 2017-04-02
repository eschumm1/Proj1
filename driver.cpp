#include <iostream>
#include "posint.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() 
{

  // Set base to 16^4
  // This causes numbers to display in hex.  
  // However, base must be no greater than 2^15 when
  // using 32-bit integers, so we can only fit 3 hex 
  // digits (or 12 bits) per 32-bit int.  It is more
  // space-efficient to use the default, but then the
  // numbers will print in binary.
  	PosInt::setBase(10, 4);
	
  // x = 2^128
  	PosInt x(2);
 	PosInt y(128);
  	x.pow(y);

  // z = random number between 0 and 2^128 - 1
  	//  srand(0);
  	srand(time(NULL));
  	PosInt z(936900000);
  	//z.rand(x);
  	PosInt a(z);

  	cout << "x = 2^128 = " << x << endl;
  	//cout << "z = rand(x) = " << z << endl;
  	cout << "z  = " << z << endl;

	time_t begin;
  // z = z^2

	time(&begin);
  	z.mul(z);

	time_t end;
	time(&end);

  	cout << "z^2 = " << z << endl;
	double diff;
	diff = difftime(end, begin);
	double elapsed_sec = (1000000*double(end - begin) / CLOCKS_PER_SEC);
	cout << "Time elapsed: " << elapsed_sec << endl;	
	cout << "Execution time: " << diff << " seconds" << endl;
	
  // z.set(10000000);
  	cout << "a =  " << a << endl;
	cout << endl;
	clock_t kbegin = clock();

  	a.fastMul(a);

	clock_t kend = clock();
	
	cout << "Time elapsed: " <<  (1000000 * double(kend - kbegin) / CLOCKS_PER_SEC) << endl;
	cout << endl;
  	cout << "Fast mul a^2 = " << a << endl;
	
  // z = z mod x
  	z.mod(x);

 	cout << "z^2 mod x = " << z << endl;

}
  
