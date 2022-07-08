//
// - Implementation -
//

// constructor
template <class HashMapElemType>
HashMap<HashMapElemType>::HashMap(unsigned int c) 
{
	// ToDo
	mapsize = 0;
	if(c % 2 == 0){
		capacity = c-1;
		divisor = c-1;
	}
	else{
		capacity = c;
		divisor = c;
	}
	
	ht = new HashMapElemType*[capacity];
	for(int i=0;i<capacity;i++){
		ht[i] = NULL;
	}
	
}

// destructor
template <class HashMapElemType>
HashMap<HashMapElemType>::~HashMap() 
{
	// ToDo
	for(int i=0;i<capacity;i++){
		if(ht[i] != NULL){
			HashMapElemType* temp = ht[i];
			while(temp != NULL){
				HashMapElemType* temp1 = temp;
				temp=temp->link;
				delete temp1;
			}
		}
	}
	delete[] ht;
}

template <class HashMapElemType>
HashMapElemType* 
HashMap<HashMapElemType>::find(const KeyType k) 
{ 
	// ToDo
	HashMapElemType* temp = ht[hashfunction(k)];

	while(temp != NULL){
		if(temp->key==k){
			break;
		}
		else{
			temp=temp->link;
		}
		
	}
	return temp;
	
}

template <class HashMapElemType>
void 
HashMap<HashMapElemType>::insert(const KeyType k, const ValType v) 
{
	// ToDo
	HashMapElemType* pair = new HashMapElemType;
	pair->key = k;
	pair->val = v;
	pair->link = NULL;

	if(find(k) == NULL){ // not exist in current hash map
		if(ht[hashfunction(k)] == NULL){
			mapsize++;
			ht[hashfunction(k)] = pair;
		}
		else{
			HashMapElemType* temp = ht[hashfunction(k)];
			while(temp->link != NULL){
				temp=temp->link;
			}
			mapsize++;
			temp->link=pair;
		}
	}
	else{ // exist in current hash map
		std::cout << "already exist in hash map" << std::endl;
	}
}

template <class HashMapElemType>
bool 
HashMap<HashMapElemType>::remove(const KeyType k) 
{
	 // ToDo
	if(find(k) == NULL){
		return false;
	}
	else{
		HashMapElemType* beforetemp;
		HashMapElemType* temp = ht[hashfunction(k)];
		if(temp->link == NULL){
			ht[hashfunction(k)] = NULL;
			mapsize--;
		}
		else{
			while(temp->key != k){
				beforetemp = temp;
				temp=temp->link;
			}
		
			beforetemp->link = temp->link;
			mapsize--;
			delete temp;
		}
		return true;
	}
	
}

template <class HashMapElemType>
unsigned int 
HashMap<HashMapElemType>::hashfunction(const KeyType k)
{
	// ToDo
	unsigned int temphash = 0;
	unsigned int realhash = 0;
	int i=0;
	while(k[i] != '\0'){
		temphash = temphash + (unsigned int)k[i];
		i++;
	}
	realhash = temphash % divisor;
	return realhash;
}

template <class HashMapElemType>
void 
HashMap<HashMapElemType>::print()
{
	// ToDo
	for(int i=0;i<capacity;i++){
		std::cout << "bucket i : " << i << std::endl;
		HashMapElemType* temp = ht[i];

		if(temp != NULL){
			std::cout << "(key, value) : " <<  "(" << temp->key << ", " << temp->val << ")" << std::endl;
			while(temp->link != NULL){
				temp = temp->link;
				std::cout << "(key, value) : " <<  "(" << temp->key << ", " << temp->val << ")" << std::endl;
			}
		}
		else{
		}
	}

}