class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};


/*
    We want to find/return the kth largest integer in a stream of values, including duplicates.
    Implement the constructor - Use min heap to store the k largest values in the stream.
    min heap of size k
    Add will add the integer val to the min heap and return the kth largest integer - top() of min heap (since it is size k)
*/