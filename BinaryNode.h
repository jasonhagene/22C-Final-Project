#pragma once
#include "Contact.h"
class BinaryNode {
private:
	BinaryNode *leftChild, *rightChild;
	Contact* data;
public:
	BinaryNode();
	BinaryNode(Contact);
	~BinaryNode();

	BinaryNode* getLeft() { return leftChild; }
	BinaryNode* getRight() { return rightChild; }
	Contact* getData() { return data; }

	bool isParent();
	bool isLeaf();

	void setLeftChild(BinaryNode*);
	void setRightChild(BinaryNode*);
};