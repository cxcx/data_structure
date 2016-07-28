//
//  string_cx.cpp
//  StringMatching
//
//  Created by JackChen on 7/23/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#include "string_cx.hpp"

int length(char string[])
{
    int i = 0;
    while (string[i++] != '\0');
    return i;
}

location_in_tring match_string(char target_string[], char partten_string[])
{
    location_in_tring loct = 0;
    
    return loct;
}


void next(char partten_string[], int next[])
{
    int len = length(partten_string);
    int k = -1, i = 1;
    next[0] = -1;
    while ( i < len) {
        if (k == -1 || partten_string[i] == partten_string[k]) {
            k = k + 1;
            next[i] = k;
            i = i + 1;
        }
        else
            k = next[i];
    }
}
