#include<bits/stdc++.h>
using namespace std;






class Solution {
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int index, 
             vector<vector<int>>& vis, const int (&di)[4], const int (&dj)[4]) {
      if (index == word.size()) return true; 
  
      int m = board.size(), n = board[0].size();
  
      vis[i][j] = 1;
  
      
      for (int d = 0; d < 4; d++) {
        int ni = i + di[d], nj = j + dj[d];
  
        if (ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj] && board[ni][nj] == word[index]) {
          if (dfs(ni, nj, board, word, index + 1, vis, di, dj)) return true;
        }
      }
  
      
      vis[i][j] = 0;
      return false;
    }
  
  public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size(), n = board[0].size();
      vector<vector<int>> vis(m, vector<int>(n, 0));
  
      
      const int di[4] = {+1, 0, 0, -1};
      const int dj[4] = {0, -1, +1, 0};
  
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == word[0]) { 
            if (dfs(i, j, board, word, 1, vis, di, dj)) return true;
          }
        }
      }
      
      return false;
    }
  };