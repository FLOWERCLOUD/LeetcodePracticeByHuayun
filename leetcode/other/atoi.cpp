// atoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#include <iostream>

int myAtoi(char* str) {
	char* p_str = str;
	int count = 0;  //coutn the numeber of character in the first sequence of non-whitespace characters in str
	long long result = 0; 
	int sign = 0;
	int sign_count = 0;
	int space_count =0;
	while( !( ( *p_str == '\0' ) || ( ( sign_count >0 || count>0 ) &&( *p_str<'0'||*p_str>'9' ) ) ) ){
		if((*p_str<'0')&&(*p_str>'9')&&(*p_str != 0x20) ){
			break;  //遇到非空 且不为数字的符号
		}
		if( *p_str == '+' ){
			sign = 1;
			sign_count++;
		}
		else if( *p_str == '-'){
			sign =0;
			sign_count++;

		}else if( *p_str >= '0' && *p_str <= '9'){
			result = 10*result + *p_str - '0';    
			count++;
			if(count>=18)break;  //避免 超过64位溢出，不是最安全方式，只是简易的方式
		}else if( *p_str!=0x20){
			break;  // 针对没有符号且为首个非空字符为非数字的情况
		}

		p_str++;    
	} 

	if( 0 == count ){
		return 0;
	}else{
		if(!sign && (sign_count >0)){
			return -result < INT_MIN ? INT_MIN : -(int)result;
		}
		return result >= INT_MAX? INT_MAX : (int)result;
	}


}
/*
int myAtoi(char* str) {
	char* p_str = str;
	int count = 0;  //coutn the numeber of character in the first sequence of non-whitespace characters in str
	long long result = 0; 
	int sign = 0;
	int sign_count = 0;
	int space_count =0;
	while( *p_str != '\0'){
		if( sign_count>0 &&( *p_str< '0' ||*p_str>'9' || *p_str == 0x20 )){
			space_count++;
			p_str++;
			continue;
		}
		if( (*p_str!= 0x20)&&( *p_str >= '0')&&(*p_str <='9')||(count==0)&&( (*p_str =='-')||(*p_str=='+') )){
			if(*p_str =='-'){
				sign = 1;
				p_str++;
				sign_count++;
				continue;
			}else if(*p_str =='+'){
				sign = 0;
				p_str++;
				sign_count++;
				continue;
			}
			result = 10*result + *p_str - '0';  
			count++;
		}else{
			if(count!= 0){
				break;  //退出while循环
			}
		}

		p_str++;
	}
	if( 0 == count ||sign_count>1||space_count >0 ){
		return 0;
	}else{
		if(sign){
			return -result < INT_MIN ? INT_MIN : -(int)result;
		}
		return result >= INT_MAX? INT_MAX : (int)result;
	}

}
*/
int _tmain(int argc, _TCHAR* argv[])
{
	char* s = "9223372036854775809"; //" b11228552307"; // " +b12102370352";
	int result = myAtoi(s);
	std::cout<< result<<std::endl;
	return 0;
}

