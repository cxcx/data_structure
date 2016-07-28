/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月07日 18时31分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cx (), cxandmjq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "String.h"
int main()
{
    String s = "hellocx";
    String c ="mjq";
    String b = "cx";
    cout<<s<<endl;
    StrReplace(s,b,c);
    cout<<s<<endl;
    return 0;
}

