/**
2023-11-09 15:42:12
26-删除有序数组中的重复项
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findValue(vector<int> &nums, int begin, int value) {
        for (begin = begin + 1; begin < nums.size(); begin++) {
            if (value == nums[begin])
                return begin;
        }
        return -1;
    }

    int removeDuplicates(vector<int> &nums) {
//        int slow = 0;
//        for (int fast = 0; fast < nums.size(); fast++) {
//            int current = nums[fast];
//            int find_index = findValue(nums, fast, current);
//            if (find_index == -1) {
//                nums[slow] = current;
//                slow++;
//            }
//        }
//        return slow;
        if (nums.empty()) return 0;
        int k = 1; // 至少有一个不重复的元素
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i]; // 更新不重复的元素
            }
        }
        return k; // 返回唯一元素的数量
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}