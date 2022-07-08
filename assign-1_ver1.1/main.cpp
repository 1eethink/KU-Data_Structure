//
// Fall 2021 COSE213 Assignment 1
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include "polynomial.h"
#include <iostream>

int main()
{
	Polynomial f, g;
	f.CreateTerm(12,2);
	f.CreateTerm(11,1);
	f.CreateTerm(10, 0);
	g.CreateTerm(0,0);
	Polynomial h = f*g;

	f.CreateTerm(0, 0);
	std::cout << "f = ";
	f.Print();

	f.CreateTerm(-4, 3);
	f.CreateTerm(2.3, 2);

	f.CreateTerm(-3, 0);
	std::cout << "f = ";
	f.Print();

	f.CreateTerm(4, 4);
	std::cout << "f = ";
	f.Print();
	
	f.CreateTerm(5, 5);
	std::cout << "f = ";
	f.Print();

	f.CreateTerm(6, 6);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(7, 7);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(0, 7);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(8, 8);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(9, 9);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(10, 10);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(11, 11);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(12, 12);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(13, 12);
	std::cout << "f = ";
	f.Print();
	
	f.CreateTerm(0, 12);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(14, 14);
	std::cout << "f = ";
	f.Print();
	f.CreateTerm(15, 15);
	std::cout << "f = ";
	f.Print();

	g.CreateTerm(3, 4);
	g.CreateTerm(-8, 0);
	g.CreateTerm(-4, 3);
	
	std::cout << "g = ";
	g.Print();
	
	g.CreateTerm(5, 2);
	std::cout << "g (creating a new term) = ";
	g.Print();
	
	// copy constructor test
	std::cout << "h (created from f) = ";
	h = f;
	h.Print();
	
	// assignment operator test
	std::cout << "h (assigned from g) = ";
	h = g;	
	h.Print();
	
	// Add test
	std::cout << "f + g = ";
	h = f + g;	
	h.Print();

	std::cout << "g + f = ";
	h = g+f;	
	h.Print();
	
	// Subtract test
	std::cout << "f - g = ";
	h = f - g;
	h.Print();
	
	std::cout << "g - f = ";
	h = g - f;
	h.Print();
	

	g.CreateTerm(5, 5);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(6, 6);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(7, 7);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(8, 8);
	std::cout << "g = ";
	g.Print();	
	g.CreateTerm(0, 0);
	std::cout << "g = ";
	g.Print();	

	g.CreateTerm(9, 9);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(40, 40);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(41, 41);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(42, 42);
	std::cout << "g = ";
	g.Print();
	g.CreateTerm(43, 43);
	std::cout << "g = ";
	g.Print();

	// Add test
	std::cout << "f + g = ";
	h = f + g;	
	h.Print();

	std::cout << "g + f = ";
	h = g+f;	
	h.Print();
	
	// Subtract test
	std::cout << "f - g = ";
	h = f - g;
	h.Print();
	
	std::cout << "g - f = ";
	h = g - f;
	h.Print();


	// Equal test
	if(f == g)
		std::cout << "f and g are same" << std::endl;
	else
		std::cout << "f and g are different" << std::endl;
	
	Polynomial x, y;

	x.CreateTerm(-4, 3);
	x.CreateTerm(2.3, 2);

	x.CreateTerm(-3, 0);
	std::cout << "x = ";
	x.Print();

	y.CreateTerm(3, 4);
	y.CreateTerm(-8, 0);
	y.CreateTerm(-4, 3);
	
	std::cout << "y = ";
	y.Print();

	if(x == y)
		std::cout << "x and y are same" << std::endl;
	else
		std::cout << "x and y are different" << std::endl;

	Polynomial z;

	z.CreateTerm(-4, 3);
	z.CreateTerm(2.3, 2);

	z.CreateTerm(-3, 0);
	std::cout << "z = ";
	z.Print();
	
	z.CreateTerm(-3, 1);
	std::cout << "z = ";
	z.Print();
	if(z == x)
		std::cout << "x and z are same" << std::endl;
	else
		std::cout << "x and z are different" << std::endl;
	z.CreateTerm(0, 1);
	std::cout << "z = ";
	z.Print();
	if(z == x)
		std::cout << "x and z are same" << std::endl;
	else
		std::cout << "x and z are different" << std::endl;
	
	// Eval test
	std::cout << "x(3.5) is " << x.Eval(3.5) << std::endl;
	std::cout << "x(1) is " << x.Eval(1) << std::endl;
	std::cout << "x(0) is " << x.Eval(0) << std::endl;
	std::cout << "x(-2) is " << x.Eval(-2) << std::endl;

	// Derivative test
	Polynomial i = x.Derivative(); 
	std::cout << "Derivative of x = ";
	i.Print();

	Polynomial j = y.Derivative(); 
	std::cout << "Derivative of y = ";
	j.Print();

	Polynomial asdf = f.Derivative(); 
	std::cout << "Derivative of f = ";
	asdf.Print();

	Polynomial fdsa = g.Derivative(); 
	std::cout << "Derivative of g = ";
	fdsa.Print();
	
	return 0;
}
