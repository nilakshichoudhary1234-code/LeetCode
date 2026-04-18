class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the specific overflow case you encountered
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Determine if the result should be negative
        // (true if signs are different)
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to handle absolute values without overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            // Left shift (multiply by 2) until it's too big
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};