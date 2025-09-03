class Solution {
public:
    int pivotInteger(int n) {
        int low= 1 , high = n ; 
        while(low <= high){
            int mid = low + ((high - low ) / 2) ;
            long long diff = n*(n+1) - (mid*(mid-1));
            if(mid*(mid+1) == diff ){
                return mid ; 
            }
            else{
                mid*(mid+1) < diff ? low = mid + 1 : high = mid - 1 ; 
            }

        }
        return -1 ;
    }
};