#include "stack.h"
#include "calculator.h"
#include <iostream>

//
// Assignment 2 : Simple calculator using Stack
//
// COSE213 Fall 2021
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

// stack & calculator test

int main()
{
	// Stack test
	Stack<int> s;
	
	s.Push(23);
	s.Push(4);
	s.Push(233);
	s.Push(235);
	s.Push(236);
	s.Push(237);
	s.Push(238);
	s.Push(239);
	s.Push(230);
	s.Push(2311);
	s.Push(102);
	s.Push(2311);
	s.Push(102);
	s.Print();
	printf("--\n");
	
	s.Push(345);
	s.Push(77);
	s.Print();
	printf("--\n");
	
	s.Pop();
	s.Push(678);
	s.Push(91011);
	s.Print();
	printf("--\n");
	
	for(int i=0; i<6; i++)
	{
		try {
			s.Pop();
			std::cout << "Pop() is called" << std::endl;
		}
		catch(const char* message)
		{
			std::cout << message << std::endl;
		}		
	}

	// Calculator test
	char str1[] ="-10-((-2+(2+4*3))-12) + 122 * (123 + (120+888) - 300)";
	// The correct result is 101372
	double res1 = Eval(str1);
	std::cout << "Result : " << res1 << std::endl;
	printf("\n");
	
	char str2[] = "1.2 + 2.4 + 3.0*2";
	// The correct result is 9.6
	double res2 = Eval(str2);
	std::cout << "Result : " << res2 << std::endl;
	printf("\n");

	char str3[] = "(-2 )*( -3)  +(-6 )/     (-2  )+( - (- 3)) ";
	double res3 = Eval(str3);
	std::cout << "Result : " << res3 << std::endl;
	printf("\n");


	char str4[] = "(2+3*5)+7 ";
	double res4 = Eval(str4);
	std::cout << "Result : " << res4 << std::endl;
	printf("\n");

	char str5[] = " 10*5*-(2+5)";
	double res5 = Eval(str5);
	std::cout << "Result : " << res5 << std::endl;

	return 0;
}
