#include <algorithm>

class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        // A value of 1 cannot be GCD-connected to any other element
        if (value == 1) {
            return -1;
        }

        // Find the smallest prime factor of value
        int p = value;
        for (int i = 2; (long long)i * i <= value; ++i) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        // Check if there is enough space for valid elements on the left
        // The left needs `index` elements, requiring value - p >= 2 * index
        if ((long long)value - p < 2LL * index) {
            return -1;
        }

        // Number of elements to the right of `index`
        long long t = (long long)n - index - 1;
        
        if (t == 0) {
            return value;
        }

        // Minimum value at the end of the array
        return (long long)value + p + 2 * (t - 1);
    }
};