/**
2023-10-26 16:35:51
34-在排序数组中查找元素的第一个和最后一个位置
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        if (start == -1) return {-1, -1};
        int end = findLast(nums, target);
        return {start, end};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) return -1;
        return left;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right < 0 || nums[right] != target) return -1;
        return right;
    }
};
//class Solution {
//public:
//    vector<int> searchRange(vector<int> &nums, int target) {
//        int left = 0;
//        int right = nums.size() - 1;
//        int start = -1;
//        int end = -1;
//        while (left <= right) {
//            int middle = left + (right - left) / 2;
//            int middle_num = nums[middle];
//            if (middle_num == target) {
//                start = middle;
//                left = middle;
//                right = middle;
//                break;
//            }
//            if (target > middle_num)
//                left = middle + 1;
//            else
//                right = middle - 1;
//        }
//        if (start != -1) {
//            while (left >= 0 && nums[left] == target) {
//                start = left;
//                left--;
//            }
//            while (right < nums.size() && nums[right] == target) {
//                end = right;
//                right++;
//            }
//        }
//        return {start, end};



//            vector<int> range = {start};
////            向右查找
//            for (int i = start + 1; i < nums.size(); i++)
//                if (nums[i] == target)
//                    range.push_back(i);
////            向左查找
//            for (int i = start - 1; i >= 0; i--)
//                if (nums[i] == target)
//                    range.push_back(i);
//            // 排序
//            std::sort(range.begin(), range.end());
//            vector<int> result = {range.front(), range.back()};
//            return result;
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> input = {1};
    int target = 1;
    Solution solution;
    solution.searchRange(input, target);
}