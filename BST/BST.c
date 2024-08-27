
#include "BST.h"




/*
*@brief		createNode creates a node with a left and right child for the BST
*
*@param[in]	keyValue	keyValue is the value for the node
*
*@return	A pointer to the newly created node.
*/
Node* createNode(int keyValue)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //Allocate memory for new node
	newNode->left = NULL; 
	newNode->right = NULL;
	newNode->key = keyValue;
	
	return newNode;
}//Function: createNode
	
/*
*@brief		searchBST searches the BST for the node with the same key as keyValue.
*
*@param[in]	root	root of the current tree branch
*@param[in]	keyValue	value of the key we are looking to find
*
*@return	returns the node with the correct key value or NULL if couldn't find the node.
*/
Node* searchBST(Node* root, int keyValue)
{
	//If can't find the key, return NULL. If we found the key, return the node pointer.
	if(root == NULL || root->key == keyValue){
		return root;
	}
	
	//If the value we are searching for is less than the node we are on, traverse the left subtree
	if(root->key > keyValue){
		return searchBST(root->left, keyValue);
	}
	
	//Value is greater than current node, traverse right subtree
	else{
		return searchBST(root->right, keyValue);
	}
}//Function: searchBST

/*
*@brief		insertNode inserts a node with key keyValue (this function also takes care of creating the node).
*
*@param[in]	root	root is the root of the tree to insert the node into
*@param[in]	keyValue	keyValue is the key for the node you wish to insert
*
*return		Returns a pointer to the newly inserted node
*/
Node* insertNode(Node* root, int keyValue)
{
	//When the tree is empty, we have found the correct location. Return a new node
	if(root == NULL){
		Node* tempNode = createNode(keyValue);
		return tempNode;
	}
	
	//When the node already exists, just return the node
	if(root->key == keyValue){
		return root;
	}
		
	//If the keyValue is less than the root's key, insert it into the root's left subtree
	//by recurring through the left subtree
	if(root->key > keyValue){
		root->left = insertNode(root->left, keyValue);
	}
	
	//If the keyValue is greater than the root's key, insert it into the root's right subtree
	//by recurring through the right subtree.
	else{
		root->right = insertNode(root->right, keyValue);
	}
	
	return root;

}//Function: insertNode


Node* findSuccessor(Node* root)
{
	//Successor is the leftmost node on the root's right subtree
	Node* successor = root->right;
	
	Node* temp = successor->left;
	
	while(successor != NULL && successor->left != NULL){
		successor = successor->left;
	}
	
	return successor;
	
}


Node* deleteNode(Node* root, int keyValue)
{

	if(root == NULL){
		return root;
	}
	
	//Search for node to delete
	if(root->key > keyValue){
		root->left = deleteNode(root->left, keyValue);
	}
	else if(root->key < keyValue){
		root->right = deleteNode(root->right, keyValue);
	}
	
	else{
		
		//No children
		if(root->right == NULL && root->left == NULL){
			free(root);
			return NULL;
		}
		
		//Only a right child
		else if(root->left == NULL){
			Node* tempRoot = root->right;
			free(root);
			return tempRoot;
		}
		
		//Only a left child
		else if(root->right == NULL){
			Node* tempRoot = root->left;
			free(root);
			return tempRoot;
		}
		
		//Has two child nodes
		else{
			
			Node* successor = findSuccessor(root); //Get successor node (lower leftmost descendent in right subtree)
			root->key = successor->key; //Now set the root key equal to the successor key
			root->right = deleteNode(root->right, successor->key); //Can now go through the process of deleting the old successor node in the right subtree
		}
	}
	return root;
	
	
}

void inOrderTraversal(Node* root){
	if(root != NULL){
		inOrderTraversal(root->left);
		printf("%d ", root->key);
		inOrderTraversal(root->right);
	}
}



