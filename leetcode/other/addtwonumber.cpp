#include <iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 ListNode * insert(ListNode* parent ,int val){
	 ListNode * child = NULL;
	 ListNode * temp;
	 while(parent!=NULL){
		 temp = parent;
		 parent = parent->next;
	 }

	    child = (ListNode*)malloc(sizeof(ListNode));
		temp->next = child;
		memset( child , val ,sizeof(ListNode));
		child->val = val;
		child->next = NULL;
	 return child;
 }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1,len2;
        int max_len = ( (len1 = getListLen(l1)) > ( len2 = getListLen(l2) ) ) ? len1 :len2  ;
        ListNode * result = (ListNode*) malloc(max_len * sizeof(ListNode));
        memset(result ,0 ,max_len * sizeof(ListNode));
		for(int i = 0 ; i<max_len-1 ;++i){
			insert( result ,0);
		}
		ListNode* temp = result;
        for(int i = 0 ; i < max_len ; ++i ){
			if( (l1 != NULL)&&(l2!=NULL)){
				 result->val = result->val + l1->val + l2->val;
			}
			if( l1==NULL)result->val = result->val + l2->val;
			if( l2==NULL)result->val = result->val + l1->val ;
           
            if( result->val > 9){
                
                result->val = result->val - 10;
				if(result->next==NULL){
					result->next = (ListNode *)malloc(sizeof(ListNode));
					result->next = (ListNode *)memset(result->next , 0 ,sizeof(ListNode));
				}
                result->next->val++;
            }
            
			if( l1 != NULL)l1 = l1->next;
			if( l2 != NULL)l2 = l2->next;
			result = result->next;
        }
        return temp;
    }
    int getListLen(ListNode*l1){
		ListNode *temp;
        int count = 0;
		temp = l1;
        while(l1 != NULL){
            l1 = l1 ->next;
            count ++;
        }
		l1 = temp;
        return count;
    }
};

int main(int argc , char** argv){
    ListNode* l1,*l2,*l3;
	l1 = (ListNode*)malloc(5*sizeof(ListNode));
	l2 = (ListNode*)malloc(5*sizeof(ListNode));
	memset( l1 ,0 , 5 * sizeof(ListNode));
	memset( l2 ,0 , 5 * sizeof(ListNode));
	insert(l1,3);
	insert(l1,4);
	insert(l1,5);
	insert(l1,6);
	insert(l1,7);
	insert(l1,4);
	insert(l2,7);
	insert(l2,3);
	insert(l2,4);
	insert(l2,7);
	
	l3 = (new Solution() )->addTwoNumbers(l1,l2);
	while(l3 != NULL){
		cout<< l3->val<<"->"<<endl;
		l3 = l3->next;
	}
	cout<<"null";
	free(l1);
	free(l2);
	free(l3);


	return 0;
}