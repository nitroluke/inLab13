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
	int iCount;
	int jCount;
	for(iCount = 1; iCount < 3; iCount++){ // the number of words you have as arguments.  Change this if you want more words as arguments, right now it is "Ada Lovelace"
		for(jCount = 0; jCount < 10; jCount++){ // the max number of letters in your words (it's set to 10 because no words will be longer than 10) and my code handles if a word is shorter than the given int counter
			if(argv[iCount][jCount] == '\0'){
				
				break;
			}
			//printf("%c", argv[i][j]);
			//puts("inserting a node");
			printf("inserting nodeData %c \n", argv[iCount][jCount]);
			headNode = insertData(argv[iCount][jCount], headNode);
		}
		puts("\n");
	}
	//printLinkedList(headNode);
	recursivePrint(headNode);
	puts("\nThis is for the Extra credit\n");
	puts("printing the fourth letter");
	printf("%c", headNode->nextNode->nextNode->nextNode->nodeData);
	return 0;
}

ofTypeNode *insertData(char nodeData, ofTypeNode *headNode){
	ofTypeNode *curNode;
	curNode = (ofTypeNode*)malloc(sizeof(ofTypeNode));
	curNode->nodeData = nodeData;
	
	if(curNode == NULL){
		puts("curNode is null for some reason this should never happen");
		return;
	}
	if(headNode == NULL){ // there are no nodes in the linked list
		curNode->nextNode = NULL;
		return curNode;
	}else{ // there is a node in the linked list
		insertRecurse(headNode, curNode);
		return;
	}
	return;
}

ofTypeNode *insertRecurse(ofTypeNode *headNode, ofTypeNode *curNode){
	if(headNode->nextNode == NULL){ // the next letter can be inserted
		printf("inserting curNode, curNode = %c\n", curNode->nodeData);
		headNode->nextNode = curNode;
		curNode->nextNode = NULL;
		return headNode;  // a node has been inserted, so exit
	}else{ // an empty place has not been found. try to insert using the next node
		insertRecurse(headNode->nextNode, curNode);
		return headNode;
	}
	return headNode;
}

void printLinkedList(ofTypeNode *headNode){  // non-recursive print function
puts("printing linked list");
	while(headNode != NULL){
		printf("%c", headNode->nodeData);
		headNode = headNode->nextNode;
	}
}

void recursivePrint(ofTypeNode *headNode){ // recursive print function
puts("recursively printing the linked list");
	if(headNode != NULL){
		printf("%c \n", headNode->nodeData);
		recursivePrint(headNode->nextNode);
	}
}