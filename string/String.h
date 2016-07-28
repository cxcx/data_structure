/*
 * =====================================================================================
 *
 *       Filename:  string.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月06日 21时32分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  cx (), cxandmjq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
#define MAXSTRLEN 255
typedef unsigned char String[MAXSTRLEN + 1];

/* Assign a string equal chars */
bool StrAssign(String &T,char* chars);

/* copy S to T */
bool StrCopy(String &T,String S);

/*Empty String s*/
bool StrEmpty(String S);

/* compare T with S,if T > S,return value > 0,if T == S,return value = 0,else return value < 0*/
int StrCompare(String T,String S);

/* return the num of the String s */
int StrLength(String S);

/*Clear String S*/
void ClearString(String &S);

/*link String S1 and S2 to get a new String T */
bool Concat(String& T, String S1, String s2);

/*get a new string which is from the pos-th,and it's length == len*/
bool SubString(String &Sub, String S, int pos, int len);

/* if S is contained by T,then return the first character's position pos, S is smaller than T*/
bool Index(String S, String T, int& pos);

/*Index() use KMP */
bool Index_KMP(String S, String T, int& pos);

/*Destroy the String S*/
bool DestroyString(String& S);

/*replace T which appear in S with V */
bool StrReplace(String &S, String T, String V);

/*insert T into S at the posion posth */
bool StrInsert(String &S, int pos, String T);

/*delete string T which appreas in S*/
bool StrDelete(String &S, String T);

