//
//  string_cx.hpp
//  StringMatching
//
//  Created by JackChen on 7/23/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#ifndef string_cx_hpp
#define string_cx_hpp

#include <stdio.h>
typedef int location_in_tring;

int length(char string[]);
location_in_tring match_string(char target_string[], char partten_string[]);

#endif /* string_cx_hpp */
