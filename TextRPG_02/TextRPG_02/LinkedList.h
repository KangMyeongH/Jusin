#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
public:
	// constructor
	explicit LinkedList() : mHead(nullptr), mTail(nullptr), mSize(0) {}
	~LinkedList();

	// class
	class Iterator
	{
	public:
		friend class LinkedList;
		// constructor
		Iterator() : mList(nullptr), mNode(nullptr), mValid(false) {}
		Iterator(LinkedList* list, Node<T>* node) : mList(list), mNode(node) { mValid = (mList != nullptr && mNode != nullptr); }
		~Iterator() = default;

		// operators
		T& operator*()
		{
			return mNode->Data;
		}

		bool operator==(const Iterator& rhs)
		{
			return mList == rhs.mList && mNode == rhs.mNode;
		}

		bool operator!=(const Iterator& rhs)
		{
			return !(*this == rhs);
		}

		Iterator& operator++()
		{
			if (!mList || !mNode) mNode = nullptr;
			else mNode = mNode->NextNode;
			return *this;
		}

		Iterator& operator--()
		{
			if (!mList || !mNode) mNode = nullptr;
			else mNode = mNode->PrevNode;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator copy(*this);
			++(*this);

			return copy;
		}

		Iterator operator--(int)
		{
			Iterator copy(*this);
			--(*this);

			return copy;
		}

	private:
		LinkedList* mList;
		Node<T>* mNode;
		bool mValid;
	};

	// methods
	Iterator 		Begin();
	Iterator 		End();
	void 			Erase(Iterator& where);
	Iterator 		Insert(const Iterator& where, const T& data);
	void 			PushFront(const T& data);
	void 			PushBack(const T& data);
	void 			PopFront();
	void 			PopBack();
	int 			GetSize() const { return mSize; }

private:
	// field
	Node<T>* 		mHead;
	Node<T>* 		mTail;
	int 			mSize;
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	while (mSize != 0)
	{
		Node<T>* temp = mHead->NextNode;
		delete mHead;
		mHead = temp;
		--mSize;
	}
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Begin()
{
	return Iterator(this, mHead);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::End()
{
	return Iterator(this, nullptr);
}

template <typename T>
void LinkedList<T>::Erase(Iterator& where)
{
	if (!where.mList || !where.mNode) return;
	Node<T>* eraseNode = where.mNode;
	if (eraseNode->PrevNode && eraseNode->NextNode)
	{
		eraseNode->PrevNode->NextNode = eraseNode->NextNode;
		eraseNode->NextNode->PrevNode = eraseNode->PrevNode;
		delete eraseNode;
		mSize--;
		return;
	}

	if (mSize == 1)
	{
		delete eraseNode;
		mHead = nullptr;
		mTail = nullptr;
		mSize--;
	}

	// where == Head
	if (eraseNode == mHead)
	{
		PopFront();
		return;
	}

	// where == Tail
	if (eraseNode == mTail)
	{
		PopBack();
	}
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Insert(const Iterator& where, const T& data)
{
	if (!where.mList || !where.mNode) return Iterator();

	Node<T>* newNode = new Node<T>{ data, where.mNode, where.mNode->PrevNode };
	where.mNode->PrevNode = newNode;
	if (where.mNode == mHead)	mHead = newNode;
	mSize++;
	return Iterator(this, newNode);
}

template <typename T>
void LinkedList<T>::PushFront(const T& data)
{
	if (mHead)
	{
		Node<T>* newNode = new Node<T>{ data, mHead, nullptr };
		mHead = newNode;
		mSize++;
	}

	// Is linkedList empty
	else
	{
		mHead = new Node<T>{ data, nullptr, nullptr };
		mTail = mHead;
		mSize++;
	}
}

template <typename T>
void LinkedList<T>::PushBack(const T& data)
{
	if (mTail)
	{
		Node<T>* newNode = new Node<T>{ data, nullptr, mTail };
		mTail->NextNode = newNode;
		mTail = newNode;
		mSize++;
	}

	// Is linkedList empty
	else
	{
		mTail = new Node<T>{ data, nullptr, nullptr };
		mHead = mTail;
		mSize++;
	}
}

template <typename T>
void LinkedList<T>::PopFront()
{
	if (!mHead) return;

	if (mHead->NextNode)
	{
		const Node<T>* removeNode = mHead;
		mHead = mHead->NextNode;
		mHead->PrevNode = nullptr;
		delete removeNode;
	}

	else
	{
		delete mHead;
		mHead = nullptr;
		mTail = nullptr;
	}

	mSize--;
}

template <typename T>
void LinkedList<T>::PopBack()
{
	if (!mTail) return;

	if (mTail->PrevNode)
	{
		const Node<T>* removeNode = mTail;
		mTail = mTail->PrevNode;
		mTail->NextNode = nullptr;
		delete removeNode;
	}

	else
	{
		delete mTail;
		mTail = nullptr;
		mHead = nullptr;
	}

	mSize--;
}
