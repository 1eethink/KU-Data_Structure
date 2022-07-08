#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Assignment 2 : Simple calculator using Stack
//
// COSE213 Fall 2021
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include <iostream>
#include <cassert>
#include <math.h>
#include <string.h>
#include "stack.h"



Stack<double> opr; // stack for operands
Stack<char> opt;   // stack for operators

using namespace std;


bool higherICP(const char a, const char b){
	if(a == '('){
			return true;
	}
	else if(a == 'u'){
		if(b=='('){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a == '+' || a == '-'){
		if(b=='*' || b=='/' || b=='u' || b=='('){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a == '*' || a =='/'){
		if(b=='u' || b=='('){
			return true;
		}
		else{
			return false;
		}
	}
	else if(a == '#'){
		return true;
	}
	else{
		return true;
	}
}


//
// Modify Eval() below to evaluate the given expression
//
double Eval(char* in)
{
	double out = 0;
	
	char buf[1000]; // temp buffer
	char lastToken = '#';
	
	string operand;
	int i = 0, bi = 0;
	
	opt.Push('#');

	std::cout << "What is in input string: " << in << std::endl;

	//space removing
	int j=0;
	while(in[j] != '\0') {
		if(in[j] == ' '){
			if(in[j+1] == '\0'){
				in[j] = '\0';
				continue;
			}
			int numspace = 0;
			while(in[j+numspace] == ' '){
				numspace++;
			}
			int temp;
			int k=j;
			while(in[k+numspace] !='\0'){
					in[k] = in[k+numspace];
					k++;
					temp = k;
			}
			in[temp] = '\0';
		}
		j++;
	}

	std::cout << "Convert input string to non space string: " << in << std::endl;

	Stack<string> postfix;

	i=0;
	


	int endofin = 0;
	while(in[i] != '\0'){		
		char c = in[i];

		// Operators
		if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		{
			if(bi > 0)
			{
				buf[bi++] = '\0';
				operand = buf;			
				bi = 0;
				
				// push operand
				std::cout << "New operand : " << operand << std::endl;
				postfix.Push(operand);

			}

			// push operator
			std::cout << "New operator : " << c << std::endl;
			if(c== '-'){
				if(i == 0 && c == '-'){
					c = 'u';
				}
				else if(i>=1 && in[i-1] == ')'){
					c = '-';
				}
				else if(i>=1 && (in[i-1] == '+')){
					c = 'u';
				}
				else if(i>=1 && (in[i-1] == '-')){
					c = 'u';
				}
				else if(i>=1 && (in[i-1] == '*')){
					c = 'u';
				}
				else if(i>=1 && (in[i-1] == '/')){
					c = 'u';
				}
				else if(i>=1 && (in[i-1] == '(')){
					c = 'u';
				}
				else{
				}
			}

			if(c == ')'){
				string s;
				s += opt.Top();
				if(opt.Top() != '('){
					postfix.Push(s);
					opt.Pop();
				}



				while(opt.Top() != '('){
					string t;
					t += opt.Top();
					postfix.Push(t);
					opt.Pop();
				}

				if(opt.Top() == '('){
					opt.Pop();
				}

			}
			else if(higherICP(opt.Top(), c)){
				opt.Push(c);

			}
			else{
				if(opt.Top() != '#'){
					string s;
					s += opt.Top();
					postfix.Push(s);
					opt.Pop();
				}
				while(!higherICP(opt.Top(), c)){
					if(opt.Top() != '#'){
						string h;
						h += opt.Top();
						postfix.Push(h);
						opt.Pop();
					}
				}

				opt.Push(c);

			}

		}
		// Operands
		else if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.')
		{
			buf[bi++] = c;
		}
		else{}
		i++;

		endofin = i;
	}

	
	// push the very last operand if exists
	if(bi > 0)
	{
		buf[bi++] = '\0';
		operand = buf;
		bi = 0;
		
		// push operand
		std::cout << "New operand : " << operand << std::endl;
		postfix.Push(operand);

	}
		


	if(in[endofin] == '\0'){
		while(opt.Top() != '#'){
			string s;
			s+= opt.Top();
			postfix.Push(s);
			opt.Pop();
		}
		opt.Pop();
	}


	//postfix to calculate
	Stack<string> tempStack;

	while(!(postfix.IsEmpty())){
		tempStack.Push(postfix.Top());
		postfix.Pop();
	}


	while(tempStack.Size() != 0){
		string a;
		a+= tempStack.Top();
		tempStack.Pop();
		if(a == "+"){
			double temp1 = opr.Top();
			opr.Pop();

			double temp2 = opr.Top();
			opr.Pop();

			opr.Push(temp2+temp1);
			
		}
		else if(a == "-"){
			double temp1 = opr.Top();
			opr.Pop();
			double temp2 = opr.Top();
			opr.Pop();

			opr.Push(temp2-temp1);
		}
		else if(a == "*"){
			double temp1 = opr.Top();
			opr.Pop();

			double temp2 = opr.Top();
			opr.Pop();

			opr.Push(temp2*temp1);
		}
		else if(a == "/"){
			double temp1 = opr.Top();
			opr.Pop();

			double temp2 = opr.Top();
			opr.Pop();

			opr.Push(temp2/temp1);
		}
		else if(a == "u"){
			string s;
			s+= opr.Top();
			double temp1 = opr.Top();
			opr.Pop();
			temp1 = temp1 * (-1);
			opr.Push(temp1);
		}
		else{
			double temp = std::stod(a);
			opr.Push(temp);
		}
	}
	
	out = opr.Top();
	
	return out;
}


#endif
