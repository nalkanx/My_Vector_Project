#include "My_vector.h"
#include <iostream>
#include <initializer_list>

MyVector::MyVector(const std::initializer_list<int> items) : MyVector(items.size()) {
	int counter = 0;
	for (auto& e : items)
	{
		mdynamicArray[counter++] = e;
	}
}
MyVector::MyVector(size_t vec_capacity) : msize{ vec_capacity }, mcapacity{ vec_capacity } {
	mdynamicArray = new int[mcapacity]();

};
MyVector::MyVector(const MyVector& target) {
	mdynamicArray = target.mdynamicArray;

};
MyVector::MyVector(size_t capacity, int initial_value) : msize{ capacity }, mcapacity{ capacity }
{
	mdynamicArray = new int[mcapacity];
	for (size_t i = 0; i < mcapacity; i++)
	{
		mdynamicArray[i] = initial_value;
	}
};

int& MyVector::operator[](size_t index) {
	return mdynamicArray[index];
}

void MyVector::reserve(size_t newCapacity = 0) {
	{

		if (mcapacity < msize)
			return;
		if (newCapacity == 0) { newCapacity = mcapacity * 2; }

		int* newArray = new int[newCapacity]();

		for (size_t k = 0; k < msize; ++k) {
			newArray[k] = std::move(mdynamicArray[k]);
		}



		mcapacity = newCapacity;
		std::swap(mdynamicArray, newArray);
		delete[] newArray;
	}
}
void MyVector::push_back(int new_item) {
	if (msize >= mcapacity)
	{
		reserve();
	}
	mdynamicArray[msize++] = new_item;


}
void MyVector::pop_back() {

	mdynamicArray[--msize] = 0;


}
void MyVector::swap(MyVector& instance2)
{
	size_t b_size = mcapacity > instance2.mcapacity ? mcapacity : instance2.mcapacity;
	MyVector buffer(b_size);
	buffer = *this;
	*this = instance2;
	instance2 = buffer;

}
void MyVector::shrink_to_fit() {
	mcapacity = msize;
}

int& MyVector::back() {
	return mdynamicArray[msize - 1];
}
int& MyVector::front() {
	return mdynamicArray[0];
}
int& MyVector::at(int value) {
	return mdynamicArray[value];
}
int* MyVector::data() {
	return mdynamicArray;
}

size_t MyVector::sum()const {
	size_t sum = 0;
	for (size_t i = 0; i < size(); i++)
	{
		sum += mdynamicArray[i];


	}
	return sum;
}
size_t MyVector::size() const {
	return msize;
}
void MyVector::print() const {
	for (size_t i = 0; i < mcapacity; i++)
	{
		std::cout << mdynamicArray[i] << " ";
	}
	std::cout << '\n';
}
size_t MyVector::capacity() const {
	return mcapacity;
}
bool MyVector::empty()const {
	return msize == 0 ? true : false;
}