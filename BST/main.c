#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "BST.h"


int main(int argc, char* argv[])
{
	
	if(argc == 1){
		Node* root = createNode(10);
		root = insertNode(root, 2);
		root = insertNode(root, 1);
		root = insertNode(root, 7);
		root = insertNode(root, 3);
		root = insertNode(root, 5);
		root = insertNode(root, 6);
		root = insertNode(root, 4);
		root = insertNode(root, 11);
		root = insertNode(root, 9);


		
		
		inOrderTraversal(root);
		printf("\n");
		
		deleteNode(root, 2);
		inOrderTraversal(root);
		printf("\n");
	}
	
	else{
		if(strcmp(argv[1], "add") == 0){
			int counter = 2;
			int newVal = 0;
			while(counter < argc){
				newVal = atoi(argv[counter]);
				printf("%d ", newVal);
				counter++;
			}
			printf("\n");
		}
	}
	
	
}