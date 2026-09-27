#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------- Memoization ----------------

    int solveMemo(int i, int j, vector<vector<int>>& grid,
                  vector<vector<int>>& dp) {

        if(i>=0 && j>=0 && grid[i][j]==1)
            return 0;

        if(i==0 && j==0)
            return 1;

        if(i<0 || j<0)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int up = solveMemo(i-1,j,grid,dp);
        int left = solveMemo(i,j-1,grid,dp);

        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstaclesMemo(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solveMemo(m-1,n-1,obstacleGrid,dp);
    }



    // ---------------- Tabulation ----------------

    int uniquePathsWithObstaclesTab(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }

                int up=0,left=0;

                if(i>0)
                    up=dp[i-1][j];

                if(j>0)
                    left=dp[i][j-1];

                dp[i][j]=up+left;
            }
        }

        return dp[m-1][n-1];
    }



    // ---------------- Space Optimization ----------------

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        vector<int> prev(n,0);

        for(int i=0;i<m;i++){

            vector<int> temp(n,0);

            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    temp[j]=0;
                    continue;
                }

                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }

                int up=0,left=0;

                if(i>0)
                    up=prev[j];

                if(j>0)
                    left=temp[j-1];

                temp[j]=up+left;
            }

            prev=temp;
        }

        return prev[n-1];
    }
};



int main() {

    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    Solution obj;

    cout<<"Memoization: "
        <<obj.uniquePathsWithObstaclesMemo(grid)<<endl;

    cout<<"Tabulation: "
        <<obj.uniquePathsWithObstaclesTab(grid)<<endl;

    cout<<"Space Optimization: "
        <<obj.uniquePathsWithObstacles(grid)<<endl;
}