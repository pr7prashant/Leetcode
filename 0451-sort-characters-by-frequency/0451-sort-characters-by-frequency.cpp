class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> arr(128, {0,0});
        for (char ch : s) {
            int offset = isupper(ch) ? 65 : 97;
            char start = isupper(ch) ? 'A' : 'a';
            arr[ch - start + offset].first++;
            arr[ch - start + offset].second = ch;
        }
        sort(arr.begin(), arr.end(), greater<pair<int,char>>());
        string ans = "";
        for (pair<int,char>& p : arr) {
            for (int i = 0; i < p.first; i++) ans += p.second;
        }
        return ans;
    }
};