/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "structuredef.h"
 int getListLen(ListNode* list){
     if(NULL == list)return 0;
	 ListNode* head = list;
     int count = 0;
     while(list->next != NULL){
		 list = list->next; 
         count++;
     }
     return count+1;
 }
ListNode* removeNthFromHead(ListNode* input ,int NthNode, int listLen){  //NthNode 从0 开始
    if(NthNode < 0)return NULL;
    else if(0 == NthNode &&listLen>0)return input->next;
    else if(NthNode>0 && listLen> NthNode){
        ListNode* p_list = input;
        for(int i = 0 ; i< NthNode-1 ;i++){
            p_list = p_list->next;        
        }
        p_list->next = p_list->next->next;  //这里没有free掉NthNode节点
    }
    return input;
    
 }
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int listLen = getListLen(head);
    ListNode* result;
    result = removeNthFromHead(head , listLen-n , listLen);
    return result;
    
    
}