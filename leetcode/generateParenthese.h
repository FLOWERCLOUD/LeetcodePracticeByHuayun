#include <string>
#include <vector>
using namespace std;


class parentheseNode{
public:
	parentheseNode()
	{
		leftNum =0;
		rightNum =0;
		num = 0;
		isWorking = true;
	}
	parentheseNode(const parentheseNode& node)
	{
		this->leftNum = node.leftNum;
		this->rightNum = node.rightNum;
		this->num =node.num;
		this->isWorking = node.isWorking;
		this->result = node.result;
	}
	parentheseNode&  operator= (const parentheseNode& node)
	{
		this->leftNum = node.leftNum;
		this->rightNum = node.rightNum;
		this->num =node.num;
		this->isWorking = node.isWorking;
		this->result = node.result;
		return *this;
	}
	void insertLeft()
	{
		++leftNum;
		++num;
		result.push_back('(');
	} 
	void insetRight()
	{
		if(leftNum >0){
			--leftNum;
			++num;
			result.push_back(')');
		}else{
			isWorking = false;
		}
	}
	string toString()
	{
		string tmp;
		for(int i = 0 ;i < result.size() ;++i){
			tmp += result[i]; 
		}
		return tmp;
	}
	vector<char> result;
	int leftNum;
	int rightNum;
	int num;
	bool isWorking;

};

class parentheseSolution {
public:
	vector<string> generateParenthesis(int n) {

		vector<parentheseNode> result; 
		parentheseNode firstnode;
		firstnode.insertLeft();
	    result.push_back(firstnode);
		for( int i = 1 ; i < n*2 ; ++i)
		{

			vector<parentheseNode> tmp;
			for( int i = 0 ;i < result.size() ; ++i){
				parentheseNode left = result[i];
				left.insertLeft();
				parentheseNode right  = result[i];
				right.insetRight();
				if(left.isWorking) tmp.push_back(left);
				if(right.isWorking) tmp.push_back(right);
			}
			result = tmp;
		}
		vector<string> stringResult;
		for(int i = 0 ; i< result.size() ;++i){
			if(result[i].leftNum == 0)
			stringResult.push_back(result[i].toString());
		}
		return stringResult;
	}
};

class  parentheseSolution2 {
public:
	// l is left parentheses used, r is right parentheses used
	// cur is initialized with ')'
	void search(int l, int r, int n, string& cur, vector<string> &ret) {
		if (l == n) {
			ret.push_back(cur);
			return;
		}  
		if (r < l) search(l, r+1, n, cur, ret);

		cur[l+r] = '(';
		search(l+1, r, n, cur, ret);
		cur[l+r] = ')';
	}

	vector<string> generateParenthesis(int n) {
		string cur;
		vector<string> ret;

		cur.resize(2*n, ')');
		ret.reserve(2 * n);
		search(0, 0, n, cur, ret);

		return ret;
	}
};

class parentheseSolution3 {
public:
	void generate(int leftNum,int rightNum,string s,vector<string> &result)  
	{  
		if(leftNum==0&&rightNum==0)  
		{  
			result.push_back(s);  
		}  
		if(leftNum>0)  
		{  
			generate(leftNum-1,rightNum,s+'(',result);  
		}  
		if(rightNum>0&&leftNum<rightNum)  
		{  
			generate(leftNum,rightNum-1,s+')',result);  
		}  
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string tmp;
		generate( n , n ,tmp , result);
		return result;
	}
};