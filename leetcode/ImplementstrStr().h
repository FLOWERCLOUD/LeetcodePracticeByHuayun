#include <string.h>
int strStr(char* haystack, char* needle) {
	if( NULL == haystack || NULL == needle )return -1;
	if( '\0' == *haystack && '\0' == * needle)return 0;
	if( '\0' != *haystack && '\0' == * needle)return 0;
	int flen = strlen(haystack);
	int slen = strlen(needle);
	if(haystack <needle) return -1;
	int j = 0;
	for( int i = 0 ; i< flen - slen +1 ;++i){
		for( j= 0 ;j< slen ;++j){
			if( haystack[ i+j] != needle[j])break;

		}
		if( j == slen)return i;
	}
	return -1;

}