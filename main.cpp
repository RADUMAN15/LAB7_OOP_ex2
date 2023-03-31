#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> vector;
	///EXAMPLE OF THE STACK TEMPLATE -> elements index start from 0 
	vector.Push(10);
	vector.Push(100);
	vector.Push(1000);
	vector.Push(1);
	vector.Push(101);
	vector.Print();
	vector.Delete(6);
	vector.Print();
	vector.Delete(3);
	vector.Print();
	vector.Insert(111, 1);
	vector.Print();
	std::cout<<vector.FirstIndexOf(100, nullptr);
	vector.Sort(nullptr);
	vector.Print();
	//std::cout<<vector.Get_element(2);
	//std::cout<<"\nThe last element from the vector is: "<<vector.Pop()<<'\n';
	//vector.Print();
}