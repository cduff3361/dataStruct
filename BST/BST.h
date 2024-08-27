#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

//#include "BST.h"


typedef struct Node{
	
	int key;
	struct Node* left;
	struct Node* right;
	
}Node;

/*
*@brief		createNode creates a node with a left and right child for the BST
*
*@param[in]	keyValue	keyValue is the value for the node
*
*@return	A pointer to the newly created node.
*/
Node* createNode(int keyValue);
	
/*
*@brief		searchBST searches the BST for the node with the same key as keyValue.
*
*@param[in]	root	root of the current tree branch
*@param[in]	keyValue	value of the key we are looking to find
*
*@return	returns the node with the correct key value or NULL if couldn't find the node.
*/
Node* searchBST(Node* root, int keyValue);

/*
*@brief		insertNode inserts a node with key keyValue (this function also takes care of creating the node).
*
*@param[in]	root	root is the root of the tree to insert the node into
*@param[in]	keyValue	keyValue is the key for the node you wish to insert
*
*return		Returns a pointer to the newly inserted node
*/
Node* insertNode(Node* root, int keyValue);

Node* findSuccessor(Node* root);

Node* deleteNode(Node* root, int keyValue);

void inOrderTraversal(Node* root);


#endif
