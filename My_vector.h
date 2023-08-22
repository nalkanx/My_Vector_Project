#pragma once 
#include<initializer_list>


class MyVector
{
public:
	MyVector() = default;
	MyVector(size_t);
	MyVector(const MyVector& target);
	MyVector(std::initializer_list<int> values);
	MyVector(size_t capacity, int initial_value);
	int* data();
	int& operator[](size_t index);
	int& at(int value);
	int& back();
	int& front();
	void swap(MyVector& instance2);
	void shrink_to_fit();
	void reserve(size_t newCapacity);
	void push_back(int new_item);
	void pop_back();
	void print() const; //prints all elements in array
	bool empty()const;
	size_t size() const;
	size_t capacity() const;
	size_t sum()const;
private:
	size_t msize = 0, mcapacity = 0;
	int* mdynamicArray = nullptr;
	std::initializer_list<int> box;

};
