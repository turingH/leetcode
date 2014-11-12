//
//  main.cpp
//  twosum
//
//  Created by 黄涛 on 14/11/12.
//  Copyright (c) 2014年 com.turing. All rights reserved.
//


/* 标准答案
public int[] twoSum(int[] numbers, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < numbers.length; i++) {
        int x = numbers[i];
        if (map.containsKey(target - x)) {
            return new int[] { map.get(target - x) + 1, i + 1 };
        }
        map.put(x, i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result ;
        map<int,vector<int>> _map ;
        int size = numbers.size() ;
        for (int i = 0 ; i != size ;i++) {
            
            _map[numbers[i]].push_back(i+1);
        }
        
        map<int,vector<int>>::iterator it = _map.begin();
        int num1 =0 ;
        int num2 =0 ;
        for ( ; it != _map.end() ; it++) {
            int key1 = it->first ;
            int key2 = target - key1 ;
            
            if (key1 == key2) {
                if (it->second.size() >= 2) {
                    num1 = it->second[0] ;
                    num2 = it->second[1] ;
                    break ;
                }
            }else {
                if (_map[key2].size()>0) {
                    num1 = _map[key1][0] ;
                    num2 = _map[key2][0] ;
                    break ;
                }
            }
           
        }
            
        if (num1 <= num2) {
            result.push_back(num1);
            result.push_back(num2);
        }else{
            result.push_back(num2);
            result.push_back(num1);
           
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution S ;
    
    vector<int> numbers = {1,2,3,4} ;
    
    vector<int> result = S.twoSum(numbers,5);
    
    for (int i = 0 ; i != 2 ; i++)
        std::cout << result[i] << endl ;
    
    return 0;
}
