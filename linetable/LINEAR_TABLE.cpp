#include <iostream>
#include <cstdlib> 
using namespace std;

#define element_type int
#define INIT_LIST_SIZE 3 			//定义初始化线性表大小
#define Elem_Size 4	
#define LIST_INCREMENT 10				//int类型线性表 

typedef struct{
	element_type *elem;						//表首地址 
	int length;						//表当前长度 
	int list_size;					//每个element长度 
}SqList;

bool InitSqList(SqList &L)			//初始化线性表 	
{ 
	L.elem = (element_type*)malloc(sizeof(element_type)*INIT_LIST_SIZE);
	if(!L.elem)
		return false;
	else
	{
		L.length = 0;
		L.list_size = INIT_LIST_SIZE ; 
		return  true;
	}
}

void AddElement(SqList &L,element_type e)
{
		*(L.elem+L.length*sizeof(element_type)) = e;
		L.length++;	
}

bool InsertElement(SqList &L,element_type e,int i)
{
	if(i <= 0|| i > L.length+1)
		return false;
	else
	{
		if(L.length >= L.list_size)
		{
			element_type* newbase = (element_type*)realloc(L.elem,(L.list_size+LIST_INCREMENT)*sizeof(element_type));
			if(!newbase)
				return false;
			L.elem = newbase;
			L.list_size = L.list_size+LIST_INCREMENT;	
		}
		for(int n = L.length-1 ;n != i-1;n--)
			*(L.elem+n*sizeof(element_type)) = *(L.elem+(n-1)*sizeof(element_type));
		*(L.elem+(i-1)*sizeof(element_type)) = e;

		L.length++;
		return true;
	}
}
bool DELETE_ELEMENT(SqList &L,int i)
{
	if(i > L.length||i<0)
		return false;
	else
	{
		int n = L.length;
		for(;i<n;i++)
			*(L.elem+(i-1)*sizeof(element_type)) = *(L.elem+i*sizeof(element_type));
		L.length--;
		return true;		
	}
} 	

int LOCATE_ELEMENT(SqList &L,element_type e)		//查找第一个等于E的位置 
{
	for(int i = 0;i<L.length;i++)
		if(e == *(L.elem+i*sizeof(element_type)))
			return i+1;
	return -1;
}


//test
int main()
{
	SqList L;
	bool b = InitSqList(L);
	AddElement(L,1);
	AddElement(L,2);
	AddElement(L,4);
	
	//for(int i = 0;i < L.length;i++)
	//	cout<<*(L.elem+i*sizeof(element_type))<<" ";
	//cout<<L.length<<" "<<L.list_size<<endl;
	//cout<<L.elem<<endl;
	//b = InsertElement(L,2,2);
	//cout<<L.elem<<endl;
	//cout<<L.length<<" "<<L.list_size<<endl;
	
	b = DELETE_ELEMENT(L,1);
	
	for(int i = 0;i < L.length;i++)
		cout<<*(L.elem+i*sizeof(element_type))<<" ";
	int a = LOCATE_ELEMENT(L,4);
	int h = LOCATE_ELEMENT(L,5);
	cout<<a<<" "<<h<<endl;
	return 0;
} 