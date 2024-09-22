#pragma once
template<typename T>
struct Node
{
	T Data;
	Node* NextNode;
	Node* PrevNode;
};