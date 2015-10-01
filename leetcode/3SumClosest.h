#define distance1(x,y)  (x)>(y)?((x)-(y)):((y)-(x)) 

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


int threeSumClosest(int* nums, int numsSize, int target) {
	quickSort(nums , 0 , numsSize -1);   
	int left;
	int right;
	int distance = 9999;
	int cloest_target;
	int object; //两个数求和应等于这个值
	int k;
	for( int i = 0 ;i <numsSize-2 ;++i){
		if( (i>0)&&(nums[i]==nums[i-1]))continue;
		object = target-nums[i];
		left = i+1;
		right = numsSize -1;
		while(left<right){
			if(nums[left]+nums[right] > object) {
				k= distance1(nums[left]+nums[right] ,object);
				if(  k < distance){
					distance = distance1(nums[left]+nums[right] ,object);
					cloest_target = nums[i]+ nums[left]+nums[right];
				}  
				right--;

			}
			else if(nums[left]+nums[right] < object){
				k= distance1(nums[left]+nums[right] ,object);
				if( k < distance){
					distance = distance1(nums[left]+nums[right] ,object);
					cloest_target = nums[i]+ nums[left]+nums[right];
				}  
				left++;
			} 
			else if( (left<right)&&(nums[left]+nums[right] == object)){
				return target;
			}
		}
	}
	return cloest_target;
}
