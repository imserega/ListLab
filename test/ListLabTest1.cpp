#include "pch.h"
#include "CppUnitTest.h"
#include "../ListLab/header.h"
#include "../ListLab/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListLabTest1
{
	TEST_CLASS(ListLabTest1)
	{
	public:
		
		TEST_METHOD(PushBackTest1)
		{
			ListOp ls;
			int count = 0;
			int array_checker[] = {5, 10, 22, 7, 11};
			
			ls.push_back(5);
			ls.push_back(10);
			ls.push_back(22);
			ls.push_back(7);
			ls.push_back(11);


			/*
			for (int i = 0; i < TEST_SIZE; ++i) {
				ls.push_back(i);
			}
			*/


			for (int i = 0; i < TEST_SIZE; ++i) {
				if (ls.list_checker(i) == array_checker[i]) {
					++count;
				}
			}
			Assert::AreEqual(TEST_SIZE, count);

		}

		TEST_METHOD(PushFrontTest1)
		{
			ListOp ls;
			int count = 0;
			int array_checker[] = { 7, 22, 5, 10, 11 };

			ls.push_back(5);
			ls.push_back(10);
			ls.push_front(22);
			ls.push_front(7);
			ls.push_back(11);


			for (int i = 0; i < TEST_SIZE; ++i) {
				if (ls.list_checker(i) == array_checker[i]) {
					++count;
				}
			}
			Assert::AreEqual(TEST_SIZE, count);
		}

		TEST_METHOD(PopBackTest1)
		{
			ListOp ls;

			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			ls.push_back(5);
			
			int size_before = ls.get_size();

			ls.pop_back();

			int size_after = ls.get_size();

			Assert::AreNotEqual(ls.at(4), 5);
			
			Assert::AreNotEqual(size_before, size_after);
			
		}

		TEST_METHOD(PopFrontTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			ls.push_back(5);
			ls.pop_front();

			Assert::AreEqual(ls.at(0), 2);



		}

		TEST_METHOD(InsertTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			ls.push_back(5);

			int size_before = ls.get_size();

			ls.insert(55, 2);

			int size_after = ls.get_size();
			Assert::AreEqual(size_before + 1, size_after);
			Assert::AreEqual(ls.at(2), 55);

		}

		TEST_METHOD(RemoveTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			ls.push_back(5);
			
			ls.remove(2);

			Assert::AreEqual(ls.at(1), 2);
			Assert::AreEqual(ls.at(3), 5);
			Assert::AreNotEqual(ls.at(2), 3);


		}

		TEST_METHOD(GetSizeTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			int size = ls.get_size();
			Assert::AreEqual(3, size);
		}

		TEST_METHOD(ClearTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);

			ls.clear();
			Assert::IsTrue(ls.isEmpty());

		}

		TEST_METHOD(IsEmptyTest1)
		{
			ListOp ls;
			Assert::IsTrue(ls.isEmpty());
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			Assert::IsFalse(ls.isEmpty());
		}

		TEST_METHOD(SetTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			ls.push_back(5);

			ls.set(3, 15);
			Assert::AreNotEqual(ls.at(3), 4);
			Assert::AreEqual(ls.at(3),15);

		}

		TEST_METHOD(AtTest1)
		{
			ListOp ls;
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);

			Assert::AreEqual(ls.at(2), 3);
		}
		TEST_METHOD(ContainsTest1) 
		{
			ListOp ls;
			ListOp lst;
			ListOp lst2;
			
			ls.push_back(1);
			ls.push_back(2);
			ls.push_back(3);
			ls.push_back(4);
			
			lst.push_back(1);
			lst.push_back(23);
			lst.push_back(0);

			lst2.push_back(24);
			lst2.push_back(25);
			lst2.push_back(26);

			Assert::IsTrue(ls.contains(lst));
			Assert::IsFalse(ls.contains(lst2));
		}
	};
}
