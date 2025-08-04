class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev = 0 ; int curr = 1;
        int ab = 0;
        for(int i = 2; i <= n; i++){
            ab = curr + prev;
            prev = curr;
            curr = ab;
        }
        return ab;
    }
};