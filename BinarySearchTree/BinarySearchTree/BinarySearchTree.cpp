#include "pch.h"
#include "BinarySearchTree.h"

Node* BinarySearchTree::Search(const int value) const
{
	Node* cursor = mRoot;

	while (true)
	{
		if (cursor->Key > value)
		{
			if (cursor->Left) cursor = cursor->Left;
			else return nullptr;
		}

		else if (cursor->Key < value)
		{
			if (cursor->Right) cursor = cursor->Right;
			else return nullptr;
		}

		else if (cursor->Key == value) return cursor;
	}
}

void BinarySearchTree::Insert(const int value) const
{
	Node* cursor = mRoot;

	while (true)
	{
		if (cursor->Key > value)
		{
			if (cursor->Left) cursor = cursor->Left;
			else
			{
				Node* newNode = new Node;
				newNode->Key = value;
				newNode->Parent = cursor;
				cursor->Left = newNode;
				return;
			}
		}

		else if (cursor->Key < value)
		{
			if (cursor->Right) cursor = cursor->Right;
			else
			{
				Node* newNode = new Node;
				newNode->Key = value;
				newNode->Parent = cursor;
				cursor->Right = newNode;
				return;
			}
		}

		else if (cursor->Key == value) return;
	}
}

void BinarySearchTree::Remove(const int value) const
{
	Node* cursor = Search(value);

	// cursor has 0 child
	if (!cursor->Left && !cursor->Right)
	{
		Node* parent = cursor->Parent;
		if (parent->Left == cursor) parent->Left = nullptr;
		else if (parent->Right == cursor) parent->Right = nullptr;
		delete cursor;
		return;
	}

	// cursor has 1 child
	if (cursor->Left || cursor->Right)
	{
		Node* parent = cursor->Parent;
		if (cursor->Left)
		{
			cursor->Left->Parent = parent;
			parent->Left = cursor->Left;
			delete cursor;
			return;
		}

		if (cursor->Right)
		{
			cursor->Right->Parent = parent;
			parent->Right = cursor->Right;
			delete cursor;
			return;
		}
	}

	// cursor has 2 child
	if (cursor->Left && cursor->Right)
	{
		Node* temp = GetMaxValue(cursor);
		Node* parent = cursor->Parent;

		temp->Parent->Right = nullptr;
		temp->Parent = parent;
		if (parent->Left == cursor)
		{
			parent->Left = temp;
		}
	}
}

void BinarySearchTree::Preorder()
{
}

void BinarySearchTree::Inorder()
{
}

void BinarySearchTree::Postorder()
{
}

void BinarySearchTree::LevelOrder()
{
}

void BinarySearchTree::LeftRotate()
{
}

void BinarySearchTree::RightRotate()
{
}

Node* BinarySearchTree::GetMaxValue(Node* cursor)
{
	Node* value = cursor;
	while (true)
	{
		if (!value->Right) return value;
		value = cursor->Right;
	}
}

Node* BinarySearchTree::GetMinValue(Node* cursor)
{
	Node* value = cursor;
	while (true)
	{
		if (!value->Left) return value;
		value = cursor->Left;
	}
}
