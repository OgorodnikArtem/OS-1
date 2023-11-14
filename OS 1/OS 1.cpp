#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;


class Object {

public:
	int n;
	int* a;
	int t;
	int r;
	Object(int* a_, int n_, int t_) : a(a_), n(n_), t(t_), r(0) {}

};


DWORD WINAPI Worker(LPVOID n)

{
	int count = 0;
	for (int i = 0; i < ((Object*)n)->n; i++) {
		if(((Object*)n)->a[i] % 2 == 1) {
			count++;
		}
		Sleep(((Object*)n)->t * 1000);
	}
	((Object*)n)->r = count;
	return 0;
}

int main()
{
	HANDLE	hThread;
	DWORD	IDThread;

	//int

	int n = 0;
	int t = 0;

	cout << " Quantity numbers = ";

	cin >> n;

	int* a = new int[n];

	cout << " Numbers = ";

	for (int i = 0; i < (int)n; i++) {
		cin >> a[i];
	}

	cout << " Time = ";

	cin >> t;

	auto A = new Object(a, n, t);

	hThread = CreateThread(NULL, 0, Worker, (LPVOID)A, 0, &IDThread);
	if (hThread == NULL)
		return GetLastError();
	
	//hThread = (HANDLE)_beginthreadex(NULL, 0, &Worker, (void*)A , 0, (unsigned int*)&IDThread);

	SuspendThread(hThread);
	ResumeThread(hThread);
	WaitForSingleObject(hThread, INFINITE);
	
		cout << " Result = " << A->r << '\n';
	

	//WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
}