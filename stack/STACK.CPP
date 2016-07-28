#include <stdlib.h>
#define INIT_STACK_SIZE 12						//初始化栈大小 
#define STACK_INCREMENT 10						//栈满后增长大小 
#define ELEMENT_TYPE int						//栈元素类型 
typedef struct{
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* top;
	int Stack_Size;
}Stack;

bool INIT_STACK(Stack &S)						//初始化栈 
{
	S.base = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE)*INIT_STACK_SIZE);
	if(!S.base)
		return false;
	S.top = S.base;
	S.Stack_Size = INIT_STACK_SIZE;
	return true;
}
ELEMENT_TYPE GET_TOP(Stack S)					//获取栈顶元素并返回元素值 
{
	if(S.base == S.top)
		return 0;
	else
		return *(S.top-1);
}
bool PUSH(Stack &S,ELEMENT_TYPE e)				//压入元素e入栈	
{
	if(S.top-S.base >= S.Stack_Size)
	{
		S.base = (ELEMENT_TYPE*)realloc(S.base,sizeof(ELEMENT_TYPE)*(S.Stack_Size+STACK_INCREMENT));
		if(!S.base)
			return false;
		else
		{
			S.top = S.base+S.Stack_Size;
			S.Stack_Size += STACK_INCREMENT;
		}
	}
	*S.top++ = e;
	return true;
}
ELEMENT_TYPE POP(Stack &S)						//出栈 并返回栈顶元素值 
{
	return 	*--S.top;
}
