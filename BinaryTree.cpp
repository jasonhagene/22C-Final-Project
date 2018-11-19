#include "BinaryTree.h"
BinaryTree::BinaryTree(Contact* arr, int size) {
	
}
BinaryTree::~BinaryTree() {
	if (head == NULL) return;
	delete head->getLeft();
	delete head->getRight();
}

void BinaryTree::clearChildren(BinaryNode** arr) {
	for (int i = 0; i < size; i++) {
		arr[i]->setLeftChild(NULL);
		arr[i]->setRightChild(NULL);
	}
}

void BinaryTree::prefixCopy(BinaryNode* head, BinaryNode** arr) {
	static int pos = 0;
	if (head == NULL) { return; }
	arr[pos] = head;
	pos++;
	prefixCopy(head->getLeft(), arr);
	prefixCopy(head->getRight(), arr);
}

void BinaryTree::arrangeByName() {
	BinaryNode** arr = new BinaryNode*[size];
	prefixCopy(head, arr);
	clearChildren(arr);
	head = arr[0];
	for (int i = 1; i < size; i++) {
		addNodeByName(head, arr[i]);
	}
}
void BinaryTree::arrangeByAddress() {
	BinaryNode** arr = new BinaryNode*[size];
	prefixCopy(head, arr);
	clearChildren(arr);
	head = arr[0];
	for (int i = 1; i < size; i++) {
		addNodeByAddress(head, arr[i]);
	}
}
void BinaryTree::arrangeByDistance(Location loc) {
	currLocation = loc;
	BinaryNode** arr = new BinaryNode*[size];
	prefixCopy(head, arr);
	clearChildren(arr);
	head = arr[0];
	for (int i = 1; i < size; i++) {
		addNodeByDistance(head, arr[i]);
	}
}

Contact* BinaryTree::searchByAddress(std::string add) {
	return searchByAddress(add, head);
}
Contact* BinaryTree::searchByAddress(std::string add, BinaryNode* head) {
	if (head == NULL) throw "Address not found.";
	if (add == head->getData()->getAddress()) {
		return head->getData();
	}
	else if (add < head->getData()->getAddress()) {
		return searchByAddress(add, head->getLeft());
	}
	else return searchByAddress(add, head->getRight());
}
Contact* BinaryTree::searchByName(std::string add) {
	return searchByName(add, head);
}
Contact* BinaryTree::searchByName(std::string add, BinaryNode* head) {
	if (head == NULL) throw "Name not found.";
	if (add == head->getData()->getName()) {
		return head->getData();
	}
	else if (add < head->getData()->getName()) {
		return searchByName(add, head->getLeft());
	}
	else return searchByName(add, head->getRight());
}

void BinaryTree::addNodeByName(Contact toAdd) {
	BinaryNode* temp = new BinaryNode(toAdd);
	addNodeByName(temp, head);
	size++;
}
void BinaryTree::addNodeByName(BinaryNode* toAdd, BinaryNode* head) {
	if (head->getData()->getName() > toAdd->getData()->getName()) {
		if (head->getLeft() == NULL) {
			head->setLeftChild(toAdd);
		}
		else addNodeByName(toAdd, head->getLeft());
	}
	else {
		if (head->getRight() == NULL) {
			head->setRightChild(toAdd);
		}
		else addNodeByName(toAdd, head->getRight());
	}
}

void BinaryTree::addNodeByAddress(Contact toAdd) {
	BinaryNode* temp = new BinaryNode(toAdd);
	addNodeByAddress(temp, head);
	size++;
}
void BinaryTree::addNodeByAddress(BinaryNode* toAdd, BinaryNode* head) {
	if (head->getData()->getAddress() > toAdd->getData()->getAddress()) {
		if (head->getLeft() == NULL) {
			head->setLeftChild(toAdd);
		}
		else addNodeByAddress(toAdd, head->getLeft());
	}
	else {
		if (head->getRight() == NULL) {
			head->setRightChild(toAdd);
		}
		else addNodeByAddress(toAdd, head->getRight());
	}
}

void BinaryTree::addNodeByDistance(Contact toAdd) {
	BinaryNode* temp = new BinaryNode(toAdd);
	temp->getData()->getLocation().setRelativeDistance(currLocation);
	addNodeByDistance(temp, head);
	size++;
}
void BinaryTree::addNodeByDistance(BinaryNode* toAdd, BinaryNode* head) {
	if (head->getData()->getLocation().getRelativeDistance() > toAdd->getData()->getLocation().getRelativeDistance()) {
		if (head->getLeft() == NULL) {
			head->setLeftChild(toAdd);
		}
		else addNodeByDistance(toAdd, head->getLeft());
	}
	else {
		if (head->getRight() == NULL) {
			head->setRightChild(toAdd);
		}
		else addNodeByDistance(toAdd, head->getRight());
	}
}