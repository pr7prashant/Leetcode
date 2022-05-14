class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        
        if (s1 > s2) return findMedianSortedArrays(nums2, nums1);
        
        int start = 0, end = s1;
        
        while (start <= end) {
            int mid1 = (start + end) / 2;
            int mid2 = (s1 + s2 + 1) / 2 - mid1;
            
            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int r1 = mid1 == s1 ? INT_MAX : nums1[mid1];
            int r2 = mid2 == s2 ? INT_MAX : nums2[mid2];
            
            if (l1 <= r2 && l2 <= r1) {
                if ((s1 + s2) & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                end = mid1 - 1;
            } else if (l2 > r1) {
                start = mid1 + 1;
            }
        }
        
        return 0.0;
    }
};
