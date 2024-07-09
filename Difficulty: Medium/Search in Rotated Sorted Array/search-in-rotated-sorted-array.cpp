//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = (low + high)/2;
            
            if(arr[mid] > arr[high]){
                if(key > arr[mid] || key <= arr[high])
                    low = mid + 1;
                else
                    high = mid;
            }else{
                if(key > arr[mid] && key <= arr[high])
                    low = mid + 1;
                else 
                    high = mid;     
            }
        }
        if(low == high && key != arr[low])
            return -1;
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends