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

	bool insert(K key, E data) {
		if (key < this->key)
		{
			if (this->pLeft == nullptr)
			{
				this->pLeft = new TNode(key, data);
			}
			else
			{
				this->pLeft->insert(key, data);
			}
		}
		return false;
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }
};
