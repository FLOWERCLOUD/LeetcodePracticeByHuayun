/*
#define TRUE 1
#define FALSE 0

int getcharsLen(char* in){
	int count =0;
	char* p = in;
	if( NULL == in)return 0;
	while( *p != '\0'){
		p++;
		count++;
	}
	return count;
}
bool isTwoValid( char left , char right){
	if('(' ==left ) return ')'==right? TRUE : FALSE;
	else if('[' == left) return ']' == right? TRUE:FALSE;
	else if('{' == left) return '}' == right? TRUE:FALSE;
	else return FALSE;
}
bool isValid(char* s) {
	int len = getcharsLen(s);
	if( len%2 != 0)return FALSE;
	int left = 0;
	int right = len -1;
	int leftBorder = len/2;
	int rightBorder = len/2-1;
	for(   ;  left<leftBorder && right>rightBorder ; left++,right--){
		if( !isTwoValid(s[left] , s[right]) ) return FALSE;        
	}
	return true;


}

*/
/*
#define TRUE 1
#define FALSE 0

	int getcharsLen(char* in){
		int count =0;
		char* p = in;
		if( NULL == in)return 0;
		while( *p != '\0'){
			p++;
			count++;
		}
		return count;
}
bool isTwoValid( char left , char right){
	if('(' ==left ) return ')'==right? TRUE : FALSE;
	else if('[' == left) return ']' == right? TRUE:FALSE;
	else if('{' == left) return '}' == right? TRUE:FALSE;
	else return FALSE;
}
bool isValid(char* s) {
	int len = getcharsLen(s);
	if( len%2 != 0)return FALSE;
	int left = 0;
	for(   ;  left < len  ; ){
		if(isTwoValid(s[left] , s[left+1]) ) left+=2;
		else return FALSE;
	}
	return true;


}
*/

#define TRUE 1
#define FALSE 0
typedef struct Node  Node;
typedef struct Stack Stack;
typedef char Item;
struct Node{
	Item data;
	Node* down;
};

struct Stack{
	int size;
	Node* top;
};
Stack *InitStack();  
/*判定是否为空栈*/  
int IsEmpty(Stack *ps);  
/*返回栈顶元素*/  
Node* GetTop(Stack *ps,Item *pitem);  
/*元素入栈*/  
Node* Push(Stack *ps,Item item);  
/*元素出栈*/  
Node* Pop(Stack *ps,Item *pitem);  
Stack *InitStack()  
{  
	Stack *ps = (Stack *)malloc(sizeof(Stack));  
	if(ps!=NULL)  
	{  
		ps->top = NULL;  
		ps->size = 0;  
	}  
	return ps;  
}  
int IsEmpty(Stack *ps)  
{  
	if(ps->top == NULL && ps->size == 0)  
		return 1;  
	else  
		return 0;  
}
Node* GetTop(Stack *ps,Item *pitem)  
{  
	if(IsEmpty(ps)!=1&&pitem!=NULL)  
	{  
		*pitem = ps->top->data;  
	}  
	return ps->top;  
}  
Node* Push(Stack *ps,Item item)  
{  
	Node* pnode = (Node*)malloc(sizeof(Node));  
	if(pnode != NULL)  
	{  
		pnode->data = item;  
		pnode->down = GetTop(ps,NULL);  
		ps->size++;  
		ps->top = pnode;  

	}  
	return pnode;  
}  
Node* Pop(Stack *ps,Item* pitem)  
{  
	Node* p = ps->top;  
	if(IsEmpty(ps)!=1&&p!=NULL)  
	{  
		if(pitem!=NULL)  
			*pitem = p->data;  
		ps->size--;  
		ps->top = ps->top->down;     
		free(p);  
	}  
	return ps->top;  
}  


int getcharsLen(char* in){
	int count =0;
	char* p = in;
	if( NULL == in)return 0;
	while( *p != '\0'){
		p++;
		count++;
	}
	return count;
}
bool isTwoValid( char left , char right){
	if('(' ==left ) return ')'==right? TRUE : FALSE;
	else if('[' == left) return ']' == right? TRUE:FALSE;
	else if('{' == left) return '}' == right? TRUE:FALSE;
	else return FALSE;
}
bool isLeft(char in){
	return '('== in ? TRUE: '['== in? TRUE: '{'==in?TRUE:FALSE;
}
bool isValid(char* s) {
	int len = getcharsLen(s);
	if( len%2 != 0)return FALSE;
	int left = 0;
	Stack *ps = InitStack(); 
	char top;
	if(isLeft(s[0]))Push(ps , s[0]);
	else return FALSE;
	for(int i = 1 ; i<len ; ){
		GetTop(ps , &top);
		if( isTwoValid( top , s[i])){
			Pop(ps , &top);
			i++;
		}else if(isLeft(s[i])){
			Push(ps , s[i]);
			i++;
		}else return FALSE;

	}
	if(IsEmpty(ps))return TRUE;
	else return FALSE;

}