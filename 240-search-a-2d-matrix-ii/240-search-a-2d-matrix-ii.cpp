class Solution {
public:
    bool binSearch(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int start = 0, end = matrix.size() - 1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target >= matrix[i][0] && target <= matrix[i][cols-1] && binSearch(matrix[i], target)) return true;
        }
        
        return false;
    }
};
