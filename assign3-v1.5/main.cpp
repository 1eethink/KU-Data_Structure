#include "hashmap.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/** 
  * Assignment 3 for COSE213 Data Structures
  *
  * 2021. 11. 1   Won-Ki Jeong
  *
  */
 

HashMap<MapElem<std::string, int>> hm(500);

void spellcheck(std::string s)
{
	std::cout << "> " << s;
	// ToDo	
	if(hm.find(s) != NULL){
		std::cout << " is in the dictionary"  << std::endl;
	}
	else{
		unsigned int len = s.length();
		std::cout << " is NOT in the dictionary"  << std::endl;
		int count = 0;
		std::string suggest;
		suggest = s;
		std::cout << "> " << s << " : ";
		for(int i=0;i<len;i++){
			for(int j=0;j<26;j++){
				suggest[i] = 97+j;
			
				if(hm.find(suggest) != NULL && suggest != s){
					if(count > 0){
					std::cout << ", ";
					}
					count++;
					std::cout << suggest;
				}
			}
			suggest = s;
		}
		if(count == 0){
			std::cout << "no suggestion" << std::endl;
		}
		else{
		std::cout << std::endl;
		}
	}
}



int main()
{
	// load dictionary
	char filename[] = "dictionary.txt";
	std::ifstream ifs(filename, std::ifstream::in);
	std::string s((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	std::string token;
	unsigned int len = s.length();
	


	for(int i=0; i<len; i++)
	{
		int ascii = s[i];
		
		if(ascii < 97 || ascii > 127) 
		{
			if(token.length() > 0) 
			{
				// ToDo
				// Insert token to hash map
				hm.insert(token, 1);
				token.clear();
			}
			continue;
		}
		token.push_back(s[i]);
	}

	//hm.print();

	//
	// infinite loop to accept user input word
	//
	while(1)
	{
		std::string s;
		std::cout << "> ";
		std::cin >> s;
		
		if(s.compare("q") == 0) break;	
		
		spellcheck( s );
	}

	
	return 0;
}