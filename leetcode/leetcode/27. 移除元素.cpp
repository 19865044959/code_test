#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：复制数组

说明：
    空间复杂度超预算

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：

***********************************************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> numsCopy(nums);
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (numsCopy[i] == val) continue;
            nums[j] = numsCopy[i];
            j++;
        }
        return j;
    }
};

/**********************************************************************************************************
方法2：C++ STL

说明：
    erase与remove函数

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/
//第一种
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         int i;
         for(i = 0; i < nums.size(); i++){ //注意这里不能将size储存到n中！因为它的size一直在变化！
             if(nums[i] == val){
                 nums.erase(nums.begin() + i);
                 i--;
             }
         }
         return nums.size();
     }
 };

 //第二种
 class Solution {
 public:
     int removeElement(vector<int>& nums, int val) {
         auto iter = remove(nums.begin(), nums.end(), val);
         return iter - nums.begin();
     }
 };