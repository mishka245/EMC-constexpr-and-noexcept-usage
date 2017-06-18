#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<chrono>
#include"Header.h"


using namespace std;
using namespace chrono;

int fo(int a)
{
	if (a == 1) return 1;
	return a+ fo(a - 1);

}

// native function
// time in microsecconds: 2957112
int main()
{
	int  m = 111;
	int t = 0;
	
	steady_clock::time_point begin = steady_clock::now();
	for (int i = 0; i < 1000000; ++i)
	{
			t = fo(m);
		
	}
	steady_clock::time_point end = steady_clock::now();
	cout << "microsecconds  = " << duration_cast<microseconds>(end - begin).count()<< endl;
	//cout << "difference in nanosecconds = " <<  duration_cast<nanoseconds> (end - begin).count() << endl;
	cin >> t;
	return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

constexpr int fo(int a)
{
	if (a == 1) return 1;
	return a+ fo(a - 1);

}

// constexpr function
// time in microsecconds: 2883095
int main()
{
	constexpr int  m = 111;
	int t = 0;
	
	steady_clock::time_point begin = steady_clock::now();
	for (int i = 0; i < 1000000; ++i)
	{
			t = fo(m);
		
	}
	steady_clock::time_point end = steady_clock::now();
	cout << "microsecconds  = " << duration_cast<microseconds>(end - begin).count()<< endl;
	//cout << "difference in nanosecconds = " <<  duration_cast<nanoseconds> (end - begin).count() << endl;
	cin >> t;
	return 0;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int fo(int a)noexcept
{
	if (a == 1) return 1;
	return a+ fo(a - 1);

}

// noexcept function
// time in microsecconds: 2852256
int main()
{
	 int  m = 111;
	int t = 0;
	
	steady_clock::time_point begin = steady_clock::now();
	for (int i = 0; i < 1000000; ++i)
	{
			t = fo(m);
		
	}
	steady_clock::time_point end = steady_clock::now();
	cout << "microsecconds  = " << duration_cast<microseconds>(end - begin).count()<< endl;
	//cout << "difference in nanosecconds = " <<  duration_cast<nanoseconds> (end - begin).count() << endl;
	cin >> t;
	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 constexpr int fo(int a)noexcept
{
	if (a == 1) return 1;
	return a+ fo(a - 1);

}

// noexcept constexpr function
// time in microsecconds: 2839266
int main()
{
	constexpr int  m = 111;
	int t = 0;
	
	steady_clock::time_point begin = steady_clock::now();
	for (int i = 0; i < 1000000; ++i)
	{
			t = fo(m);
		
	}
	steady_clock::time_point end = steady_clock::now();
	cout << "microsecconds  = " << duration_cast<microseconds>(end - begin).count()<< endl;
	//cout << "difference in nanosecconds = " <<  duration_cast<nanoseconds> (end - begin).count() << endl;
	cin >> t;
	return 0;

}
