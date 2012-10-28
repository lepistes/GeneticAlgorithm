// GenericAlg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert> // for assert function

#include <vector>
#include <list>
#include <deque>

#include <algorithm> // for reverse, sort etc.
#include <numeric>   // for accumulate

using namespace std;

// Find the maximum
template <class T>
const T max1 (const T& x, const T& y){
	return x>y?x:y;
}

// multiply class for accumulate
template <typename T>
class multiple{
public:
	T operator()(const T& x, const T& y) const { return x*y; }
};

// divide class for accumulate
template <typename T>
class divided{
public:
	T operator()(const T& x, const T& y) const { return x/y; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	// USING THE vector CLASS
	cout << "\nusing the vector class" << endl;

	vector<int> myVector(4, 1);
	int bit_shift_no = (1 << 4); // left shift(<<), e.g. x << n == x*2^n
	myVector.push_back(bit_shift_no);

	vector<int>::iterator vec_i;
	for (vec_i = myVector.begin(); vec_i != myVector.end(); vec_i++){
		cout << *vec_i << endl;
	}

	cout << "\nreversed vector (using reverse_iterator):" << endl;
	vector<int>::reverse_iterator rvec_i;
	for (rvec_i = myVector.rbegin(); rvec_i != myVector.rend(); rvec_i++){
		cout << *rvec_i << endl;
	}

	cout << "\n original vector after the reverse ITERATOR:" << endl;
	for (vec_i = myVector.begin(); vec_i != myVector.end(); vec_i++){
		cout << *vec_i << endl;
	}

	cout << "\nreversed vector (using reverse ALGORITHM):" << endl;
	reverse(myVector.begin(), myVector.end());
	for (vec_i = myVector.begin(); vec_i != myVector.end(); vec_i++){
		cout << *vec_i << endl;
	}

	cout << "\noriginal vector after the reverse algorithm:" << endl;
	for (vec_i = myVector.begin(); vec_i != myVector.end(); vec_i++){
		cout << *vec_i << endl;
	}

	cout << "\naccumulate on VECTOR (with a function object)" << endl;
	cout.precision(10);
	int ans = accumulate(myVector.begin(), myVector.end(), (int)1, multiple<int>());
	cout <<  ans << endl; 
	//assert( ans == 2 );

	// USING THE list CLASS
	cout << "\nusing the list class" << endl;

	list<double> myList(4, 3);
	myList.push_back(4);

	list<double>::iterator list_i;

	for (list_i  = myList.begin(); list_i != myList.end(); list_i++){
		cout << *list_i << endl;
	}

	// USING THE list CLASS
	cout << "\nusing the deque class" << endl;

	deque<double> myDeque(4, 5.2);
	myDeque.push_back(.665);

	deque<double>::iterator deque_i;

	for (deque_i  = myDeque.begin(); deque_i != myDeque.end(); deque_i++){
		cout << *deque_i << endl;
	}

	
	// Do not remove the the code below
	cin.get();
	
	return 0;
}


