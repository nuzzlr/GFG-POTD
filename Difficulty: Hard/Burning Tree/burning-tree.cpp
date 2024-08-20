//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void mapParents(Node* root, unordered_map<Node*, Node*>& parentTrack, Node*& targetNode, int target) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) {
                targetNode = current;
            }
            
            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentTrack;
        Node* targetNode = nullptr;
        mapParents(root, parentTrack, targetNode, target);
        
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            
            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();
                
                if (current->left && visited.find(current->left) == visited.end()) {
                    flag = true;
                    visited.insert(current->left);
                    q.push(current->left);
                }
                
                if (current->right && visited.find(current->right) == visited.end()) {
                    flag = true;
                    visited.insert(current->right);
                    q.push(current->right);
                }
                
                if (parentTrack[current] && visited.find(parentTrack[current]) == visited.end()) {
                    flag = true;
                    visited.insert(parentTrack[current]);
                    q.push(parentTrack[current]);
                }
            }
            
            if (flag) {
                ++time;
            }
        }
        
        return time;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends