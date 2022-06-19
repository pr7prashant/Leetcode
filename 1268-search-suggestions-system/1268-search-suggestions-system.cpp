class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        
        for (int i = 1; i <= searchWord.length(); i++) {
            vector<string> curr;
            string prefix = searchWord.substr(0, i);
            int idx = lower_bound(products.begin(), products.end(), prefix) - products.begin();
            for (int i = 0; i < 3 && idx + i < products.size(); i++) {
                if (products[idx+i].substr(0, prefix.length()) == prefix) {
                    curr.push_back(products[idx+i]);
                }
            }
            res.push_back(curr);
        }
        
        return res;
    }
};
