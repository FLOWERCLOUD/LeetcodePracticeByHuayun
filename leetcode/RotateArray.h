void rotate(int* nums, int numsSize, int k) {
	if( NULL == nums) return;
	if( 0 == numsSize ) return;
	if( 1 == numsSize) return;
	if( k >= numsSize) k= k% numsSize;
	int* tmp = (int*)malloc( sizeof(int)* numsSize);
	memcpy( tmp ,nums+numsSize-k , k*sizeof(int));
	memcpy( tmp+k , nums ,(numsSize-k)* sizeof(int));
	memcpy( nums , tmp ,(numsSize)* sizeof(int));
	free(tmp);
	return ;
}