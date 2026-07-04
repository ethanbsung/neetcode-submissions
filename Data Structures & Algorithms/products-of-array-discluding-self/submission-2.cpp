class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> output(n);
        
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for (int j = n - 2; j >= 0; j--) {
            postfix[j] = postfix[j+1] * nums[j + 1];
        }

        for (int k = 0; k < n; k++) {
            output[k] = prefix[k] * postfix[k];
        }

        return output;
    }
};
