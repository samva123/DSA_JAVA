#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        //when count of open and close brackets are same then 
        //we have only one choice to put open bracket 
        if(open == close){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else if(open == 0){
            //only choice is to put close brackets 
            string op1 = op;
            op1.push_back(')');
            solve(op1, open, close-1, ans);
        }
        else if(close == 0){
            //only choise is to use open bracket 
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, ans);
            solve(op2, open, close-1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op = "";
        solve(op, open, close, ans);
        return ans;
    }
};









class Solution {
    private:
    void solve(int cnt1,int cnt2,int n,vector<string> &ans,string &op,int ind)
    {
        if(ind>=n*2)
        {
            ans.push_back(op);
            return;}
        if(cnt1<n and ind<n*2-1)
        {
            op+='(';
            solve(cnt1+1,cnt2,n,ans,op,ind+1);
            op.pop_back();
        }
        
        if(cnt2<cnt1 and ind>0)
        {
            op+=')';
 
            solve(cnt1,cnt2+1,n,ans,op,ind+1);
            op.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
         string op="";
        vector<string> ans;
        solve(0,0,n,ans,op,0);
        return ans;
    }
};






















class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        generate(n,0,0,"",s);
        return s;
    }
    void generate(int n,int open,int close,string present,vector<string>&s) {
        if(open==n&&open==close){
            s.push_back(present);
            return;
        }
        if(open<n){
            generate(n,open+1,close,present + "(",s);
        }
        if(close<open){
            generate(n,open,close+1,present + ")",s);
        }
        
    }
};





















class Solution {
public:
    void generate_parenthesis(int opn, int cls, string &path, vector<string> &ans)
    {
        if(opn == 0 && cls == 0)
        {
            ans.push_back(path);
            return;
        }

        if(opn != 0)
        {
            path.push_back('(');
            generate_parenthesis(opn-1, cls, path, ans);
            path.pop_back();
        }

        if( cls - opn >= 1)
        {
            path.push_back(')');
            generate_parenthesis(opn, cls-1, path, ans);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string>ans;
        generate_parenthesis( n, n, path, ans);
        return ans;
    }
};