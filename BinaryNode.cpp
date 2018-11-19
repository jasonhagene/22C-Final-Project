#include "BinaryNode.h"

BinaryNode::BinaryNode() {
	data = NULL;
	leftChild = NULL;
	rightChild = NULL;
}
BinaryNode::BinaryNode(Contact contents) {
	data = &contents;
	leftChild = NULL;
	rightChild = NULL;
}
BinaryNode::~BinaryNode() {
	delete data;
}

bool BinaryNode::isParent(){
	if (leftChild != NULL || rightChild != NULL) {
		return true;
	}
	return false;
}
bool BinaryNode::isLeaf() {
	return !isParent();
}

void BinaryNode::setLeftChild(BinaryNode* node) {
	leftChild = node;
}

void BinaryNode::setRightChild(BinaryNode* node) {
	rightChild = node;
}