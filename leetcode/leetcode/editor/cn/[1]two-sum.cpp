/* 
2023-10-25 16:34:32
1-两数之和
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target)
                    return {i, j};
            }
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution solution;
    solution.twoSum(nums, target);
}