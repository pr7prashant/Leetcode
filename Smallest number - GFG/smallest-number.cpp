// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D) {
        if (S > D * 9) return "-1";
        
        string ans = "";
        int remainingDigits = D;
        while (D-- > 0) {
            remainingDigits--;
            if (remainingDigits * 9 >= S) {
                if (ans == "") {
                    ans = "1";
                    S -= 1;
                } else {
                    ans += "0";
                }
            } else {
                int num = S - (remainingDigits * 9);
                ans += to_string(num);
                S -= num;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends