#pragma once

template <typename K, typename E>
class TNode {
private:
	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E data;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight;

public:
	K getKey();
	E getData();
	TNode();
	TNode(K, E);
	void setItem(K keyItem, E Item);
	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();
	void setLeft(TNode<K, E>* l);
	void setRight(TNode<K, E>* r);
	void add(K keyItem, E Item);
	int count();
	~TNode();



};




//get key function
template <typename K, typename E>
K TNode<K, E>::getKey()
{
	return this->key;
}

//get data function
template <typename K, typename E>
E TNode<K, E>::getData()
{
	return this->data;
}

//setting pRight and pLeft to null pointers
template <typename K, typename E>
TNode<K, E>::TNode()
{
	pLeft = nullptr;
	pRight = nullptr;
};


template <typename K, typename E>
TNode<typename K, typename E>::TNode(K key, E data)
{
	pLeft = nullptr;
	pRight = nullptr;
	this->data = data;
	this->key = key;
}






//creating the set item function
template <typename K, typename E>
void TNode<K, E>::setItem(K keyItem, E item)
{
	this->data = item;
	this->key = keyItem;
}





//Get left function
template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getLeft()
{
	return this->pLeft;
}
//Get right function
template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getRight()
{
	return this->pRight;
}


//Set left function
template <typename K, typename E>
void TNode<K, E>::setLeft(TNode<K, E>* l)
{
	this->pLeft = l;
}
//Set right function
template <typename K, typename E>
void TNode<K, E>::setRight(TNode<K, E>* r)
{
	this->pRight = r;
}




//creating the add function
template <typename K, typename E>
void TNode<K, E>::add(K keyItem, E dataItem) {

	//When both data and key are equal do nothing
	if (dataItem == this->data && keyItem == this->key) {
		return;
	}

	//When data is equal but key is less than
	else if (dataItem == this->data && keyItem < this->key) {

		if (pLeft == nullptr) {
			pLeft = new TNode<K, E>();
			pLeft->data = dataItem, keyItem;
		}
		else {
			pLeft->add(dataItem, keyItem);
		}
	}

	//When data is equal but key is greater than
	else if (dataItem == this->data && keyItem > this->key) {
		
		if (pRight == nullptr) {
			pRight = new TNode<K, E>();
			pRight->data = dataItem;
			pRight->key = keyItem;
		}
		else {
			pRight->add(dataItem, keyItem);
		}
	}

	//When data is less than but key is equal to 
	else if (dataItem < this->data && keyItem == this->key) {
		
		if (pLeft == nullptr) {
			pLeft = new TNode<K, E>();
			pLeft->data = dataItem;
			pLeft->key = keyItem;
		}
		else {
			pLeft->add(dataItem, keyItem);
		}
	}

	//When data is less than but key is greater to 
	else if (dataItem < this->data && keyItem > this->key) {

		if (pLeft == nullptr) {
			pLeft = new TNode<K, E>();
			pLeft->data = dataItem;
			pLeft->key = keyItem;
		}
		else {
			pLeft->add(dataItem, keyItem);
		}
	}

	//When data is less than and key is less than
	else if (dataItem < this->data && keyItem < this->key) {

		if (pLeft == nullptr) {
			pLeft = new TNode<K, E>();
			pLeft->data = dataItem;
			pLeft->key = keyItem;
		}
		else {
			pLeft->add(dataItem, keyItem);
		}
	}

	//When data is greater than but key is equal to
	else if (dataItem > this->data && keyItem == this->key) {

		if (pRight == nullptr) {
			pRight = new TNode<K, E>();
			pRight->data = dataItem;
			pRight->key = keyItem;
		}
		else {
			pRight->add(dataItem, keyItem);
		}
	}

	//When data is greater than and key is greater than
	else if (dataItem > this->data && keyItem > this->key) {

		if (pRight == nullptr) {
			pRight = new TNode<K, E>();
			pRight->data = dataItem;
			pRight->key = keyItem;
		}
		else {
			pRight->add(dataItem, keyItem);
		}
	}

	//When data is greater than but key is less than
	else if (dataItem > this->data && keyItem < this->key) {

		if (pRight == nullptr) {
			pRight = new TNode<K, E>();
			pRight->data = dataItem;
			pRight->key = keyItem;
		}
		else {
			pRight->add(dataItem, keyItem);
		}
	}
}


//Count Function
template <typename K, typename E>
int TNode<K, E>::count()
{
	int c = 1;
	if (pLeft != nullptr)
	{
		c += pLeft->count();
	}
	if (pRight != nullptr)
	{
		c += pRight->count();
	}
	return c;
}

template <typename K, typename E>
TNode<K, E>::~TNode(){

	delete pLeft;
	delete pRight;
}


