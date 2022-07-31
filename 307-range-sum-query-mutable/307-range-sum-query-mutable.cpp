class NumArray {
public:
    int size;
    vector<int> tree;
    
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree = vector<int>(size * 4, 0);
        buildSegmentTree(nums, 0, 0, size - 1);
    }
    
    void buildSegmentTree(vector<int>& nums, int idx, int start, int end) {
        if (start == end) {
            tree[idx] = nums[start];
            return;
        }
        
        int mid = (start + end) / 2;
        buildSegmentTree(nums, 2*idx+1, start, mid);
        buildSegmentTree(nums, 2*idx+2, mid+1, end);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    
    int query(int idx, int start, int end, int left, int right) {
        if (start >= left && end <= right) return tree[idx];
        if ((start < left && end < left) || (start > right && end > right)) return 0;
        
        int mid = (start + end) / 2;
        int l = query(2*idx+1, start, mid, left, right);
        int r = query(2*idx+2, mid+1, end, left, right);
        return l + r;
    }
    
    int updateNode(int idx, int target, int val, int start, int end) {
        if (start == end) {
            if (start != target) return 0;
            int old = tree[idx];
            tree[idx] = val;
            return val - old;
        }
        if (end < target || start > target) return 0;
        
        int mid = (start + end) / 2;
        int l = updateNode(2*idx+1, target, val, start, mid);
        int r = updateNode(2*idx+2, target, val, mid+1, end);
        int old = tree[idx];
        tree[idx] += l + r;
        return tree[idx] - old;
    }
    
    void update(int index, int val) {
        updateNode(0, index, val, 0, size - 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, size-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
