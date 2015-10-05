// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "PalindromeNumber.h"
//#include "LongestCommonPrefix.h"
//
//#include "3SumClosest.h"
//#include "RemoveNthNodeFromEndofList.h"
//#include "ValidParentheses.h"
//#include "ImplementstrStr().h"
//#include "RotateArray.h"
#include "InsertionSortList.h"
#include "IntersectionofTwoLinkedLists.h"
#include "iostream"
using namespace std;
//#include "3Sum.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int input = 1;
	
	cout<<isPalindrome(input)<<endl;
	char * comprefix;
	char *f = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char* p[] = {f ,s ,t};
	comprefix = longestCommonPrefix(p , 3);
	cout<<comprefix<<endl;
	*/
	//free(comprefix);
	/*
	int nums[] = {0,0,0,0};
	int returnsize = 0;
	int** result;
	result = threeSum( nums, 4 ,&returnsize);
	for(int i = 0 ;i <returnsize;++i){
		cout<<"("<<result[i][0] <<"," <<result[i][1]<<","<<result[i][2]<<")"<<endl;
	}
	*/
	
	/*int nums[] = {-10,0,-2,3,-8,1,-10,8,-8,6,-7,0,-7,2,2,-5,-8,1,-4,6};//{1,1,1,0};
	cout<<threeSumClosest(nums,20,18) <<endl;
	*/
	/*
	ListNode* head,*second,*result;
	head = (ListNode*)malloc(sizeof(ListNode));
	second = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = second;
	second ->val =2;
	second ->next = NULL;	
	result = removeNthFromEnd(head,1);
	*/
	/*
	char in[] =  "([{}]{}[])";//"{[(())]}";
 	cout<<isValid(in)<<endl;
	*/
	/*
	char* l = "aaa";
	char* r = "a";
	cout<<strStr(l, r);
	*/


	//int a[] = {1 ,2 ,3};
	//rotate( a ,3 ,1 );
	//for(int i = 0; i<3 ;i++){
	//	std::cout<<a[i]<<std::endl;
	//}

	//insertionSortListWrap islw;
	//islw.run();
	IntersectionofTwoLinkedListsWrap itlw;
	itlw.run();

	

	return 0;
}

