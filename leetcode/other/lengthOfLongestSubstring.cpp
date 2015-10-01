#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int MAX_ASCII = 256;
		int last[MAX_ASCII];
		int first_ascii = 0;
		for( int i = 0;i<MAX_ASCII;++i){
			last[i] = -1 ;
		}
		const int s_len = s.size();
		int max = 0;
		int count=0;
		int i_f;
		i_f = 0;
		for(int i = 0;i<s_len ; ++i){

			if( last[s[i]-first_ascii]>=i_f ){
				i_f = last[s[i]-first_ascii]+1;
			}
			last[s[i]-first_ascii] = i;
			count = i - i_f+1;
			max = count> max? count: max;

		}
		return max;
	}
};

int main(int argc ,char** argv){
	string s = "abcabcdefbcaabc";
	int i = (new Solution )->lengthOfLongestSubstring(s);
	cout<<i;

}