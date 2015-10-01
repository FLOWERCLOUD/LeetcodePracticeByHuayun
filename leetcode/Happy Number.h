#define MAXITER 99
int caculateSquare(int in , int* count){
	int sum = 0;
	if( *count > MAXITER)return 0;
	while( 0 != in){
		sum+= (in%10)*(in%10);
		in/=10;
	}
	*count++;
	if( 1==sum)return 1;
	else return caculateSquare(sum ,count);
}
bool isHappy(int n) {
	int count = 0;
	return caculateSquare( n , &count);
}