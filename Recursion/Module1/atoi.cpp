#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int helper(string &s, int i, int num, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return num * sign;
        }
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int i = 0, sign = 1;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        return helper(s, i, 0, sign);
    }
};





class Solution {
public:
    int myAtoi(string s) {
        int num = 0 , i = 0 , sign = 1 ;//+ve
        while(s[i] == ' '){
            i++;
        }
        if(i<s.size() && (s[i] == '-' || s[i] == '+')){
            sign = s[i] == '+' ? 1: -1;
            ++i;
        }

        while(i<s.size() && isdigit(s[i])){
            if(num > INT_MAX/10 || (num == INT_MAX /10 && s[i] > '7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num*10 + (s[i] - '0');
            ++i;


        }
        return num*sign;


        
    }
};