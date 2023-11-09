/**
2023-11-09 16:57:35
977-有序数组的平方
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> result(n);
        int left = 0, right = n - 1;
        int index = n - 1;
        while (left <= right) {
//            因为原数组是非递减的  所以最大的数一定在两端
            if (abs(nums[left]) > abs(nums[right])) {
                result[index--] = nums[left] * nums[left];
                left++;
            } else {
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}