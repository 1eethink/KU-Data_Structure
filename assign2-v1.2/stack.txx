//
// Assignment 2 : Simple calculator using Stack
//
// Array-based stack data structure
//
// COSE213 Fall 2021
//

template<class type>
Stack<type>::~Stack()
{
	// ToDo
	delete [] array;
}

template<class type>
type& Stack<type>::Top()
{
	// ToDo

	if(top==-1){
		throw("Error: Stack is empty.");
	}
	else{
		return array[top];
	}
}

template<class type>
void Stack<type>::Push(const type& item)
{
	// ToDo
	if(top==capacity-1){
		capacity = 2*capacity;
		type *tempArray = new type[capacity];
		for(int i=0;i<=top;i++){
			tempArray[i] = array[i];
		}
		tempArray[top+1] = item;
		top++;
		
		delete [] array;
		array = tempArray;

	}
	else{
		array[top+1] = item;
		top++;
	}
}

template<class type>
void Stack<type>::Pop()
{
	// ToDo

	if(top==-1){
		throw("Error: Stack is empty.");
	}
	else{
		top--;
	}
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	// ToDo	
	if(top!=-1){
		return false;
	}

	return true;
}

