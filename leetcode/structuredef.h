#ifndef _STRUCTUREDEF_H_
#define _STRUCTUREDEF_H_
#include <iostream>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode  ListNode;

typedef struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

}TreeNode;

ListNode* getListFromArray( int* iarray ,int num){
	ListNode *pNode;
	int arraynum = num;
	ListNode dummy;
	pNode = &dummy;
	for( int i = 0 ;i< arraynum ;++i ){
		pNode->next =(ListNode*)malloc(sizeof(int));
		pNode->next->val = iarray[i];			
		pNode = pNode->next;
		pNode->next = NULL;
	}
	return dummy.next;
}
void coutList(ListNode* phead)
{
	while( NULL != phead){
		std::cout<< phead->val<<"->";
		phead = phead->next;
	}
	std::cout<<"NULL"<<std::endl;
}
#endif