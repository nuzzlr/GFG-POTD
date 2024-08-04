//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool static comp( pair<int,int>&a, pair<int,int>&b){
        return (a.second<b.second) || (a.second==b.second && a.first<=b.first);
    }
    
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> meet;
        for(int i=0;i<n;i++){
            meet.push_back({start[i],end[i]});
        }
        sort(meet.begin(),meet.end(),comp);
        int ans=1;
        int endTime=meet[0].second;
        for(int i=1;i<n;i++){
            if(endTime< meet[i].first){
                ans++;
                endTime=meet[i].second;
            }
        }
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends