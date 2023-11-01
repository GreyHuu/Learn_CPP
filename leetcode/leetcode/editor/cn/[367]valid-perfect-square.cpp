/**
2023-11-01 16:01:04
367-有效的完全平方数
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        if (num == 1)
            return true;
        while (left <= right) {
            int middle = left + (right - left) / 2;
//            使用double来除  防止去掉小数后成立
            auto q_middle = num / static_cast<double>(middle);
            if (q_middle == middle)
                return true;
            else if (q_middle < middle) {
//                此处是为了避免left==right且为答案的状况   和 while的小于等于   可以二选一
//                auto q_middle_1 = num / static_cast<double>((middle - 1));
//                if (q_middle_1 == (middle - 1))
//                    return true;
                right = middle - 1;
            } else
                left = middle + 1;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    solution.isPerfectSquare(5);
}