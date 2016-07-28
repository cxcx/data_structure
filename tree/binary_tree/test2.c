/*
 * =====================================================================================
 *
 *       Filename:  test2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月12日 16时10分12秒
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
struct a{
    int a ;
};
void change(struct a* p)
{
    (p->a)++;
}
int main()
{
    struct a s;
    s.a = 0;
    printf("%d",sizeof(s));
    struct a *p = &s;
    printf("%d",sizeof(p));
    
//    change(p);
  //  printf("%d",p->a);
    return 0;
}

