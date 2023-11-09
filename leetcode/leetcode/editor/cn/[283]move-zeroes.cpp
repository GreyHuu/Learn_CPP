/**
2023-11-09 15:59:43
283-移动零
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
//        int slow = 0;
//        for (int fast = 0; fast < nums.size(); fast++) {
//            if (nums[fast] != 0) {
//                nums[slow] = nums[fast];
//                slow++;
//            }
//        }
//        for (; slow < nums.size(); ++slow) {
//            nums[slow] = 0;
//        }
        int non_zero_index = 0; // 非零元素应该放置的位置
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
//                确实应该使用交换更加合适一点
                std::swap(nums[non_zero_index++], nums[i]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}