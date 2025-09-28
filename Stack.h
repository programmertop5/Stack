#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
	T* ptr;
	int maxSize;
	int current;
public:
	Stack(int size = 200);
	Stack(const Stack<T>& other);
	~Stack();
	Stack<T>& operator=(const Stack<T>& other) = delete;


	void add();
	void print();

	void push(const T& value);


	void pop();

	T& top();

	bool empty() const;

	int size() const;
};

template<typename T>
Stack<T>::Stack(int size) : maxSize(size)
{
	ptr = new T[maxSize];
	current = -1;
}

template<class T>
inline Stack<T>::Stack(const Stack<T>& other) :maxSize(other.maxSize)
{
	ptr = new T[other.maxSize];
	current = other.current;

	for (int i = 0;i <= current;i++) {
		ptr[i] = other.ptr[i];
	}
}

template<class T>
inline Stack<T>::~Stack()
{
	delete[] ptr;
}


template<class T>
inline void Stack<T>::add()
{
	int NewMaxSize = maxSize * 2;
	T* newPtr = new T[NewMaxSize];

	for (int i = 0;i <= current;i++) {
		newPtr[i] = ptr[i];
	}

	delete[]ptr;
	ptr = newPtr;
	maxSize = NewMaxSize;

	cout << "Stack size grow to" << maxSize << "elements" << endl;
}

template<class T>
inline void Stack<T>::print()
{
	for (int i = 0; i <= current; i++) {
		cout << ptr[i] << " ";
	}
	cout << endl;
}

template<class T>
inline void Stack<T>::push(const T& value)
{
	if (current >= maxSize - 1) {
		add();
	}
	ptr[++current] = value;
}

template<class T>
inline void Stack<T>::pop()
{
	if (empty()) {
		cout << "Exception: Stack is empty\n";
		return;
	}
	current--;
}

template<class T>
inline T& Stack<T>::top()
{
	if (empty()) {
		cout << "Exception: Stack is empty\n";
		exit(-1);
	}
	return ptr[current];
}

template<class T>
inline bool Stack<T>::empty() const
{
	return current < 0;
}

template<class T>
inline int Stack<T>::size() const
{
	return current + 1;
}




