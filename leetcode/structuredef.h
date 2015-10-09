#ifndef _STRUCTUREDEF_H_
#define _STRUCTUREDEF_H_
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

#endif