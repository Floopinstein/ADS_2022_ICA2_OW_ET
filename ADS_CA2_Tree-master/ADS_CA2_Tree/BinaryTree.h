#pragma once
#include "TNode.h"
#include <vector>

//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <class K, class E>
class BinaryTree
{
public:
	E* search(K key) {
		return nullptr;
	}

	insert(E data);
	Search(K key);
	Delete(E data, K key);
	Print(E data);


	template <class E>
		BinaryTree<E>::BinaryTree(){
			root = nullptr;
	}

		template <class K, class E>
		void BinaryTree<K, E>::insert(K key, E data){
			if (root == nullptr){
					root = new TNode<K, E>();
					root->setData(data);
			}
			else
			{
				root->insert(data);
			}
		}


};
