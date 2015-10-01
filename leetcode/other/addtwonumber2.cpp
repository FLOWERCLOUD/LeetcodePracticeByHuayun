#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	ListNode * dummy; // used to indicate the head of the list of the result
	dummy = (ListNode*)malloc(sizeof(ListNode));
	memset(dummy , 0 ,sizeof(ListNode));
	dummy->val = -1;
	ListNode *pa,*pb, *pr;
	// pr = dummy->next;
	pr = dummy;
	for( pa = l1 ,pb= l2 ; NULL != pa ||NULL!=pb;pa= NULL==pa ?NULL :  pa->next, pb=NULL== pb?NULL : pb->next ){
		const int a = NULL==pa? 0 :pa->val;
		const int b = NULL==pb? 0 :pb->val;
		const int r = NULL==pr->next? 0 :pr->next->val;
		const int carry = ( r +a + b)/10;
		const int value = ( r +a + b)%10;
		if(NULL== pr->next){
			pr->next =(ListNode*)malloc(sizeof(ListNode));    //不能直接对 pr赋值，会造成断链
			memset(pr->next ,0,sizeof(ListNode));
		}
		pr->next->val = value;
		if(carry>0){
			pr->next->next = (ListNode*)malloc(sizeof(ListNode));
			memset(pr->next->next , 0 ,sizeof(ListNode));
			pr->next->next->val = carry;
		}
		pr = pr->next;
	}
	return dummy->next;
}

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
int main(int argc , char** argv){
	ListNode* l1,*l2,*l3;
	l1 = (ListNode*)malloc(5*sizeof(ListNode));
	l2 = (ListNode*)malloc(5*sizeof(ListNode));
	memset( l1 ,0 , 5 * sizeof(ListNode));
	memset( l2 ,0 , 5 * sizeof(ListNode));
	insert(l1,9);
	insert(l1,8);
	insert(l2,1);

	l3 = addTwoNumbers(l1,l2);
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