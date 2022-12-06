#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTests
{
	TEST_CLASS(NodeTests)
	{
	public:


		//Testing constructor
		TEST_METHOD(TestMethodConstruct)
		{

			TNode<int, int> node(4, 2);
			Assert::AreEqual(4, node.getKey());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());

		}
		
		//Testing Add Function//
		
			//Testing for when new data is Equal
		TEST_METHOD(TestMethodEqual)
		{
			TNode<int, int> node(5, 5);
			Assert::AreEqual(5, node.getData());
			Assert::IsNull(node.getLeft());
			node.add(5, 6);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getData());
		}
		

			//Testing for when new data is less than
		TEST_METHOD(TestMethodLessThan)
		{
			TNode<int, int> node(4, 4);
			Assert::AreEqual(4, node.getData());
			Assert::IsNull(node.getLeft());
			node.add(3, 1);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(1, node.getLeft()->getData());

		}

			//Testing for when new data is greater than
		TEST_METHOD(TestMethodGreaterThan)
		{
			TNode<int, int> node(4, 4);
			Assert::AreEqual(4, node.getData());
			Assert::IsNull(node.getRight());
			node.add(6, 6);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getData());

		}
		
		TEST_METHOD(TestAddGreaterThanChildren)
		{
			TNode<int, int> node(4, 4);
			node.add(7, 7);
			TNode<int, int>* pRight = node.getRight();
			node.add(5, 5);
			node.add(9, 9);
			Assert::IsNotNull(pRight->getLeft());
			Assert::AreEqual(7, pRight->getData());
			Assert::IsNotNull(pRight->getRight());
			Assert::AreEqual(9, pRight->getRight()->getData());

		}
		
		TEST_METHOD(TestAddLessThanChildren)
		{
			TNode<int, int> node(6, 6);
			node.add(3, 3);
			TNode<int, int>* pLeft = node.getLeft();
			node.add(1, 1);
			node.add(4, 4);
			Assert::IsNotNull(pLeft->getLeft());
			Assert::AreEqual(4, pLeft->getRight()->getData());
			Assert::IsNotNull(pLeft->getLeft());
			Assert::AreEqual(1, pLeft->getLeft()->getData());

		}



		TEST_METHOD(TestCount)
		{
			TNode<int, int> node(9, 9);
			
			node.add(8, 8);
			node.add(7, 7);
			node.add(6, 6);
			node.add(18, 18);
			node.add(4, 4);



			Assert::AreEqual(6, node.count());


		}

	};
}
