//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n=nums.size();
        vector<long long int> ans(n,0);
        int zero=0;
        long long int prod=1;
        for(int i=0;i<n;i++) {
            if( nums[i]==0 ){
                zero++;
            }
            else{
                prod=prod*nums[i];
            }
        }
        
        if(zero>1){
            return ans;
        }
        
        for(int i=0;i<n;i++){
           if(nums[i]==0) ans[i]=prod;
           else if(zero) ans[i]=0;
           else ans[i]=prod/nums[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends