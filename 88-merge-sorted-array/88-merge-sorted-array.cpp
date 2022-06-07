class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, it = n+m-1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[it] = nums1[i];
                i--;
                it--;
            } else {
                nums1[it] = nums2[j];
                j--;
                it--;
            }
        }
    }
};
