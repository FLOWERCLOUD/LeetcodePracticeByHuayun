#include "structuredef.h"
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class TreeTraversalSolution 
{
public:
	TreeNode* root;
	static const  int treearray[11] ;
	TreeTraversalSolution(){
		root = getTreeFromArray((int*)treearray ,11);
	}
	TreeNode* getTreeFromArray(int* iarray ,int num){
		TreeNode ;
		
		queue<TreeNode*> tq;
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->val = iarray[0];
		tq.push(newNode);
		for( int i = 0 ;i< num-1 ;){
			TreeNode* topNode = tq.front();
			tq.pop();
			if( iarray[++i] != -1){
				TreeNode* leftNode = (TreeNode*)malloc(sizeof(TreeNode));
				leftNode->val = iarray[i];
				tq.push(leftNode);
				topNode->left = leftNode;
			}else{
				topNode->left = NULL;
			}
			if( iarray[++i] != -1){
				TreeNode* rightNode = (TreeNode*)malloc(sizeof(TreeNode));
				rightNode->val = iarray[i];
				tq.push( rightNode);
				topNode->right = rightNode;
			}else{
				topNode->right = NULL;
			}
			
			
		}
		return newNode ;
		
	}
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> path;
		stack<TreeNode*> stk;
		TreeNode* head = root;
		while( !stk.empty() ||head){
			while(head ){
				stk.push( head);
				head = head->left;
			}
			head = stk.top();
			stk.pop();
			path.push_back(head->val);
			head = head->right;         
		}

		return path;
	}
	void coutArray(vector<int>& _in)
	{
		int num = _in.size();
		for( int i = 0 ; i<num ;++i){
			std::cout<<_in[i]<<std::endl;
		}

	}
	void run(){
		vector<int> result;
		result = inorderTraversal(root);
		coutArray(result);
	}
};

const int TreeTraversalSolution::treearray[] = { 1,2,3,4,5,-1,-1,-1,-1,-1,-1};