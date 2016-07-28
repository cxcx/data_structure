/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 18时54分46秒
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

int change(int **p)
{
    if((*p = (int)malloc(sizeof(int))))
    {
        **p = 10;
        return 1;
    }
    else
        return 0;
}
int main()
{
    int *p;
    printf("%d\n",change(&p));
    printf("%d\n",*p);
    return 0;
}

