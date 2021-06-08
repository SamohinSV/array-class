#pragma once
#include <iostream>

template<typename TData>
class CArray
{
	TData* data;
	int len;
public:
	CArray() {
		data = new TData;
		len = 1;
	};

	CArray(int size) {
		data = new TData[size];
		len = size;
	};

	~CArray() {
		delete[] data;
	};

	int size() {
		return len;
	};

	void clear() {
		if (len == 0)
			return;

		delete[] data;
		TData* newData = new TData;
		data = newData;
		len = 0;
	};

	void swap(int n) {
		if (n <= 0)
			return;

		TData na = data[n];
		TData nb = data[n - 1];

		data[n] = nb;
		data[n - 1] = na;
	};

	void erase(int n) {
		if (n < 0 || n >= len)
			return;

		TData* newData = new TData[len - 1];

		for (int i = 0; i < n; i++)
			newData[i] = data[i];

		for (int i = n; i + 1 < len; i++)
			newData[i] = data[i + 1];

		len--;
		delete[] data;
		data = newData;
	}

	void sort()
	{
		for (int i = 1; i < len; i++) {
			for (int j = i; (j - 1 >= 0) && (data[j - 1] > data[j]); j--)
				swap(j);
		}
	};

	void print() {
		setlocale(LC_ALL, "ru");

		if (len == 0) {
			std::cout << "массив пуст" << std::endl;
			return;
		}

		for (int i = 0; i < len; i++)
		{
			std::cout << data[i] << std::endl;
		}
	};

	void push_back(TData m) {
		TData* newData = new TData[len + 1];
		newData[len] = m;
		for (int i = 0; i < len; i++)
		{
			newData[i] = data[i];
		}
		len++;
		delete[] data;

		data = newData;
	};

	TData& operator[](int i) {
		return data[i];
	};
};
