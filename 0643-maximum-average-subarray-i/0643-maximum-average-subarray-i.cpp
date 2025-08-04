class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxAvg = sum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, sum);
        }

        return maxAvg / k;
    }
};
