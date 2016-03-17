#include "structuredef.h"

ListNode* reverseWithVal(ListNode* p , int val)
{
	if(!p)return p;
	ListNode dummy;
	dummy.next = p;
	dummy.val = -1;
	ListNode* pN = &dummy;
	ListNode* ph = NULL;
	ListNode* pp = NULL;
	while( pN->next)
	{
		if( pN->next ->val == val)
		{
			ph = pN->next;
			pp = pN ;
		}
		pN = pN->next;
	}	
	if(pp&&(pp->next!=p))pp ->next = NULL;
	if(pp&&(pp->next!=p))pN->next = p;
	return pp?ph:p;

}
typedef ListNode List;
List* reverseWithVal2(List *l, int num)
{
	List *head = l;
	List *p = NULL;
	while (l != NULL && l->val != num) {
		l = l->next;
	}
	if (l == NULL)
		return l;
	else
		p = l;
	l = p;
	while (head != l) {
		p->next = head;
		head = head->next;
		p = p->next;
	}
	p->next = NULL;
	return l;
}
