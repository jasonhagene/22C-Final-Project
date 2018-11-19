#pragma once
#include "BinaryNode.h"
class BinaryTree {
private:
	BinaryNode* head;
	Location currLocation; //Only used for sorting by Location
	int size;
	//Used when re-sorting to temporarily store elements
	void clearChildren(BinaryNode**);
	void prefixCopy(BinaryNode*, BinaryNode**);
	//Called by the above function
	void prefixCopy(BinaryNode** arr) { prefixCopy(head, arr); }
	Contact* searchByName(std::string, BinaryNode*);
	Contact* searchByAddress(std::string, BinaryNode*);
	//Called recursively when a node is added
	void addNodeByName(BinaryNode*, BinaryNode*);
	void addNodeByAddress(BinaryNode*, BinaryNode*);
	void addNodeByDistance(BinaryNode*, BinaryNode*);
public:
	BinaryTree(Contact*, int);
	~BinaryTree();

	void arrangeByName();
	void arrangeByAddress();
	void arrangeByDistance(Location);
	Contact* searchByName(std::string);
	Contact* searchByAddress(std::string);

	//Functions which begin recursively adding a given node
	void addNodeByName(Contact);
	void addNodeByAddress(Contact);
	void addNodeByDistance(Contact);
};