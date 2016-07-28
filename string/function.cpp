/*
 * =====================================================================================
 *
 *       Filename:  function.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月06日 23时08分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cx (), cxandmjq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "String.h"
int StrLength(String S)
{
    int i = 0;
    for(;S[i] != '\0';i++);
    return i;
}

bool Index(String S,String T,int& pos)
{
    int len_s = StrLength(S);
    int len_t = StrLength(T);
    for(int i = 0; i < len_t; i++)
    {
       int num = 0;
       if(T[i] == S[0])
         {
             for(int j = 0; j < len_s;j++)
             {
                if(S[j] == T[i+j])
                    num++;
                else
                    num = 0;
             }
             if(num == len_s)
             {
                pos = i+1;
                return true;
             }
         }
      else  if(i == len_t -1)
           return false;
    }
}

bool Index_KMP(String S, String T, int &pos)
{
        
}


bool Concat(String& T, String S1, String S2)
{
    if(StrLength(S1) == 0 && StrLength(S2) == 0)
        return false;
    if(StrLength(S1)+StrLength(S2) <= MAXSTRLEN)
    {
        for(int i = 0; i < StrLength(S1)+StrLength(S2); i++)
        {
            if(i < StrLength(S1))
                T[i] = S1[i];
            else
                T[i] = S2[i-StrLength(S1)];
        }
    }
    /*cut the s2 */
    else if(StrLength(S1) <= MAXSTRLEN)
    {
        for(int i = 0; i<MAXSTRLEN;i++)
        {
            if(i < StrLength(S1))
                T[i] = S1[i];
            else
                T[i] = S2[i-StrLength(S1)];
        }
    }
    return true;
}

void ClearString(String &S)
{
    for(int i = 0;i<StrLength(S);i++)
        S[i]= ' ';
}

bool StrEmpty(String S)
{
    if(StrLength(S) == 0)
        return true;
    else
        return false;
}

bool StrCopy(String &T, String S)
{
    ClearString(T);
    for(int i = 0; i<StrLength(S); i++)
        T[i] = S[i];
}

int StrCompare(String T, String S)
{
    if(StrLength(T) == StrLength(S))
        return 0;
    if((StrLength(T) > StrLength(S)))
        return 1;
    if(StrLength(T) < StrLength(S))
        return -1;
}

bool SubString(String &sub, String S, int pos, int len)
{
    if(StrLength(S) < pos+len)
        return false;
    if(!StrEmpty(sub))
        ClearString(sub);
    for(int i = 0;i<len;i++)
        sub[i] = S[i+pos-1];
    return true;
}

bool StrInsert(String &S, int pos, String T)
{
    if(StrLength(S)+StrLength(T) > MAXSTRLEN)
        return false;
    for(int i = StrLength(S); i> pos; i--)
        S[i+StrLength(T)-1] = S[i-1];
    for(int i = 0; i < StrLength(T); i++)
        S[pos+i-1] = T[i];
    return true;
}
bool StrDelete(String &S, String T)
{
    int pos = 0;
    if(Index(T,S,pos))
    {
        for(int i = pos; i<StrLength(S);i++)
            S[i-1] = S[i+StrLength(T)-1];
        return true;
    }
    return false;
}

bool StrReplace(String &S, String T, String V)
{
    if(StrLength(S) - StrLength(T) + StrLength(V) > MAXSTRLEN)
        return false;
    int pos = 0;
    if(Index(T,S,pos))
    {
        StrDelete(S,T);
        StrInsert(S,pos,V);
        return true;
    }
    return false;

        return true;

}
