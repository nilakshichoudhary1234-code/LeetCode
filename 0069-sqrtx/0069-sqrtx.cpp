class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Handle 0 and 1 immediately
        
        long long left = 1, right = x;
        int ans = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (mid * mid == x) {
                return mid; // Perfect square found
            } else if (mid * mid < x) {
                ans = mid;     // mid could be the potential answer (rounded down)
                left = mid + 1; // Search the right half
            } else {
                right = mid - 1; // Search the left half
            }
        }
        
        return ans;
    }
};