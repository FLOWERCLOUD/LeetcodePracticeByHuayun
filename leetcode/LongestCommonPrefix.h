#include<stdlib.h>
char * longestCommonPrefix1(char* fchar ,char* schar ,int * pilongestPrefix){
	char* fp_char = fchar;
	char* sp_char = schar;
	char* clongestPrefix;
	int ilongestPrefix = 0;
	char* fp, *sp;
	for(fp = fp_char, sp = sp_char; !(*fp=='\0'||*sp=='\0') ;){
		if( *fp == *sp){
			ilongestPrefix++;
			fp++,sp++;
		}else break;
	}

	if(ilongestPrefix>0){
		
		clongestPrefix = (char*)malloc(sizeof(ilongestPrefix+1));
		for(int i = 0 ; i< ilongestPrefix ;++i){
			clongestPrefix[i] = fp_char[i];    
		}
		clongestPrefix[ilongestPrefix] = '\0';
	}else{
		clongestPrefix = "";
		*pilongestPrefix = 0;
		return clongestPrefix;
	}
	*pilongestPrefix = ilongestPrefix;
	return clongestPrefix;

}

char* longestCommonPrefix(char** strs, int strsSize) {
	if( 0 ==strsSize)return "";
	if( 1 ==strsSize)return strs[0];
	char* fp_char = strs[0];
	char* sp_char = strs[1];
	int ilongestPrefix = 0;
	char* clongestPrefix;
	clongestPrefix = longestCommonPrefix1(fp_char,sp_char,&ilongestPrefix);
	if( 0 ==ilongestPrefix) return clongestPrefix;
	for(int i =2  ; i< strsSize ;i++){

		clongestPrefix = longestCommonPrefix1( clongestPrefix ,strs[i] , &ilongestPrefix);
		if( 0 ==ilongestPrefix) return clongestPrefix;
	}
	return clongestPrefix;

}