//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by 黄涛 on 15/10/12.
//  Copyright © 2015年 com.turing. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    //96ms v0.1
     /*
    std::string longestPalindrome(std::string s) {
        std::string str_result =s.substr(0,1);
        if (s.length() == 1) return str_result;
        for (int i = 0 ; i != s.length()*2-1 ; i++ ) {
            //printf ("\nstep :%d\n",i);
            int ioffset = 0 ;
            for (;;) {
                ioffset++ ;
                if (i-ioffset <0) break ;
                if (i%2 == 0){
                    //检测单数字符串s
                    int icenter = i/2 ;
                    //printf ("\nicenter:%d\tioffset:%d\n",icenter,ioffset) ;
                    if (icenter+ioffset > s.length()-1) break;
                    if (s.c_str()[icenter-ioffset] != s.c_str()[icenter+ioffset]) {
                        break;
                    }else{
                        if (2*ioffset+1 > str_result.length()) {
                            //printf ("\bget a result, icen:%d, ioffset:%d\n",icenter,ioffset);
                            str_result = s.substr(icenter-ioffset,2*ioffset+1) ;
                        }
                    }
                } else {
                    //检测双数字符串
                    int icenter = i/2 ;
                    if (icenter+ioffset > s.length()-1) break;
                    if (s.c_str()[icenter-ioffset+1] != s.c_str()[icenter+ioffset]) {
                        break;
                    } else {
                        if (2*ioffset > str_result.length()) {
                            str_result = s.substr(icenter-ioffset+1,2*ioffset) ;
                        }
                    }
                }
            }
        }
        
        
        
        return str_result ;
    }
    */
    
    /* 因为加了两个循环 更慢了
    std::string longestPalindrome(std::string s) {
        std::string str_result =s.substr(0,1);
        if (s.length() == 1) return str_result;
        
        long i = s.length();
        for (i ; i!= 0 ; i--){
            s.insert(i,"|") ;
        }
        s.insert(0,"|");
        
        for (int i = 0 ; i != s.length()*2-1 ; i++ ) {
            //printf ("\nstep :%d\n",i);
            int ioffset = 0 ;
            for (;;) {
                ioffset++ ;
                if (i-ioffset <0) break ;
                //检测单数字符串s
                int icenter = i;
                //printf ("\nicenter:%d\tioffset:%d\n",icenter,ioffset) ;
                if (icenter+ioffset > s.length()-1) break;
                if (s.c_str()[icenter-ioffset] != s.c_str()[icenter+ioffset]) {
                    break;
                }else{
                    if (2*ioffset+1 > str_result.length()) {
                        //printf ("\bget a result, icen:%d, ioffset:%d\n",icenter,ioffset);
                        str_result = s.substr(icenter-ioffset,2*ioffset+1) ;
                    }
                } //if
            } // for (;;)
        } //for (int i = 0 ; i != s.length()*2-1 ; i++ )
        
        long j = str_result.length()-1;
        for (j ; j!= 0 ; j--){
            if (j%2==0){
                str_result.replace(j,1,"");
            }
        }
        str_result.replace(0,1,"");
        
        return str_result ;
    }
     */
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;

    std::cout << "result:\t" << s.longestPalindrome("abb") << std::endl ;
    return 0;
}
