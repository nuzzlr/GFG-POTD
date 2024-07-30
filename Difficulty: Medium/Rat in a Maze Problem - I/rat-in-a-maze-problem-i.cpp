//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    void help(vector<vector<int>> &matrix,int n,int i,int j,vector<string> &ans,string temp){
        if(i<0 or j<0 or i==n or j==n or matrix[i][j]==0)return;
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
            return;
        }
        matrix[i][j]=0;
        help(matrix,n,i+1,j,ans,temp+'D');
        help(matrix,n,i-1,j,ans,temp+'U');
        help(matrix,n,i,j+1,ans,temp+'R');
        help(matrix,n,i,j-1,ans,temp+'L');
        matrix[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        help(mat,mat.size(),0,0,ans,"");
        return ans;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends