/*
Luke Welna
Lab 13
4-15-14
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeNode{
	char nodeData;  //S stores the char read in
	struct nodeNode *nextNode; // references the next node
} ofTypeNode;

ofTypeNode *headNode = NULL;
ofTypeNode *insertData(char nodeData, ofTypeNode *headNode);
ofTypeNode *insertRecurse(ofTypeNode *curNode, ofTypeNode *headNode);
void printLinkedList(ofTypeNode *headNode);
void recursivePrint(ofTypeNode *headNode);

int main(int argc, char *argv[]){
	int i;
	int j;
	for(i = 1; i < 4; i++){ // the number of words you have as arguments
		for(j = 0; j < 10; j++){ // the max number of letters in your words (it's set to 10 becuase no words will be loger than 10)
			headNode = insertData(argv[i][j], headNode);
			if(argv[i][j] == '\0'){
				
				break;
			}
			//printf("%c", argv[i][j]);
			//puts("inserting a node");
			printf("inserting nodeData %c \n", argv[i][j]);
			headNode = insertData(argv[i][j], headNode);
			if(headNode == NULL){
				puts("headNode is null in main");
				return;
			}
		}
		puts("\n");
	}
	//printLinkedList(headNode);
	recursivePrint(headNode);
	return 0;
}

ofTypeNode *insertData(char nodeData, ofTypeNode *headNode){
	ofTypeNode *curNode;
	curNode = (ofTypeNode*)malloc(sizeof(ofTypeNode));
	curNode->nodeData = nodeData;
	
	if(curNode == NULL){
		puts("curNode is null for some reason");
		curNode->nextNode = NULL;
		return;
	}
	if(headNode == NULL){ // there are no nodes in the linked list
		puts("this should print once");
		curNode->nextNode = NULL;
		//printf("hjkhjk  %c   ", curNode->nodeData);
		return curNode;
	}else{ // there is a node in the linked list
		insertRecurse(headNode, curNode);
		return headNode;
		//puts("bleh");
	}

	//printf("%c", nodeData);
}

ofTypeNode *insertRecurse(ofTypeNode *headNode, ofTypeNode *curNode){
    //puts("inserting recursively");
	if(headNode->nextNode == NULL){ // the next letter can be inserted
		headNode->nextNode = curNode;
		curNode->nextNode = NULL;
		//printf("%c", curNode->nodeData);
		
		return;
	}
	insertRecurse(headNode->nextNode, curNode);
	
}

void printLinkedList(ofTypeNode *headNode){
puts("printing linked list");
	while(headNode != NULL){
		printf("%c", headNode->nodeData);
		headNode = headNode->nextNode;
	}
	//removed a return here
}

void recursivePrint(ofTypeNode *headNode){
	if(headNode != NULL){
		printf("%c \n", headNode->nodeData);
		recursivePrint(headNode->nextNode);
	}
}