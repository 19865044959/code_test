#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：递归分治

说明：即如果一个数组满足后序遍历，那么通过后序遍历分解的小数组，
    对应也必须满足后序遍历，如果所有小数组都满足后序遍历，那么整个数组也就满足后序遍历了

时间复杂度与空间复杂度：O(n^2) O(n) 分别是：循环最大复杂度：O(n) 递归最大复杂度O(n)，因此是二次方

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

private:
    bool recur(vector<int>& postorder, int left, int right) {
        if (left >= right) return true; //一个数，当然是符合后序遍历了
        int rootVal = postorder[right];
        //考虑到有可能只有左子树的情况，那么下面的循环将不会进行，那么此时右子树应该为空，
        //即recur(postorder, right, right - 1);因此初值需要赋right
        int midIdx = right;
        int i;
        for (i = left; i <= right; i++) {//O(n)
            if (postorder[i] > rootVal) {
                midIdx = i;
                break;
            }
        }
        //必须满足的条件：即分界点的右侧一定都要大于postorder[right]，要不然就不满足后序遍历中右子树所有的值都大于root值了
        for (int i = midIdx; i < right; i++) {//O(n)
            if (postorder[i] < postorder[right]) return false;
        }
        return recur(postorder, left, midIdx - 1) && recur(postorder, midIdx, right - 1);
    }
};