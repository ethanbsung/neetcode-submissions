class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        kth = k;
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > kth) heap.pop();
        return heap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int kth;
};
