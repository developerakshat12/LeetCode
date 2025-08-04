class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int sum = 0;

        // Initial window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if ((double)sum / k >= threshold)
            count++;

        // Sliding window
        for (int right = k; right < arr.size(); right++) {
            sum += arr[right];
            sum -= arr[right - k];

            if ((double)sum / k >= threshold)
                count++;
        }

        return count;
    }
};
