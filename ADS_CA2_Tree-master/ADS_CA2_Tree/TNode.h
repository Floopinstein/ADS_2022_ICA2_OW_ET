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
	TNode(K key, E value)
	{
		this->key = key;
		this->data = value;
	}
	
	template <typename E, typename K>
	void insert(K key, E data) {

		//if key is smaller than current Node data
		if (key < this->key)
		{
			//if left node doesnt exist
			if (this->pLeft == nullptr)
			{
				//create new node for data
				this->pLeft = new TNode(key, data);
			}
			else
			{
				//else inset the data into Left node
				this->pLeft->insert(key, data);
			}

			//if data is bigger then current Node data
			if (key > this->key) {

				//if right node doesnt exist
				if (this pright-> == nullptr) {
					//create new node for data
					this->pRight = new TNode(key, data);
				}
				else {
					//else insert the data into right node
					this->pRight->insert(key, data)
				}
				return false;

			}

			template <class E>
			void TNode<E>::setData(E data){this->data = data;}
			E getData() const { return this->data; }
		}
	}

		
	
	void Search(K key, E data) {

		

	}


		
	void Delete(K key, E data) {

		delete this->data;
	
	}


	void Print(K key, E data) {



	}
	



};

