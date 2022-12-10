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
		
		//Testing adding to an empty tree
        TEST_METHOD(TestTreeAddToNull)
        {
            BinaryTree<int, int> tree;
            tree.add(4, 3);

            Assert::IsNotNull(tree.root);
            Assert::AreEqual(3, tree.root->getData());
        }

		//Adding a smaller number
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


		//Adding a bigger number
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

		//Removing data that isnt in the tree
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
         
        }

		//Testing count function paired with add
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

		//Deleting a node with no children
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
	
		}

		//Deleting a node with one child
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
			Assert::AreEqual(8, tree.root->getRight()->getRight()->getData());
		}

		//Deleting a node with two children
		//Test failing after removing (2, 2) saying that it still has 7 nodes, cant figure out, works on other tests (also worked a few times before)
		//further testing shows the (2, 2) node just isn't deleting
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
            Assert::AreEqual(6, tree.count());
            tree.Delete(2, 2);
            Assert::AreEqual(6, tree.count());
            Assert::AreEqual(3, tree.root->getLeft()->getData());

		}
			

		//Deleting a node with children that have children
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

		//Testing print in order function
		TEST_METHOD(PrintInOrderTest)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.PrintInOrder(tree.root);

		}

		//Testing print preorder function

		TEST_METHOD(PrintPreOrderTest)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.PrintPreOrder(tree.root);

		}

		//Testing print postorder function
		TEST_METHOD(PrintPostOrderTest)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.PrintPostOrder(tree.root);

		}

		//Testing Search function (both left and right)
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
			
			Assert::AreEqual(3, tree.root->getData());
			Assert::AreEqual(9, tree.root->getRight()->getData());
			Assert::AreEqual(5, tree.root->getRight()->getLeft()->getData());
			Assert::AreEqual(6, tree.root->getRight()->getLeft()->getRight()->getData());
			Assert::AreEqual(8, tree.root->getRight()->getLeft()->getRight()->getRight()->getData());
			Assert::AreEqual(2, tree.root->getLeft()->getData());

			Assert::IsTrue(tree.Search(8));
			Assert::IsTrue(tree.Search(1));


		}

		//Searching for data not in the tree
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

		//Searching for deleted data
		TEST_METHOD(SearchTestDelete)
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
			tree.Delete(6, 6);
			Assert::IsFalse(tree.Search(6));

		}

		//Testing Depth function
		TEST_METHOD(TestDepth)
		{
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			tree.add(10, 10);

			Assert::AreEqual(4, tree.Depth(8));
			Assert::AreEqual(2, tree.Depth(10));

		}
		
		//Testing Depth with delete function
		TEST_METHOD(TestDepthDelete)
		{
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			tree.add(10, 10);

			Assert::AreEqual(4, tree.Depth(8));
			tree.Delete(6, 6);
			Assert::AreEqual(3, tree.Depth(8));

		}

		//Function doesn't work properly its programmed to make it to the end of the tree but can't tell if its the longest path or not
		TEST_METHOD(TestHeight)
		{
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			tree.add(10, 10);

			Assert::AreEqual(5, tree.Height());
		}

		//Subtree Test (broke)

	/*	TEST_METHOD(TestSubTree)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.SubTree(tree.root);
		}*/

		//Balance Test (broke)

	/*	TEST_METHOD(TestBalance)
		{

			int array1[];

			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(9, 9);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(6, 6);
			tree.add(8, 8);
			tree.add(10, 10);

			BalancedTree(tree, 0, 8, array1[]);{

			tree.Balance();
		}*/


	};

};
