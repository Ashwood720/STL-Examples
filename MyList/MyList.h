#pragma once

#include <iostream>

using namespace std;

template<typename T>
class MyList
{
public:
	MyList();
	~MyList();

	void Clear();
	void Insert(T Data, int Index);
	void PopBack();
	void PopFront();
	void PushBack(T Data);
	void PushFront(T Data);
	void RemoveAt(int Index);

	inline int GetSize() { return Size; }

	T& operator[](const int Index);

private:
	template<typename T>
	struct Node
	{
		Node* pNext;
		T Data;

		inline Node(T Data = T(), Node* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* Head;
};

int main()
{
	MyList<int> lst;

	lst.PushBack(5);
	lst.PushBack(11);
	lst.PushBack(21);
	cout << lst.GetSize();
	lst.Insert(59, 0);
	cout<<lst.GetSize();
}