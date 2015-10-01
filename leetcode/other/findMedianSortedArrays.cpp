#include<iostream>
using namespace std;
int find_kth(int* nums1 , int nums1Size , int * nums2 ,int nums2Size ,int k);
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int totol = nums1Size+nums2Size;
	if( (totol&0x1)){
		return find_kth(nums1 , nums1Size , nums2 ,nums2Size ,totol/2+1);

	}else{
		return (find_kth(nums1 , nums1Size , nums2 ,nums2Size ,totol/2)+
			find_kth(nums1 , nums1Size , nums2 ,nums2Size ,totol/2+1) )/2.0;
	}
}
int find_kth(int* nums1 , int nums1Size , int * nums2 ,int nums2Size,int k){ //k应小于nums1Size+nums2Size
	if(nums1Size > nums2Size){
		return find_kth(nums2 ,nums2Size,nums1 ,nums1Size,k);
	}
	if(0==nums1Size)return nums2[k-1];

	
	if( 1==k){
		return nums1[0] <nums2[0] ? nums1[0]:nums2[0];
	}
	int l_num =  k/2 > nums1Size? nums1Size:k/2;   // num1Size < num2Size , l_num 最大为num1Size
	int r_num =  k - l_num;
	if(nums1[l_num-1]>nums2[r_num-1]){
		return find_kth(nums1 ,nums1Size,nums2+r_num,nums2Size-r_num,k-r_num);    //k-r_num应小于nums1Size+nums2Size
	}else
		if(nums1[l_num-1]<nums2[r_num-1]){
			return find_kth(nums1+l_num ,nums1Size - l_num ,nums2 ,nums2Size,k-l_num);
		}else{
			return nums1[l_num-1];
		}

}

int main(int argc ,int argv){
	int a[] = {1,1};
	int b[] = {1,2};
	cout<<findMedianSortedArrays(a ,2 , b ,2);


}