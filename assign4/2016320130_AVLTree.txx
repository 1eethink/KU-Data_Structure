//
// Implementation
//
template <typename E>					// constructor
  AVLTree<E>::AVLTree() : ST() { }

template <typename E>					// node height utility
  int AVLTree<E>::height(const TPos& v) const
    { return (v.isExternal() ? 0 : (*v).height()); }

template <typename E>					// set height utility
  void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));			// max of left & right
  }

template <typename E>					// is v balanced?
  bool AVLTree<E>::isBalanced(const TPos& v) const {	
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
  }

template <typename E>					// get tallest grandchild
  typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))			// left child taller
      if (height(zl.left()) >= height(zl.right()))
        return zl.left();
      else
        return zl.right();
    else 						// right child taller
      if (height(zr.right()) >= height(zr.left()))
        return zr.right();
      else
        return zr.left();
  }


//
// ToDo
//

template <typename E>					// remove key k entry
  void AVLTree<E>::erase(const K& k) {
    
    // ToDo
	TPos v = ST::finder(k, ST::root());
	if(Iterator(v) == ST::end()){
		throw "Erase of nonexistent";
	}
	TPos w = ST::eraser(v);
	rebalance(w);
    
  }

template <typename E>					// insert (k,x)
  typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    
    // ToDo
	TPos v = ST::inserter(k,x);
	setHeight(v);

	rebalance(v);

	return Iterator(v);
    
  }
  
template <typename E>					// rebalancing utility
  void AVLTree<E>::rebalance(const TPos& v) {
    
    // ToDo
	TPos z = v;
	int i=0;
	while(!(z == ST::root())){
		//std::cout << "what is in the root : " << i <<"..."<< (*ST::root()).key() << " , " << (*ST::root()).value() << std::endl;
		//std::cout << "what is in z: " << (*z).key() << " , "<< (*z).value() << std::endl;
		z = z.parent();
		//std::cout << "what is in z's parent: " << (*z).key() << " , "<< (*z).value() << std::endl;
		i=i+1;
		//std::cout << "what is bal of i : " << i <<"..."<< z.v->left->elt.height() - z.v->right->elt.height() << std::endl;
		
		setHeight(z);
		if(!isBalanced(z)){
			TPos x = tallGrandchild(z);
			//std::cout << "what is x: " << (*x).key() << " , "<< (*x).value() << std::endl;
			z = restructure(x);
			//std::cout << "------" << std::endl;
			setHeight(z.left());
			setHeight(z.right());
			setHeight(z);
		}
		//z = z.parent();
	}
    
  }

template <typename E>				// Binary Search Tree Rotation
  typename AVLTree<E>::TPos AVLTree<E>::restructure(const TPos& v) {

	// ToDo

	//Node* w = p.v;
	//ST::TPos::Node();
	//TPos temp = TPos->Node((*v),v.parent(),v.left(), v.right());

	TPos temp = v.parent().parent(); // grandparent of v
	//std::cout << "what is temp: " << (*temp).key() << " , "<< (*temp).value() << std::endl;
	//std::cout << "what is v: " << (*v).key() << " , "<< (*v).value() << std::endl;


	if(temp.left().left() == v){	// LL = right rotation
		
		TPos temp1 = temp.left();

		temp1.right().v->par = temp.v;
		temp.v->left = temp1.right().v;
		
		temp1.v->right = temp.v;
		temp1.v->par = temp.parent().v;

		if(temp1.parent().v->right == temp.v){
			temp1.parent().v->right = temp1.v;
		}
		else{
			temp1.parent().v->left = temp1.v;
		}

		temp.v->par = temp1.v;

		return temp1;
	}
	else if(temp.right().right() == v){	// RR = left rotation

		TPos temp1 = temp.right();
		
		temp1.left().v->par = temp.v;
		temp.v->right = temp1.left().v;
		
		temp1.v->left = temp.v;
		temp1.v->par = temp.parent().v;
		
		if(temp1.parent().v->right == temp.v){
			temp1.parent().v->right = temp1.v;
		}
		else{
			temp1.parent().v->left = temp1.v;
		}
		temp.v->par = temp1.v;
	
	
		return temp1;
	}
	else if(temp.right().left() == v){	// RL = right, left rotation
		TPos star = v;
		TPos star1 = v.left();
		TPos star2 = v.right();

		temp.right().v->left = star2.v;
		star2.v->par = temp.right().v;

		star.v->par = temp.v;
		temp.right().v->par = star.v;// changed
		star.v->right = temp.right().v;
		temp.v->right = star.v;	// R

		star1.v->par = temp.v;
		temp.v->right = star1.v;

		star.v->left = temp.v;
		star.v->par = temp.parent().v;
		if(temp.parent().v->right == temp.v){
			temp.parent().v->right = star.v;
		}
		else{
			temp.parent().v->left = star.v;
		}
		temp.v->par = star.v; // L

		return star;
		
	}
	else if(temp.left().right() == v){	// LR = left, right rotation
		TPos star = v;
		TPos star1 = v.left();
		TPos star2 = v.right();

		temp.left().v->right = star1.v;
		star1.v->par = temp.left().v;
		
		star.v->par = temp.v;
		temp.left().v->par = star.v;// changed
		star.v->left = temp.left().v;
		temp.v->left = star.v; 	// L

		star2.v->par = temp.v;
		temp.v->left = star2.v;

		star.v->right = temp.v;
		star.v->par = temp.parent().v;
		if(temp.parent().v->right == temp.v){
			temp.parent().v->right = star.v;
		}
		else{
			temp.parent().v->left = star.v;
		}
		temp.v->par = star.v; //  R
		
		return star;
	}
	else{
		//std::cout << "what is temp in here: " << (*temp).key() << " , "<< (*temp).value() << std::endl;
		std::cout << "Error : grand child is different" << std::endl;

		//throw("grand child is different");
	}

  }

