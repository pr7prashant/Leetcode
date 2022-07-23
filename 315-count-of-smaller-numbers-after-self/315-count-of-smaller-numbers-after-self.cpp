class Solution {
public:
    void merge(vector<pair<int,int>>& nums, int start, int end, int mid, vector<int>& result) {
        vector<pair<int,int>> left, right;
        for (int i = start; i <= mid; i++) left.push_back(nums[i]);
        for (int i = mid+1; i <= end; i++) right.push_back(nums[i]);
        
        int i = 0, j = 0, k = start;
        while (i < left.size() && j < right.size()) {
            if (left[i].first > right[j].first) {
                result[left[i].second] += right.size() - j;
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        
        while (i < left.size()) nums[k++] = left[i++];
        while (j < right.size()) nums[k++] = right[j++];
    }
    
    void mergeSort(vector<pair<int,int>>& nums, int start, int end, vector<int>& result) {
        if (start >= end) return;
        
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid, result);
        mergeSort(nums, mid+1, end, result);
        merge(nums, start, end, mid, result);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums.size(); i++) arr.push_back({ nums[i], i });
        mergeSort(arr, 0, arr.size() - 1, result);
        return result;
    }
};
