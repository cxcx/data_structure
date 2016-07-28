/*
 * =====================================================================================
 *
 *       Filename:  Tread_BiTree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月24日 18时39分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cx (), cxandmjq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct TBTreeNode{
    element_type data;
    char l_Flag;
    char r_Flag;
    struct TBTreeNode* l_child;
    struct TBTreeNode* r_child;
}TBTreeNode, *TBTree;

enum Tread{link,Tread}; /* link == 0,表示链表，Tread == 1,表示线索 */

TBTreeNode Start;
TBTree pre = &Start;

/*vist element*/
void visit(TBTree T)
{
    printf("%d",T->data);
}

/* Create a new TreadTree which dont have a l_child,will not have a r_child too */
int CreateTBTree(TBTree* T)
{
    element_type c;
    scanf("%d",&c);
    if(c == 0)
    {
        *T = NULL;
        return 0;
    }
      
    else
    {
        if(!(*T = (TBTree)malloc(sizeof(TBTreeNode))))
            exit(EXIT_FAILURE);
        else
        {
            (*T)->data = c;
            if(CreateTBTree(&((*T)->l_child)))
                CreateTBTree(&((*T)->r_child));
            return 1;   
        }      
    }

}

void PreOrderTraverse(TBTree T)
{
    if(T)
    {
        visit(T);
        PreOrderTraverse(T->l_child);
        PreOrderTraverse(T->r_child);
    }
    else
    {
        return;
    }
}
/*先序线索化*/
int PreTreaten(TBTree T)
{
    if(T)
    {
        PreTreaten(T->l_child);
        if(!T->l_child)
        {
           // T->l_Flag = 
        }
    }
}
/*中序线索化 */
void InOrderThreading(TBTree T)
{
    if(T)
    {
        InOrderThreading(T->l_child);
        if(!T->l_child)
        {
            T->l_child = pre;
            T->l_Flag = Tread;
        }
        else 
            T->l_Flag = link;
        if(!pre->r_child)
        {
            pre->r_Flag = Tread;
            pre->r_child = T;
        }
        else
            T->r_Flag = link;
        pre = T;
        InOrderThreading(T->r_child);
    }
}


/* test */
int main()
{
    TBTree T;
    CreateTBTree(&T);
    PreOrderTraverse(T);
    InOrderThreading(T);
    return 0;
}
