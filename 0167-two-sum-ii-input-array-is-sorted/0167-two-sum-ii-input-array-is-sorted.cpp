class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; // 1-based index as per problem statement
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {}; // return empty if no solution found (optional based on assumptions)
    }
};