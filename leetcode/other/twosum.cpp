#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		int index1,index2;
		index1= 1;
		index2 =2;
		vector<int>::iterator iter1,iter2;
		iter1 = nums.begin();
		
		for( ; iter1 != nums.end() ; ++iter1,++index1)
		{
			for(iter2 = iter1,index2=index1,++iter2,++index2 ; iter2!=nums.end() ;++iter2,++index2)
			{
				if( ( (*iter1)+(*iter2)) == target)
				{
					vector<int> vec;
					vec.push_back(index1);
					vec.push_back(index2);
					return vec;
				}

			}

		}
		return vector<int>(2,0);
	}
};
int main(int argc ,char* argv[])
{
	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	int target = 7;
	vector<int> vec = (new Solution())->twoSum(vec1, target );
	
	cout<<vec[0]<<vec[1]<<endl;
	
}