/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月21日 18时46分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cx (), cxandmjq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
typedef int e_type;
typedef struct BTNode{
    e_type data;
    struct BTNode* l_child;
    struct BTNode* r_child;
}BTNode, *BTree;

/*Create Binary Tree */
int CreateBinaryTree(BTree *T)
{
    int temp;
    scanf("%d",&temp);
    if(temp == 0)
    {
        *T = NULL;
        return 0;
    }
    else
    {
        if(!((*T)=(BTree)malloc(sizeof(BTNode))))
        {
            printf("error");
            return -1;
        }
        (*T)->data = temp;
        if(CreateBinaryTree(&(*T)->l_child))
            CreateBinaryTree(&(*T)->r_child);
    }
    return 1;
}
/* */
int PreOrderTraverse(BTree T,void (*visit)(e_type e))
{
    if(T)
    {
        visit(T->data);
        if(PreOrderTraverse(T->l_child,visit))
            PreOrderTraverse(T->r_child,visit);
    }
    else
        return 0;
    return 1;
}
/*  */
int MidOrderTraverse(BTree T,void (*visit)(e_type e))
{
    if(T)
    {
        if(MidOrderTraverse(T->l_child,visit))
        {
            visit(T->data);       
            MidOrderTraverse(T->r_child,visit);
        }
        else
            visit(T->data);
        return 1;
    }
    else
        return 0;
}
/*  */
int AftOrderTraverse(BTree T,void (*visit)(e_type e))
{
    if(T)
    {
        if(AftOrderTraverse(T->l_child,visit))
        {
            AftOrderTraverse(T->r_child,visit);
            visit(T->data);
        }
        else
            visit(T->data);
        return 1;
    }
    return 0;
}
/* */
void visit(e_type e)
{
    printf("%d",e);
}
/* */

int main() 
{
    BTree T;
    CreateBinaryTree(&T);
    printf("ok");
    PreOrderTraverse(T,visit);
    printf("\n");
    MidOrderTraverse(T,visit);
    printf("\n");
    AftOrderTraverse(T,visit);
    printf("\n");
    return 0;
}


