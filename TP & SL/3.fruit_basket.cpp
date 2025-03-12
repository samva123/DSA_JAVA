//#Self Explanatory  from bute force to all the way optimised

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        int maxFruits = 0;
        
        //O(n*n) time ans constant space 
        
        for(int i = 0; i < n ; i++ ){
            set<int> st;
            for(int j = i; j < n; j++ ){
                st.insert(arr[j]);
                if(st.size() <= 2){
                    maxFruits = max(maxFruits, (j - i) + 1);
                }else{
                    break;
                } 
            }
        }
        return maxFruits;













        
        // O(n + n) time and constant space  i.e. 3 max size map
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        while(j < n ){
            mp[arr[j]]++;
            if(mp.size() <= 2){
                maxFruits = max(maxFruits, j - i + 1);
            }else {
                while(mp.size() > 2){
                    mp[arr[i]] --;
                    if(mp[arr[i]] == 0){
                        mp.erase(arr[i]);
                        
                    }
                    i++;
                }
            }
            j++;
        }
        
        return maxFruits;







        






        
        
        //O(n) time and constant space
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        while( j < n ){
            mp[arr[j]] ++ ;
            if(mp.size() <= 2 ){
                maxFruits = max(maxFruits, j - i + 1);
            }else{
                mp[arr[i]]--;
                if(mp[arr[i]] == 0 ){
                    mp.erase(arr[i]);
                    
                }
                ++i;
            }
            j++;
        }
        return maxFruits;
        
    }    
};


















//////////////////////////////////////////////////////////////////////////










//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends