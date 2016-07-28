#include <iostream>
#define element_type int

using namespace std;

typedef struct CircularLinkedList{
	element_type data;
	struct CircularLinkedList* next;
}CircularLinkedList,*P_CircularLinkedList;

bool CreatCircularLinkedList(P_CircularLinkedList &L,int n)
{
	L = (P_CircularLinkedList)malloc(sizeof(CircularLinkedList));
	L->next = NULL;
	for(int i = 0;i < n;i++)
	{
		P_CircularLinkedList p = (P_CircularLinkedList)malloc(sizeof(CircularLinkedList));
		if(!p)
			return false;
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
	return true;
}
bool GetElement(P_CircularLinkedList &L,)

int main()
{
	P_CircularLinkedList L = NULL;
	bool b = CreatCircularLinkedList(L,3);
	return 0;	
}