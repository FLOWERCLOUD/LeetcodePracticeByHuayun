/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 void quickSort(int* nums,int first,int end){   //快排，不是自己写的
    int temp,l,r;  
    if(first>=end)return;  
    temp=nums[first];  
    l=first;r=end;  
    while(l<r){  
        while(l<r && nums[r]>=temp)r--;  
        if(l<r)nums[l]=nums[r];  
        while(l<r && nums[l]<=temp)l++;  
        if(l<r)nums[r]=nums[l];  
    }  
    nums[l]=temp;  
    quickSort(nums,first,l-1);  
    quickSort(nums,l+1,end);  
}
 /*
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int** result=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6); 
    if(numsSize<3){
        *returnSize = 0;
        return result;
    }
    quickSort(nums , 0 , numsSize -1);
    int top =-1 ;
    int left;
    int right;
    int object; //两个数求和应等于这个值
    for( int i = 0 ;i <numsSize-2 ;++i){
        object = 0-nums[i];
        left = i+1;
        right = numsSize -1;
        while(left<right){
            if(nums[left]+nums[right] > object) right--;
            if(nums[left]+nums[right] < object) left++;
            if(nums[left]+nums[right] == object){
                if(top!=-1){
                    if( (result[top][0]==nums[i])&&(result[top][1]==nums[left]) ){
                    //不加入
                    
                    }else{
						++top;
                        result[top] = (int*)malloc(sizeof(int)*3); 
                        result[top][0] = nums[i];   
                        result[top][1] = nums[left];     //之前把1写出left,2写出right，导致内存泄漏，使得malloc 出现问题
                        result[top][2] = nums[right];    //
                    }
                }else{
					++top;
                    result[top] = (int*)malloc(sizeof(int)*3);
                    result[top][0] = nums[i];
                    result[top][1] = nums[left];
                    result[top][2] = nums[right];
                }
                right--;
                left++;
            }
        }
        
    }
    *returnSize = top+1;
    return result;
   
}
*/
 int** threeSum(int* nums, int numsSize, int* returnSize) {
	 int** result=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6); 
	 if(numsSize<3){
		 *returnSize = 0;
		 return result;
	 }
	 quickSort(nums , 0 , numsSize -1);
	 int top =-1 ;
	 int left;
	 int right;
	 int object; //两个数求和应等于这个值
	 for( int i = 0 ;i <numsSize-2 ;++i){
		 if( (i>00)&&(nums[i]==nums[i-1]))continue;
		 object = 0-nums[i];
		 left = i+1;
		 right = numsSize -1;
		 while(left<right){
			 if(nums[left]+nums[right] > object) right--;
			 else if(nums[left]+nums[right] < object) left++;
			 else if( (left<right)&&(nums[left]+nums[right] == object)){

				 ++top;
				 result[top] = (int*)malloc(sizeof(int)*3);
				 result[top][0] = nums[i];
				 result[top][1] = nums[left];
				 result[top][2] = nums[right];
				 while( nums[left]==nums[left+1])left++;
				 while( nums[right]==nums[right-1])right--;
				 right--;
				 left++;
			 }
		 }

	 }
	 *returnSize = top+1;
	 return result;

 }