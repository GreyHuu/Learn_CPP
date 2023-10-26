/**
2023-10-25 16:44:31
2-两数相加
*/
/**
 * 目前问题  就是只能处理四位数字  ==> 需要将固定的四位结果扩展为自适应的
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> result = addTwoNumber(l1, l2);
        int index = result.size() - 1;
        for (int i = result.size() - 1; i > 0; i--) {
            if (index == i && result[i] == 0) {
                index--;
                continue;
            } else
                break;
        }
        result.resize(index + 1);
        auto *start = new ListNode();
        ListNode *end;
        for (int i = 0; i < result.size() - 1; i++) {
            if (i == 0) {
                start->val = result[i];
                start->next = new ListNode(result[i + 1]);
                end = start->next;
                end->next = nullptr;
            } else {
                end->next = new ListNode(result[i + 1]);
                end = end->next;
                end->next = nullptr;
            }
        }
        return start;
    }

    /**
     * 当前位置的加法器
     * @param num1
     * @param num2
     * @return  如果相加超过10则返回 {num-10,1,0,0},否则返回{num,0,0,0}
     */
    static vector<int> add(int &num1, int &num2) {
        int result = num1 + num2;
        if (!isOneToNine(result))
            return {(result - 10), 1, 0, 0};
        else
            return {result, 0, 0, 0};
    }

    /**
     * 判断是否在0~9
     * @param num
     * @return
     */
    static bool isOneToNine(int &num) {
        if (0 <= num && num <= 9)
            return true;
        return false;
    }

    /**
     * 递归的计算每一位两者相加
     * @param l1
     * @param l2
     * @return
     */
    vector<int> addTwoNumber(ListNode *l1, ListNode *l2) {
        vector<int> result = add(l1->val, l2->val);   //
        vector<int> nextResult;
        ListNode null;
        null.next = nullptr;
        if (l1->next != nullptr) {
            if (l2->next != nullptr)
                nextResult = addTwoNumber(l1->next, l2->next);
            else
                nextResult = addTwoNumber(l1->next, &null);
        } else {
            if (l2->next != nullptr)
                nextResult = addTwoNumber(&null, l2->next);
            else
                return result;
        }
////        是否执行结束
//        if (!isOneToNine(nextResult[0]))
//            return result;
//        将当前相加的结果和下一位相加的结果加在一起
        int first, second, third, fourth;
        first = result[0];
        second = result[1] + nextResult[0];
        third = nextResult[1];
        fourth = nextResult[2];

        if (!isOneToNine(second)) {
            second = second - 10;
            third += 1;
        }
        if (!isOneToNine(third)) {
            third = third - 10;
            fourth += 1;
        }
        return {first, second, third, fourth};
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> input1 = {9,9,9,9,9,9,9};
    vector<int> input2 = {9,9,9,9};
    auto *start1 = new ListNode();
    ListNode *end1;
    auto *start2 = new ListNode();
    ListNode *end2;

    for (int i = 0; i < input1.size() - 1; i++) {
        if (i == 0) {
            start1->val = input1[i];
            start1->next = new ListNode(input1[i + 1]);
            end1 = start1->next;
            end1->next = nullptr;
        } else {
            end1->next = new ListNode(input1[i + 1]);
            end1 = end1->next;
            end1->next = nullptr;
        }
    }
    for (int i = 0; i < input2.size() - 1; i++) {
        if (i == 0) {
            start2->val = input2[i];
            start2->next = new ListNode(input2[i + 1]);
            end2 = start2->next;
            end2->next = nullptr;
        } else {
            end2->next = new ListNode(input2[i + 1]);
            end2 = end2->next;
            end2->next = nullptr;
        }
    }
    Solution solution;
    solution.addTwoNumbers(start1, start2);
}