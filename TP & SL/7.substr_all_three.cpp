class Solution {
    public:
        int numberOfSubstrings(string s) {
            int count = 0 ;
            for(int i = 0 ; i < s.size() ; i++){
                int hash[3] = {0};
                for(int j = i ; j < s.size() ; j++ ){
                    hash[s[j]-'a'] = 1;
    
                    if(hash[0] + hash[1] + hash[2] == 3){
                        count  = count +1;
                    }
               
                }
            }
            return count;
            
        }
    };




















    
    class Solution {
        public:
            int numberOfSubstrings(string s) {
                int count = 0 ;
                for(int i = 0 ; i < s.size() ; i++){
                    int hash[3] = {0};
                    for(int j = i ; j < s.size() ; j++ ){
                        hash[s[j]-'a'] = 1;
        
                        if(hash[0] + hash[1] + hash[2] == 3){
                            count  = count +(s.size()-j);
                            break;
                        }
                   
                    }
                }
                return count;
                
            }
        };
















//above both approaches are brute force 

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numberOfSubstrings(string s) {
            int lastseen[3] = {-1,-1,-1};
            int count  = 0 ;
    
            for(int i = 0 ; i <  s.size(); i++){
                lastseen[s[i]-'a'] = i ;
                if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                    count = count + (1 + min(lastseen[0], min(lastseen[1] , lastseen[2])));
                }
    
    
            }
            return count ;
            
        }
    };