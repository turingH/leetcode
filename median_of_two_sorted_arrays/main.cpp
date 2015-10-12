//
//  main.cpp
//  median_of_two_sorted_arrays
//
//  Created by 黄涛 on 14/11/12.
//  Copyright (c) 2014年 com.turing. All rights reserved.
//

#include <iostream>
#include <map>
#include <bitset>
using namespace::std ;


class Solution {
public:
    //使用bitset的实现
    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        bitset<1024> bitvec;
        for (int i = 0 ; i < m or i < n ; i++) {
            if (i<m)
                bitvec.set(A[i]);
            if (i<n)
                bitvec.set(B[i]);
        }
        
        int min = 0;
        if (m==0) {
            min = B[0] ;
        } else if (n == 0) {
            min = A[0];
        } else {
            min = A[0]<B[0] ? A[0] : B[0] ;
        }
        
        int key1 = -1 ;
        int key2 = -1 ;
        int value1 = 0 ;
        int value2 = 0 ;
        
        if ((m+n) % 2 == 0) {
            key1 = (m+n)/2 ;
            key2 = key1 +1 ;
        }else{
            key1 = (m+n+1)/2 ;
        }
        
        int offset = 0 ;
        for (int i = min ; i != 1024 ; i++) {
            if (bitvec.test(i) && offset++) {
                if (key1 == offset) {
                    value1 = i ;
                    if (key2 == -1) {
                        break ;
                    }
                }
                if (key2 == offset) {
                    value2 = i ;
                    break ;
                }
                
            }
        }
        
        return key2 == -1 ? value1 : (value1+value2 )/2.0 ;
    }
    
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        int steps = ((m + n)/2.0+0.5) ;
        int offset = (m + n) % 2 == 0 ? 1 : 0 ;

        int h_a = -1 ;
        int h_b = -1 ;
        
        
        
        int h_index = 0 ; // 0代表a 1代表b
        
        while (1) {
            int tmp_a = -1 ;
            int tmp_b = -1 ;
            
            if ((m-1) > h_a)
                tmp_a = A[h_a+1] ;
            if ((n-1) > h_b)
                tmp_b = B[h_b+1] ;
            
            if (tmp_a*tmp_b>0) {
                if (tmp_a < tmp_b) {
                    h_index = 0 ;
                }else if (tmp_a > tmp_b){
                    h_index = 1 ;
                } else {
                    if (A[h_a+2] <= B[h_b+2]) {
                        h_index = 0 ;
                    } else {
                        h_index = 1 ;
                    }
                }
            } else {
                h_index = tmp_a != -1 ? 0:1;
            }
            
            
            
            if (h_index == 0) {
                h_a++ ;
            } else {
                h_b++ ;
            }

            if (--steps<=0) {
                break ;
            }
        }
    
        double num1,num2 ;
        if (h_index==0) {
            num1 = A[h_a] ;
        } else {
            num1 = B[h_b] ;
        }
        
        if (offset>0) {
            int tmp_a = -1 ;
            int tmp_b = -1 ;
            
            if ((m-1) > h_a)
                tmp_a = A[h_a+1] ;
            if ((n-1) > h_b)
                tmp_b = B[h_b+1] ;
            
            if (tmp_a*tmp_b>0) {
                if (tmp_a < tmp_b) {
                    h_index = 0 ;
                }else if (tmp_a > tmp_b){
                    h_index = 1 ;
                } else {
                    if (A[h_a+2] <= B[h_b+2]) {
                        h_index = 0 ;
                    } else {
                        h_index = 1 ;
                    }
                }
            } else {
                h_index = tmp_a != -1 ? 0:1;
            }
            
            if (h_index == 0) {
                h_a++ ;
            } else {
                h_b++ ;
            }
            
            if (h_index==0) {
                num2 = A[h_a] ;
            } else {
                num2 = B[h_b] ;
            }
            
            double sum = (num1 + num2)/2.0 ;
            return sum ;
        }else{
            return num1 ;
        }
                
        return 0.0 ;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution S ;
    int A[] ={} ;
    int B[] ={1} ;
    //std::cout << S.findMedianSortedArrays1 (A,1,B,1) <<endl ;
    std::cout << S.findMedianSortedArrays2 (A,0,B,1) <<endl ;
    return 0;
}
