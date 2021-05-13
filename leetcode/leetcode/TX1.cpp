/*
作者：老萌新
链接：https://www.nowcoder.com/discuss/643580?type=all&order=time&pos=&page=0&channel=-1&source_id=search_all_nctrack
来源：牛客网

1. 求最小循环同构串：最小表示法，建议百度
2. 优先队列
3. 贪心：最先做W大的。为什么呢？因为现在剩下一个时间，如果能做W大的和W小的，只能做一个，那么做大的肯定更优。如果W相同，那么先做T靠后的，为什么呢？因为后面的时间比较不值钱，一个时间可以做时间在它后面的任何事，后面的就明显能做的更少。
4. 直接暴力模拟
5. 应该是dp，考试时写了很久只过了30。感觉改改能过。

另一个大神：
https://www.nowcoder.com/discuss/643588?type=post&order=time&pos=&page=1&channel=-1&source_id=search_post_nctrack
*/
/*
	核心代码模式，给一个链表，可以进行旋转，求旋转链表后字典序最小的链表
	b链表字典序小于a链表字典序的定义：存在j，使得对于任意的i < j，a[i] == b[i]，a[j] > b[j]
	1 2 3 4 这个最小
	2 3 4 1
	3 4 1 2
	4 1 2 3
	我的思路：先将链表值拿出来，然后在值1~ n - 1处翻转，得到的新链表储存起来叫做temp，遍历，
	如果跟res相比，temp[i] < res[i]那么res = temp，否则不动，过了66%
*/

#include <iostream>
#include <vector>
#include<stdlib.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* solve(ListNode* S) {
        vector<int>nums;
        while (S != NULL) {
            nums.push_back(S->val);
            S = S->next;
        }
        int n = nums.size();
        vector<int>res = nums;
        vector<int>temp(n, 0);

        for (int i = 1; i < 1 + n; i++) {
            //构造新
            for (int m = 0; m < n; m++) {
                temp[m] = nums[(m + i) % n];
            }
            for (int j = 0; j < n; j++) {
                if (res[j] == temp[j]) continue;
                else if (res[j] > temp[j]) {
                    res = temp;
                    break;
                }
                else break;
            }
        }
        ListNode* newHead = new ListNode(res[0]);
        ListNode* ptr1 = newHead;
        for (int i = 1; i < n; i++) {
            ptr1->next = new ListNode(res[i]);
            ptr1->next->val = res[i];
            ptr1 = ptr1->next;
        }
        return newHead;
    }
};

//最小表示法 O(n)求字典序最小的字符串
// https://blog.csdn.net/tianyuhang123/article/details/54919715?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-0&spm=1001.2101.3001.4242
int minimumRepresentation(string s) {
    int i = 0, j = 1, k = 0;
    int n = s.size();
    while (i < n && j < n && k < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) k++;
        else {
            if (s[(i + k) % n] > s[(j + k) % n]) i = i + k + 1; //最小字符串不可能以i ~ i + k开头
            else {
                j = j + k + 1; // 最小字符串不可能以j ~j + k开头
            }
            k = 0;
            if (i == j) j++;
        }
    }
    return i < j ? i : j;
}
