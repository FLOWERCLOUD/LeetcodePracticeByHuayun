long long mit[] = {1 , 10 ,100 ,1000 ,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
long long comp[] ={ 9 ,99 ,999,9999,99999,999999,9999999,99999999,999999999,9999999999};
#define comp_count  10
bool isPalindrome1(long long x , int bit){ //假设x为正数

	if( 0 == bit)return 0;
	if( 1 == bit)return 1;
	if( 2 == bit)return x/10 == x %10 ? 1: 0;
	if( x/mit[bit-1] == x%10){
		x = x% mit[bit-1];
		x= x/10;
		return isPalindrome1(x,bit-2);
	}
	return 0;
}

bool isPalindrome(int x) {
	if( x<0)return false;
	long long temp = x;
	int count = 0;
	if( 0==temp)return 1; //为0的情况
	int i;
	for( i = comp_count-1 ;i>-1 ;i--){
		if( temp <= comp[i] ){
			count=i+1;
			break;
		}
	}
	return isPalindrome1( x ,count);


}