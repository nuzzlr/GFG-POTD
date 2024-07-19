//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
public:
    vector<int> constructLowerArray(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n);
        int k = n - 2;
        vector<int> arr;
        arr.push_back(a[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int idx = binaryS(arr, a[i], 0, arr.size() - 1);
            ans[k--] = idx;
            arr.insert(arr.begin() + idx, a[i]);
        }
        return ans;
    }

    int binaryS(vector<int>& arr, int key, int l, int h) {
        if (l <= h) {
            int mid = (l+h) / 2;
            if (arr[mid] >= key) {
                return binaryS(arr, key, l, mid - 1);
            }
            return binaryS(arr, key, mid + 1, h);
        }
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends