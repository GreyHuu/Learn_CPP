/**
2023-10-31 10:33:07
69-x 的平方根 
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int sqrt_middle = x / middle;
            if (sqrt_middle == middle)
                return sqrt_middle;
            else if (sqrt_middle < middle) {
                int middle_1 = middle - 1;
                if (middle_1 > 0) {
                    int sqrt_middle_1 = x / middle_1;
                    if (middle_1 < sqrt_middle_1)
                        return middle_1;
                }
                right = middle - 1;
            } else
                left = middle + 1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.mySqrt(8);
}