class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //so what we want is - 
        //alternate + and - in the array
        //order of the array should be mainteained 
        //checking if the array begins with positive or negative 
        //STEP 1 - alternate + and - 
        int n = nums.size();
        vector<int> ans (n);
        // this here will be our answer vector 
        //NOTE - Never change the original vector in interview it is not a good practice as in real life we wont be changing the input but manipulating it and getting the desired output 
        //**IDEATION for the problem 1 
        //2 -4 1 2 4 -5 -3 -5
        //point one as read (0)  and other as finder and swaper (1) 
        //2 check the <0 number in ith position using finder
        //swap with swapper 
        // read += 2 
        //swapper += (read +1);
        //this solves first two things**

        //cant swap violates the 2nd rule 
        //swap will not happen it will be pushed into the 


        // lol we can just create vec positive and vec negative and combine them to form the answer 
        // vector<int> pos (n/2);
        // vector<int> neg (n/2);
        // int positive_pos = 0;
        // int negative_pos = 0;
        // for(int i = 0; i < n ; i++){
        //     if(nums[i] > 0) pos[positive_pos++] = nums[i];
        //     else neg[negative_pos++] = nums[i];
        // }

        // for(int j = 0; j < n; j++){
        //     if(j%2 == 0) ans[j] = pos[j/2];
        //     else ans[j] = neg[j/2];
        // }

        // return ans;

        //let's optimize it more --> Most Optimized 
        //we can combine both the steps into one
        int pos = 0;
        int neg = 1;
        for(int read = 0; read < n; read++){
            if(nums[read] > 0) {
                ans[pos] = nums[read];
                pos += 2;
            }
            else {
                ans[neg] = nums[read];
                neg += 2;
            }
        }
        return ans;
    }
};