//
//  main.cpp
//  Longest_Substring_Without_Repeating
//
//  Created by 黄涛 on 14/11/14.
//  Copyright (c) 2014年 com.turing. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std ;

class Solution {
public:
    int _lengthOfLongestSubstring(string s) {
        map<char,int> _map ;
        const char* pstr = s.c_str() ;
        
        int offset = 0 ;
        int result = 0 ;

        if (s.size() == 0) return 0 ;
        
        while (1)
        {
            if (_map.find (pstr[offset]) == _map.end()) {
                _map[pstr[offset]] = offset ;
            } else {
                if (_map.size() >= result) {
                    result = (int)_map.size() ;
                }
                //cout<<"offser: "<<offset <<" exist_offset: "<<_map[pstr[offset]] <<endl ;
                cout<<" map: "<<_map.size()<<endl;
                
                map<char,int>::iterator it = _map.begin() ;
                int limit = _map[pstr[offset]] ;
                for (; it != _map.end() ;) {
                    if (it->second <= limit) {
                        it = _map.erase(it) ;
                    }else {
                        it++;
                    }
                }
                _map[pstr[offset]] = offset;
                
            }
            if (offset++ == s.size()) {
                if (_map.size() >= result) {
                    result = (int)_map.size() -1 ;
                }
                //cout<<"offser: "<<offset <<" exist_offset: "<<_map[pstr[offset]] <<endl ;
                cout<<" map: "<<_map.size()<<endl;
                
                map<char,int>::iterator it = _map.begin() ;
                int limit = _map[pstr[offset]] ;
                for (; it != _map.end() ;) {
                    if (it->second <= limit) {
                        it = _map.erase(it) ;
                    }else {
                        it++;
                    }
                }
                _map[pstr[offset]] = offset;
                
                break ;
            }
            
        }
        return result ;
    }
    
    
    int accepted_lengthOfLongestSubstring(string s) {
        int index_s = 0;
        int index_e = 0;
        std::map <char,int> _map ;
        int result = -1 ;
        int itmp = 0 ;
        if (s.size()==0) return 0 ;
      
        for (int i = 0 ; i != s.size(); i++)
            _map[s[i]]=-1;
      
       
        while (index_e<s.size()) {
            if (_map[s[index_e]] < 0) {
                _map[s[index_e]] = index_e ;
                 /*
                map<char,int>::iterator it = _map.begin() ;
                cout << "waht in map" << endl ;
                for ( ; it != _map.end() ; it++)
                    cout << it->first << endl ;
                */
                index_e++ ;
            }else{
                
               
    
                result =  index_e-index_s > result ? index_e-index_s : result ;
                itmp = _map[s[index_e]]+1;
                
                for (int i = index_s ; i <= _map[s[index_e]]; i++ )
                    _map[s[i]] = -1 ;
                index_s = itmp ;
            }
        }
        return index_e-index_s > result ? index_e-index_s : result ; ;
    }
    
    //最终版
    int lengthOfLongestSubstring(string s) {
        int index_s = 0;
        int index_e = 0;
        int _map[9999] ;
        int result = -1 ;
        int itmp = 0 ;
        if (s.size()==0) return 0 ;
        
        for (int i = 0 ; i != s.size(); i++)
            _map[s[i]]=-1;
        
        int len = (int)s.size() ;
        while (index_e<len) {
            if (_map[s[index_e]] < 0 || _map[s[index_e]] < index_s) {
                _map[s[index_e]] = index_e ;
                
                index_e++ ;
            }else{
                
                result =  index_e-index_s > result ? index_e-index_s : result ;
                itmp = _map[s[index_e]]+1;
                
                index_s = itmp ;
            }
        }
        return index_e-index_s > result ? index_e-index_s : result ;
    }
};

//todo:两个指针在字符串中偏移，map中得数据直接clear
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution S ;
    cout << S.lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar");
    return 0;
}
