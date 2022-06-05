// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string> res;
    
    void helper(string& S, int start, string curr) {
        if (start == S.length()) return res.push_back(curr);
        
        helper(S, start + 1, curr + " " + S[start]);
        helper(S, start + 1, curr + S[start]);
    }
    
    vector<string> permutation(string S){
        helper(S, 1, S.substr(0, 1));
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends