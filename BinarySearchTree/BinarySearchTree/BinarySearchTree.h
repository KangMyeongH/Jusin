#pragma once
struct Node
{
	Node* 	Parent = nullptr;
	Node* 	Left = nullptr;
	Node* 	Right = nullptr;
	int 	Key = 0;
}; 
class BinarySearchTree
{
public:
	BinarySearchTree() : mRoot(nullptr) {}


	// 이진 탐색 트리란?
	// 왼쪽 자식 노드 키 값의 크기는 나보다 작고, 오른쪽 자식 노드 키 값의 크기는 나보다 커야한다.
	// 중복 키 = X
	//
	// 구현해야할 내용
	// 1. 탐색
	// 2. 삽입
	// 3. 삭제
	// 4. 순환
	// 5. 회전

	Node* 	Search(int value) const;
	void 	Insert(int value) const;
	void 	Remove(int value) const;
	void	Preorder();
	void	Inorder();
	void	Postorder();
	void	LevelOrder();
	void	LeftRotate();
	void	RightRotate();

	static Node* GetMaxValue(Node* cursor);
	static Node* GetMinValue(Node* cursor);
private:
	Node* mRoot;
};