class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
                if (nums.empty()) return 0;

        int* write = nums.data() + 1;
        int* read = nums.data() + 1;
        int* prev = nums.data();

        while (read < nums.data() + nums.size()) {
            if (*read != *prev) {
                *write = *read;
                ++write;
            }
            prev = read;
            ++read;
        }

        return write - nums.data(); // new length
    }
};