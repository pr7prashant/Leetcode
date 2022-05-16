// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
	    vector<pair<int, int>> arr;
	    for (int i = 0; i < nums.size(); i++) arr.push_back({nums[i], i});
	    
	    sort(arr.begin(), arr.end());
	    int ans = 0;
	    vector<bool> visited(arr.size(), false);
	    for (int i = 0; i < arr.size(); i++) {
	        if (visited[i] || i == arr[i].second) continue;
	        
	        int j = i, cycle_len = 0;
	        while (!visited[j]) {
	            visited[j] = true;
	            cycle_len++;
	            j = arr[j].second;
	        }
	        
	        ans += cycle_len - 1;
	    }
	    
	    return ans;
	}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends