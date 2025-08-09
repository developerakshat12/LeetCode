class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(nums[start] == 0 || nums[end] == 2){
            if(nums[start] == 0) ++start;
            if(nums[end] == 2) --end;
            if(start > end) {
                return;
            }
        }

        for(int read = start; read <= end ; ){
            if(nums[read] == 2){
                swap(nums[read],nums[end]);
                --end;
            }
            else if(nums[read] == 0){
                swap(nums[read],nums[start]);
                ++start;
                ++read;
            }
            else ++read;
        }

    }
};