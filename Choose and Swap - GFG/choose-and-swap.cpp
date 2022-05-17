// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        vector<int> pos(128, -1);
        for (int i = 0; i < a.length(); i++) {
            if (pos[a[i]] == -1) pos[a[i]] = i;
        }
        
        char ch1, ch2;
        bool found = false;
        for (char ch : a) {
            ch1 = ch;
            for (int j = 'a'; j < ch1; j++) {
                if (pos[j] > pos[ch1]) {
                    ch2 = j;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        
        if (!found) return a;
        
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == ch1) a[i] = ch2;
            else if (a[i] == ch2) a[i] = ch1;
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends