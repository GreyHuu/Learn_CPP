/**
2023-10-26 16:33:44
704-二分查找
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left <= right){   // 左闭右闭
            int middle=left+(right-left)/2;
            int middle_num=nums[middle];

            if (middle_num==target) return middle;

            if(middle_num>target)
                right=middle-1 ;
            else
                left=middle+1 ;

        }
        return -1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){

}