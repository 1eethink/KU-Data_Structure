/** 
  * Assignment 4 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 11. 21
  *
  */
  
#include "LinkedBinaryTree.h"
#include "SearchTree.h" 
#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#include <iostream>
 
using namespace std;

int main()
{
	typedef Entry<int, float> EntryType;

	//LinkedBinaryTree<EntryType> t;
	
	//std::cout << "Size : " << t.size() << std::endl;
	
	//t.addRoot();
	
	//std::cout << "Size : " << t.size() << std::endl;
	
	
	//
	//
	//
	SearchTree<EntryType>	st;
	std::cout << "---Let's test given skeleton code---" << std::endl;
	std::cout << "Initial Size : " << st.size() << std::endl;
	st.insert(1, 2.5);
	st.insert(3, 4.5);
	st.insert(7, 5.5);
	st.insert(2, 1.5);
	std::cout << "Size before insert same key 3 : " << st.size() << std::endl;
	st.insert(3, 8.5);
	std::cout << "Size after insert same key 3 : " << st.size() << std::endl;
	std::cout << "Size is same" << std::endl;
	std::cout << std::endl;

	std::cout << "Tree has below entries"<<std::endl;
	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << "Key : " <<(*it).key() << ", " << "Value : " << (*it).value() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Size before erase key 3 : " << st.size() << std::endl;
	st.erase(3);
	std::cout << "Size after erase key 3 : " << st.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Tree has below entries"<<std::endl;
	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}	
	
	std::cout << "---Given skeleton code works well, let's start experiment---" << std::endl;
	






int nElem = 1; 	// test from 100 to 1000000

clock_t tm;

// skewed data set
for(int iter=0;iter<5;iter++){


	//making test set

	nElem = nElem*10;

	std::cout << std::endl;
	std::cout << "Test for the size of " << nElem<< std::endl;
	std::cout << std::endl;

	int *key = new int[nElem];
	//int *randomkey = new int[nElem];
	float *val = new float[nElem];

	std::srand(std::time(0)); // use current time as seed for random generator

	// initialize
	for(int i=0; i<nElem; i++)
	{
		key[i] = i+1; //  for skewed key
		//randomkey[i] = std::rand()%nElem+1; // for random key
		val[i] = (float) std::rand()/RAND_MAX * 20000; //value is not important
	}
	   
	SearchTree<EntryType>	skewedst;
		// SearchTree skewed test
	// insert
	

 	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		skewedst.insert(key[i], val[i]);
	}
	tm = clock() - tm;
	printf ("Insert SearchTree by using skewed data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

	// find
	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		skewedst.find(key[i]);
	}
	tm = clock() - tm;
	printf ("Find SearchTree by using skewed data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

			// AVLTree skewed test
	AVLTree<EntryType>	skewedavl;
		// insert
 	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		skewedavl.insert(key[i], val[i]);
	}
	tm = clock() - tm;
	printf ("Insert AVLTree by using skewed data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

		// find
	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		skewedavl.find(key[i]);
	}
	tm = clock() - tm;
	printf ("Find AVL tree by using skewed data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

}


// random data set
nElem = 1;
for(int iter=0;iter<6;iter++){
	nElem = nElem*10;

	std::cout << std::endl;
	std::cout << "Test for the size of " << nElem<< std::endl;
	std::cout << std::endl;

	//int *key = new int[nElem];
	int *randomkey = new int[nElem];
	float *val = new float[nElem];

	std::srand(std::time(0)); // use current time as seed for random generator

	// initialize
	for(int i=0; i<nElem; i++)
	{
		//key[i] = i+1; //  for skewed key
		randomkey[i] = i+1;// std::rand()%nElem+1; // for random key
		
		val[i] = (float) std::rand()/RAND_MAX * 20000; //value is not important
	}
	
	for(int i=0; i<nElem; i++){
		int swap1 = std::rand()%nElem;
		int swap2 = std::rand()%nElem;
		//std::cout << swap1 << swap2 << std::endl;
		if(swap1 != swap2){
			int temp;
			temp = randomkey[swap1];
			randomkey[swap1] = randomkey[swap2];
			randomkey[swap2] = randomkey[swap1];
		}
	}
	
	

	SearchTree<EntryType>	randomst;
		// SearchTree random test
	// insert

 	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		randomst.insert(randomkey[i], val[i]);
	}
	tm = clock() - tm;
	printf ("Insert SearchTree by using random data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

	// find
	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		randomst.find(randomkey[i]);
	}
	tm = clock() - tm;
	printf ("Find SearchTree by using random data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);


		// AVLTree random test
	AVLTree<EntryType>	randomavl;
	// insert
 	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		randomavl.insert(randomkey[i], val[i]);
	}
	tm = clock() - tm;
	printf ("Insert AVLTree by using random data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

		// find
	tm = clock();

	for(int i=0; i<nElem; i++)
	{
		randomavl.find(randomkey[i]);
	}
	tm = clock() - tm;
	printf ("Find AVLTree by using random data set\n");
	printf ("It took me %f seconds.\n",((float)tm)/(float)CLOCKS_PER_SEC);

}



		
	return 0;
	
}