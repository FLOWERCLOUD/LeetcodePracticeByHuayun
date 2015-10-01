#include<iostream>
#define TRUE  1
#define FALSE 0
typedef int BOOL;
int getStrLen(char*s);
char* longestPalindrome( char* s) {
	int max_len = 1;
	const int LEN = getStrLen(s);
	int start = 0;
	BOOL** f;
	f =(BOOL**)malloc(LEN*sizeof(BOOL*));
	for(int i = 0 ;i<LEN ;++i){
		f[i] = (BOOL*)malloc(LEN*sizeof(BOOL));
	}
	//BOOL f[LEN][LEN];
	for(int i= 0 ;i < LEN;++i){
		for(int j = 0 ;j<LEN ;++j){
			f[i][j] = FALSE;
		}
	}
	for(int i=0 ; i<LEN ;++i){
		f[i][i] =TRUE;
		for( int j = 0 ;j < i;++j){
			//f[j][i] = ((s[j]==s[i]) &&(1==i-j) )||( (f[j+1][i-1])&&(i-j>1)&&(s[j]==s[i])) ? TRUE:FALSE;
			f[j][i] = (s[j]==s[i])&&( (f[j+1][i-1])||(i-j<2)) ? TRUE:FALSE;
			if(f[j][i]){
				//max_len = i-j+1>max_len ? i-j+1 : max_len;
				if(i-j+1 > max_len){
					start = j;
					max_len= i-j+1;
				}
			}

		}
	}
	char* result = (char*)malloc(max_len*sizeof(char));
	int i;
	for( i = 0 ;i<max_len;++i){
		result[i] = s[start+i];
	}
	result[i] ='\0';
	return result;
}

int getStrLen(char* s){

	int len = 0;
	while(*s!='\0'){
		++len;
		++s;
	}
	return len;
}

int main(int argc ,char** argv){
	char * s = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
	std::cout<<longestPalindrome(s)<<std::endl;
}