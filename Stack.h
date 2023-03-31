#pragma once

template <class T>
class Stack {

private:
	T* array;
	int size;
public:
	Stack() : array(nullptr), size(0) {};
	~Stack() {
		delete array;
	}
	void Push(T value_to_push) {

		if (size == 0)
		{
			array = new T[4];
			array[size++] = value_to_push;
		}
		else
		{
			T* copy_array = array;
			size++;
			array = new T[sizeof(T) * size];
			for (int i = 0; i < size - 1; i++)
				array[i] = copy_array[i];

			array[size-1] = value_to_push;
		}
	}
	T Pop() {
		return array[size - 1];
	}
	void Delete(int index) {

		if (index < 0 || index > size)
		{
			std::cout << "\nCannot perform delete -> Index outside of the array";
			return;
		}

		T* copy_array = array;
		array = new T[sizeof(T) * (size - 1)];
		
		for (int i = 0; i < index; i++)
			array[i] = copy_array[i];

		for (int i = index; i < size; i++)
			array[i] = copy_array[i + 1];
		size--;
	}
	void Insert(T value, int index) {	///pot sa apelez push ul -> si sa mut ulterior elementul 
		if (index < 0 || index > size)
		{
			std::cout << "\nCannot perform insertion -> Index doesn't respect array boundaries";
			return;
		}
		T* copy_array = array;
		array = new T[sizeof(T) * (size + 1)];

		for(int i = 0 ; i < index; i++)
			array[i] = copy_array[i];

		array[index] = value;
		size++;
		for (int i = index + 1; i < size; i++)
			array[i] = copy_array[i - 1];
	}
	void Sort(T(*callback)(T,T)) {

		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (callback == nullptr)
				{
					if (array[i] > array[j])
						std::swap(array[i], array[j]);
				}
				else if (callback(array[i], array[j]))
				{
					std::swap(array[i], array[j]);
				}

					
	}
	const T& Get_element(int index) {

		if (index < 0 || index > size)
		{
			std::cout << "\nCannot perform getter -> Index doesn't respect array boundaries";
			return -1;
		}
		else
			return array[index];
	}
	void Set(T value, int index) {
		if (index < 0 || index > size)
		{
			std::cout << "\nCannot perform setter -> Index doesn't respect array boundaries";
			return;
		}
		else
			array[index] = value;
	}
	int Count() {
		return size + 1;
	}
	int FirstIndexOf(T value, bool(*callback)(T, T)) {

		for (int i = 0; i < size; i++)
			if (callback != nullptr)
			{
				if (callback(value, array[i]))
					return i;
			}
			else
			{
				if (value == array[i])
					return i;
			}
		return -1;	///elem was not found
	}
	void Print() 
	{
		std::cout << "\nThe elements from the vector are: ";
		if (size == 0)
			return;
		for (int i = 0; i < size; i++)
			std::cout << array[i] << ' ';
	}
};
