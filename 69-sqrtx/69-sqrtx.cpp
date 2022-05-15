class Solution {
public:
    int mySqrt(int x) {
        // Newton's Method
        long r = x;
        
        while (r*r > x)
            r = (r + x/r) / 2;
        
        return r;
        
        // Binary Search
        // int start = 1, end = x;
        
        // while (start <= end) {
        //     int mid = start + ((end - start) >> 1);
            
        //     if (mid == x/mid) return mid;
            
        //     if (mid > x/mid) end = mid - 1;
        //     else start = mid + 1;
        // }
        
        // return end;
    }
};
