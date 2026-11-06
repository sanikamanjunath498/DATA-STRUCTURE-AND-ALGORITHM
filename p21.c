#include <limits.h>

int reverse(int x) {
    int rev = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        
        // Check for positive overflow (INT_MAX is 2147483647)
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        
        // Check for negative underflow (INT_MIN is -2147483648)
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        
        rev = rev * 10 + digit;
    }
    
    return rev;
}
