#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    
	    vector<int> arr(n);
	    for (int i = 0; i < n; i++) cin >> arr[i];
	    
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            
            if (pq.size() > k) {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        
        cout << endl;
	}
	
	return 0;
}
