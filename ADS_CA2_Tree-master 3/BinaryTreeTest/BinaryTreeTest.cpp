#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		
        TEST_METHOD(TestTreeAddToNull)
        {
            BinaryTree<int, int> tree;
            tree.add(4, 3);
            Assert::IsNotNull(tree.root);
            Assert::AreEqual(3, tree.root->getData());
        }

        TEST_METHOD(TestTreeAddToLeft)
        {
            BinaryTree<int, int> tree;
            tree.add(4, 2);
            tree.add(5, 1);
            Assert::IsNotNull(tree.root);
            Assert::AreEqual(2, tree.root->getData());
            TNode<int, int>* left = tree.root->getLeft();
            Assert::IsNotNull(left);
            Assert::AreEqual(1, left->getData());

            cout << tree.root->getData();
        }

        TEST_METHOD(TestTreeAddToRight)
        {
            BinaryTree<int, int> tree;
            tree.add(2, 2);
            tree.add(3, 3);
            Assert::IsNotNull(tree.root);
            Assert::AreEqual(2, tree.root->getData());
            TNode<int, int>* pRight = tree.root->getRight();
            Assert::IsNotNull(pRight);
            Assert::AreEqual(3, pRight->getData());
        }


        TEST_METHOD(TestRemoveNullData)
        {
            BinaryTree<int, int> tree;
            tree.add(4, 4);
            tree.add(2, 2);
            tree.add(6, 6);
            tree.add(1, 1);
            tree.add(3, 3);
            tree.add(5, 5);
            tree.add(7, 7);
            Assert::AreEqual(7, tree.count());
            tree.Delete(8, 8);
            Assert::AreEqual(7, tree.count());
            Assert::AreEqual(4, tree.root->getData());
            Assert::AreEqual(2, tree.root->getLeft()->getData());
            Assert::AreEqual(6, tree.root->getRight()->getData());
            TNode<int, int>* left = tree.root->getLeft();
            TNode<int, int>* right = tree.root->getRight();
            Assert::AreEqual(1, left->getLeft()->getData());
            Assert::AreEqual(3, left->getRight()->getData());
            Assert::AreEqual(5, right->getLeft()->getData());
            Assert::AreEqual(7, right->getRight()->getData());

        }


        TEST_METHOD(TestCountOnFullTree)
        {
            BinaryTree<int, int> tree;
            tree.add(4, 4);
            tree.add(2, 2);
            tree.add(6, 6);
            tree.add(1, 1);
            tree.add(3, 3);
            tree.add(5, 5);
            tree.add(7, 7);

            Assert::AreEqual(7, tree.count());
        }

		TEST_METHOD(TestRemoveLeafNode)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			Assert::AreEqual(7, tree.count());
			tree.Delete(5, 5);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getData());
			Assert::AreEqual(2, tree.root->getLeft()->getData());
			Assert::AreEqual(6, tree.root->getRight()->getData());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getData());
			Assert::AreEqual(3, left->getRight()->getData());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getData());
		}

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(8, 8);
			Assert::AreEqual(7, tree.count());
			tree.Delete(7, 7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getData());
			Assert::AreEqual(2, tree.root->getLeft()->getData());
			Assert::AreEqual(6, tree.root->getRight()->getData());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getData());
			Assert::AreEqual(5, right->getLeft()->getData());
			Assert::AreEqual(8, right->getRight()->getData());
		}

		//Test failing after removing (2, 2) saying that it still has 7 nodes, cant figure out, works on other tests
		TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			  BinaryTree<int, int> tree;
            tree.add(4, 4);
            tree.add(2, 2);
            tree.add(6, 6);
            tree.add(1, 1);
            tree.add(3, 3);
            tree.add(5, 5);
            tree.add(7, 7);
            Assert::AreEqual(7, tree.count());
            tree.Delete(2, 2);
            Assert::AreEqual(6, tree.count());
            Assert::AreEqual(4, tree.root->getData());
            Assert::AreEqual(3, tree.root->getLeft()->getData());
            Assert::AreEqual(6, tree.root->getRight()->getData());
            TNode<int, int> * pleft = tree.root->getLeft();
            TNode<int, int> * pright = tree.root->getRight();
            Assert::AreEqual(1, pleft->getLeft()->getData());
            Assert::IsNull(pleft->getRight());
            Assert::AreEqual(5, pright->getLeft()->getData());
            Assert::AreEqual(7, pright->getRight()->getData());
		}

		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			BinaryTree<int, int> tree;
			tree.add(8, 8);
			tree.add(4, 4);
			tree.add(12, 12);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(10, 10);
			tree.add(14, 14);
			tree.add(9, 9);
			tree.add(11, 11);
			tree.add(13, 13);
			tree.add(15, 15);
			Assert::AreEqual(15, tree.count());

			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getData());
			tree.Delete(12, 12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getData());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
		}




		TEST_METHOD(SearchTestTrue)
		{
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			Assert::IsTrue(tree.Search(6));
		}

		TEST_METHOD(SearchTestFalse)
		{
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			Assert::IsFalse(tree.Search(4));
		}

	};
}
