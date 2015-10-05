#include "structuredef.h"

class IntersectionofTwoLinkedListsWrap
{
public: 
	ListNode* lhead, *rhead;
	static const  int larray[13] ;
	static const  int rarray[13] ;
	IntersectionofTwoLinkedListsWrap(){
		int lnum = sizeof( larray)/sizeof(int);
		int rnum = sizeof( rarray)/sizeof(int);
		lhead = getListFromArray( (int*)larray , lnum);
		rhead = getListFromArray( (int*)rarray, rnum);

	}
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
	ListNode* reverse(ListNode* head)
	{
		ListNode dumnode;
		dumnode.next = head;
		if(!head || !head->next)return dumnode.next;
		while( head->next){
			ListNode* tmp = dumnode.next;
			dumnode.next = head->next;
			head->next = head->next->next;
			dumnode.next->next = tmp;
		}
		return dumnode.next;
	}
	struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
		if( !headA || !headB)return NULL;
		ListNode* nlhead ,*nrhead;
		ListNode* lp ,*rp;
		nlhead = reverse( headA);
		nrhead = reverse( headB);
		if( nlhead->val != nrhead->val){
			reverse(nlhead);
			reverse(nrhead);
			return NULL;

		}else{
			for( lp = nlhead ,rp = nrhead ; (lp->next) ; lp = lp->next , rp = rp->next )
			{
				if((lp->next->val != rp->next->val))break;

			}
			ListNode* target = lp;
			reverse(nlhead);
			reverse(nrhead);
			return target;
		}





	}

	ListNode* getIntersectionNode2( ListNode* llist , ListNode* rlist)
	{
		if( !llist || !rlist)return NULL; 
		int lnum ,rnum;
		lnum = rnum =0;
		ListNode* pl = llist; 
		ListNode* pr = rlist;
		while( pl){
			++lnum;
			pl = pl->next;
		}
		while( pr){
			++rnum;
			pr = pr->next;
		}
		pl = llist;
		pr = rlist;
		for( int i = 0 ; i< (lnum-rnum) ; ++i){
			pl = pl->next;
		}
		for( int i = 0; i< ( rnum - lnum) ; ++i){
			pr = pr->next;
		}
		while( pl!= pr && pl){
			pl = pl->next;
			pr = pr->next;
		}
		return pl;

	}
	void coutList(ListNode* phead)
	{
		while( NULL != phead){
			std::cout<< phead->val<<std::endl;
			phead = phead->next;
		}
	}
	void run(){

		ListNode* result = getIntersectionNode2( lhead ,rhead);
		coutList(lhead);

	}

};
const int IntersectionofTwoLinkedListsWrap::larray[]= {1,2,3,4,5,6,7,8,9,10,11,12,0};
const int IntersectionofTwoLinkedListsWrap::rarray[]= {1,2,3,4,5,6,7,8,9,10,11,12,0};