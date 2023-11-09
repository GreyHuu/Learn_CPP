/**
2023-11-09 16:21:41
844-比较含退格的字符串
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void process_char(vector<char> &c_s) {
        int slow = 0;
        for (int fast = 0; fast < c_s.size(); ++fast) {
            if (c_s[fast] == '#') {
                if (slow > 0)
                    slow--;
            } else {
                c_s[slow++] = c_s[fast];
            }

        }
        // 通过resize缩小vector大小到k个元素
        c_s.resize(slow);
    }

    bool backspaceCompare(string s, string t) {
        vector<char> c_s(s.begin(), s.end());
        vector<char> t_s(t.begin(), t.end());
        process_char(c_s);
        process_char(t_s);
        return c_s == t_s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

}