class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int waterlvl = 1;
        int ans = 0;
        while (left < right) {
            if (waterlvl > min(height[left], height[right])) {
                if (height[left] > height[right]) {
                    right--;
                } else if (height[left] < height[right]) {
                    left++;
                } else {
                    // equal heights
                    left++;
                    right--;
                }
            }
            area = min(height[left],height[right]) * (right - left);
            ans = max(area, ans);
            waterlvl++;
        }
        return ans;
    }
};