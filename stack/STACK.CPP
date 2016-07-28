#include <stdlib.h>
#define INIT_STACK_SIZE 12						//��ʼ��ջ��С 
#define STACK_INCREMENT 10						//ջ����������С 
#define ELEMENT_TYPE int						//ջԪ������ 
typedef struct{
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* top;
	int Stack_Size;
}Stack;

bool INIT_STACK(Stack &S)						//��ʼ��ջ 
{
	S.base = (ELEMENT_TYPE*)malloc(sizeof(ELEMENT_TYPE)*INIT_STACK_SIZE);
	if(!S.base)
		return false;
	S.top = S.base;
	S.Stack_Size = INIT_STACK_SIZE;
	return true;
}
ELEMENT_TYPE GET_TOP(Stack S)					//��ȡջ��Ԫ�ز�����Ԫ��ֵ 
{
	if(S.base == S.top)
		return 0;
	else
		return *(S.top-1);
}
bool PUSH(Stack &S,ELEMENT_TYPE e)				//ѹ��Ԫ��e��ջ	
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
ELEMENT_TYPE POP(Stack &S)						//��ջ ������ջ��Ԫ��ֵ 
{
	return 	*--S.top;
}