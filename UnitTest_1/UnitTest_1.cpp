#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include "../OS 1/OS 1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int expectedCount = 3;

			int testArray[] = { 1, 2, 3 ,4 , 5};
			int testSize = sizeof(testArray) / sizeof(testArray[0]);

			auto A = new Object(testArray, testSize, 1);

			DWORD IDThread;
			HANDLE hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
			if (hThread == NULL)
			{
				Assert::Fail(L"Failed to create thread");
			}

			Sleep(2000);

			ResumeThread(hThread);
			WaitForSingleObject(hThread, INFINITE);

			Assert::AreEqual(expectedCount, A->r);

			CloseHandle(hThread);
			delete A;
		}

		TEST_METHOD(TestMethod2)
		{
			int expectedCount = 4;

			int testArray[] = { 1, 2, 3 , 5 , 9 };
			int testSize = sizeof(testArray) / sizeof(testArray[0]);

			auto A = new Object(testArray, testSize, 1);

			DWORD IDThread;
			HANDLE hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
			if (hThread == NULL)
			{
				Assert::Fail(L"Failed to create thread");
			}

			Sleep(2000);

			ResumeThread(hThread);
			WaitForSingleObject(hThread, INFINITE);

			Assert::AreEqual(expectedCount, A->r);

			CloseHandle(hThread);
			delete A;
		}


		TEST_METHOD(TestMethod3)
		{
			int expectedCount = 3;

			int testArray[] = { 5, 5, 5 };
			int testSize = sizeof(testArray) / sizeof(testArray[0]);

			auto A = new Object(testArray, testSize, 1);

			DWORD IDThread;
			HANDLE hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
			if (hThread == NULL)
			{
				Assert::Fail(L"Failed to create thread");
			}

			Sleep(2000);

			ResumeThread(hThread);
			WaitForSingleObject(hThread, INFINITE);

			Assert::AreEqual(expectedCount, A->r);

			CloseHandle(hThread);
			delete A;
		}


		TEST_METHOD(TestMethod4)
		{
			int expectedCount = 5;

			int testArray[] = { 5, 5, 5 , 5 , 5 };
			int testSize = sizeof(testArray) / sizeof(testArray[0]);

			auto A = new Object(testArray, testSize, 1);

			DWORD IDThread;
			HANDLE hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
			if (hThread == NULL)
			{
				Assert::Fail(L"Failed to create thread");
			}

			Sleep(2000);

			ResumeThread(hThread);
			WaitForSingleObject(hThread, INFINITE);

			Assert::AreEqual(expectedCount, A->r);

			CloseHandle(hThread);
			delete A;
		}


		TEST_METHOD(TestMethod5)
		{
			int expectedCount = 2;

			int testArray[] = { 1, 2, 3 };
			int testSize = sizeof(testArray) / sizeof(testArray[0]);

			auto A = new Object(testArray, testSize, 1);

			DWORD IDThread;
			HANDLE hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
			if (hThread == NULL)
			{
				Assert::Fail(L"Failed to create thread");
			}

			Sleep(2000);

			ResumeThread(hThread);
			WaitForSingleObject(hThread, INFINITE);

			Assert::AreEqual(expectedCount, A->r);

			CloseHandle(hThread);
			delete A;
		}
	};
}