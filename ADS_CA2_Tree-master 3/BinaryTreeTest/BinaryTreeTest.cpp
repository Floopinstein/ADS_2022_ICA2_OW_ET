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

	};
}
