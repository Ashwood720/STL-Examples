#include "MyList.h"

template<typename T>
MyList<T>::MyList()
{
	Size = 0;
	Head = nullptr;
}

template<typename T>
MyList<T>::~MyList()
{
	Clear();
}

template<typename T>
void MyList<T>::Clear()
{
	while (Size)
	{
		PopFront();
	}
}

template<typename T>
void MyList<T>::Insert(T Data, int Index)
{
	if (Index == 0)
	{
		PushFront(Data);
	}
	else
	{
		Node<T>* Previous = this->Head;

		for (int i = 0; i < Index - 1; i++)
		{
			Previous = Previous->pNext;
		}

		Node<T>* NewNode = new Node<T>(Data, Previous->pNext);
		Previous->pNext = NewNode;
		Size++;
	}
}

template<typename T>
void MyList<T>::PopBack()
{
	RemoveAt(Size - 1);
}

template<typename T>
void MyList<T>::PopFront()
{
	Node<T>* Temp = Head;
	Head = Head->pNext;
	delete Temp;
	Size--;
}

template<typename T>
void MyList<T>::PushBack(T Data)
{
	if (Head == nullptr)
	{
		Head = new Node<T>(Data);
	}
	else
	{
		Node<T>* Current = this->Head;

		while (Current->pNext != nullptr)
		{
			Current = Current->pNext;
		}
		Current->pNext = new Node<T>(Data);
	}
	Size++;
}

template<typename T>
void MyList<T>::PushFront(T Data)
{
	Head = new Node<T>(Data, Head);
	Size++;
}

template<typename T>
void MyList<T>::RemoveAt(int Index)
{
	if (Index == 0)
	{
		PopFront();
	}
	else
	{
		Node<T>* Previous = this->Head;

		for (int i = 0; i < Index - 1; i++)
		{
			Previous = Previous->pNext;
		}

		Node<T>* ToDelete = Previous->pNext;
		Previous->pNext = ToDelete->pNext;
		delete ToDelete;
		Size--;
	}
}

template<typename T>
T& MyList<T>::operator[](const int Index)
{
	int Counter = 0;
	Node<T>* Current = this->Head;
	while(Current != nullptr)
	{
		if(Counter == Index)
		{
			return Current->Data;
		}
		Current = Current->pNext;
		Counter++;
	}
}