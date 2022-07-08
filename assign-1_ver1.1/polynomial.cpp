#include "polynomial.h"
#include <iostream>
#include <math.h>


//
// Implementation
//


// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	// ToDo
	capacity = source.capacity;
	terms = source.terms;
	termArray = new Term[capacity];
	for(int i = 0; i<terms;i++){
			termArray[i] = source.termArray[i];
		}
}	

// Destructor
Polynomial::~Polynomial()
{
	// ToDo
	delete [] termArray;
}


Polynomial& Polynomial::operator = (const Polynomial& source)
{
	// ToDo
	if(this != &source){
		//delete [] termArray; //why double free?
		capacity = source.capacity;
		terms = source.terms;
		termArray = source.termArray;
	}
	return *this;
}



// Sum of *this and source polynomials
Polynomial Polynomial::operator +(const Polynomial& source)
{
	Polynomial c;
	
	// ToDo
	for(int i = 0;i<terms;i++){
		c.CreateTerm(termArray[i].coef, termArray[i].exp);
	}

	for(int i = 0;i<source.terms;i++){
		int temp = 0;
		for(int j=0;j<c.terms;j++){
			if(c.termArray[j].exp == source.termArray[i].exp){
				temp = j;
				break;
			}
		}
		if(temp == 0){
				c.CreateTerm(source.termArray[i].coef, source.termArray[i].exp);
			}
			else{
				c.termArray[temp].coef += source.termArray[i].coef;
			}
	}

	for(int i = 0;i<c.terms;i++){
		int temp=i;
		if(c.termArray[i].coef == 0){
		Term *tempArray = new Term[c.capacity];
			for(int k=0;k<temp;k++){
				tempArray[k] = c.termArray[k];
			}
			for(int k=temp;k<c.terms;k++){
				tempArray[k] = c.termArray[k+1];
			}

		//delete [] c.termArray;
		c.termArray = tempArray;
		
		c.terms--;
		}
	}

	return c;
}

Polynomial Polynomial::operator -(const Polynomial& source)
{
	Polynomial c;

	// ToDo
	for(int i = 0;i<terms;i++){
		c.CreateTerm(termArray[i].coef, termArray[i].exp);
	}

	for(int i = 0;i<source.terms;i++){
		int temp = 0;
		for(int j=0;j<c.terms;j++){
			if(c.termArray[j].exp == source.termArray[i].exp){
				temp = j;
				break;
			}
		}
		if(temp == 0){
				c.CreateTerm(-source.termArray[i].coef, source.termArray[i].exp);
			}
			else{
				c.termArray[temp].coef -= source.termArray[i].coef;
			}
	}

	for(int i = 0;i<c.terms;i++){
		int temp=i;
		if(c.termArray[i].coef == 0){
		Term *tempArray = new Term[c.capacity];
			for(int k=0;k<temp;k++){
				tempArray[k] = c.termArray[k];
			}
			for(int k=temp;k<c.terms;k++){
				tempArray[k] = c.termArray[k+1];
			}

		//delete [] c.termArray;
		c.termArray = tempArray;

		c.terms--;
		}
	}

	return c;
	
}

Polynomial Polynomial::operator * (const Polynomial& source)
{
	Polynomial c;
	
	// ToDo
	for(int i=0;i<terms;i++){
		for(int j=0;j<source.terms;j++){
			int temp = 0;
			float tempcoef;
			int tempexp;
			tempcoef = termArray[i].coef * source.termArray[j].coef;
			tempexp = termArray[i].exp + source.termArray[j].exp;
			for(int k=0;k<c.terms;k++){
				if(c.termArray[k].exp == tempexp){
					temp = k;
					break;
				}
			}
			if(temp != 0){
				c.termArray[temp].coef += tempcoef;
			}
			else{
				c.CreateTerm(tempcoef, tempexp);
			}
		}
	}
	return c;
}

bool Polynomial::operator == (const Polynomial& right)
{
	bool ret;

	// ToDo
	if(terms != right.terms){
		ret = false;
	}
	for(int i=0;i<terms;i++){
		if((termArray[i].coef != right.termArray[i].coef) | (termArray[i].exp != right.termArray[i].exp)){
			ret = false;
			break;
		}
		else{
			ret = true;
		}
	}
	
	return ret;
}

float Polynomial::Eval(float x)
{
	float ret = 0;
	
	// ToDo
	float temp = 0;
	if(terms != 0){
		for(int i=0;i<terms;i++){
			temp = termArray[i].coef * pow(x, termArray[i].exp);
			ret = ret + temp;
		}
	}
	return ret;
}

// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;
	
	// ToDo
	if(terms != 0){
		c.terms = terms;
		c.capacity = capacity;
		c.termArray = new Term[c.capacity];

		for(int i=0;i<terms;i++){
			if(termArray[i].exp == 0){
				c.termArray[i].coef = 0;
				c.termArray[i].exp = 0;
				c.terms = terms - 1;
			}
			else{
				c.termArray[i].coef = termArray[i].coef * termArray[i].exp;
				c.termArray[i].exp = termArray[i].exp - 1;
			}
		}
	}
	
	
	return c;	

}

void Polynomial::CreateTerm(const float coef, const int exp)
{
	// ToDo
if(coef == 0 & exp != 0){
	int temp;
	for(int i =0;i<terms;i++){
		if(termArray[i].exp == exp){
			termArray[i].coef = 0;
			temp=i;
			break;
		}
	}
	
	Term *tempArray = new Term[capacity];

	for(int k=0;k<temp;k++){
		tempArray[k] = termArray[k];
	}
	for(int k=temp;k<terms;k++){
		tempArray[k] = termArray[k+1];
	}
	delete [] termArray;
	termArray = tempArray;
	if(terms ==0){
	terms = 0;
	}
	else{
	terms--;
	}

}
else{
	if(terms==0){
	termArray[0].coef = coef;
	termArray[0].exp = exp;
	terms++;
	}
	else{
		if(terms == capacity){
		//존재하는 항 create하는 경우, 새로운 항 만드는 경우 나누기 (capacity 꽉 찬 경우)
			for(int i=0;i<terms;i++){
				if(termArray[i].exp == exp){
					termArray[i].coef = coef;
					break;
				}
				else if(termArray[i].exp < exp){
					int temp = i;
					Term *tempArray = new Term[capacity+1];
					for(int k=0;k<terms;k++){
						tempArray[k] = termArray[k];
					}
					for(int j = terms-1;j>=temp;j--){
					tempArray[j+1] = tempArray[j];
					}		
					tempArray[temp].coef = coef;
					tempArray[temp].exp = exp;
					
					capacity++;
					terms++;

					delete [] termArray;
					for(int a = 0; a<terms;a++){
						termArray[a] = tempArray[a];
					}
		
					break;
				}
			}
			if(termArray[terms-1].exp>exp){
				Term *tempArray = new Term[capacity+1];
				for(int k=0;k<terms;k++){
						tempArray[k] = termArray[k];
					}
				terms++;
				tempArray[terms-1].coef = coef;
				tempArray[terms-1].exp = exp;
				capacity++;
				delete [] termArray;
				termArray = tempArray;
			
			}
			
		}
		else{
			for(int i=0;i<terms;i++){
				if(termArray[i].exp == exp){
					termArray[i].coef = coef;
					break;
				}
				else if(termArray[i].exp < exp){
					int temp = i;
					for(int j = terms-1;j>=temp;j--){
					termArray[j+1] = termArray[j];
					}		
					termArray[temp].coef = coef;
					termArray[temp].exp = exp;
					terms++;
					break;
				}
			}
			if(termArray[terms-1].exp>exp){
				terms++;
				termArray[terms-1].coef = coef;
				termArray[terms-1].exp = exp;
			}
		}
	}
}
}

