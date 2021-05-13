/*
���ߣ�������
���ӣ�https://www.nowcoder.com/discuss/643580?type=all&order=time&pos=&page=0&channel=-1&source_id=search_all_nctrack
��Դ��ţ����

1. ����Сѭ��ͬ��������С��ʾ��������ٶ�
2. ���ȶ���
3. ̰�ģ�������W��ġ�Ϊʲô�أ���Ϊ����ʣ��һ��ʱ�䣬�������W��ĺ�WС�ģ�ֻ����һ������ô����Ŀ϶����š����W��ͬ����ô����T����ģ�Ϊʲô�أ���Ϊ�����ʱ��Ƚϲ�ֵǮ��һ��ʱ�������ʱ������������κ��£�����ľ����������ĸ��١�
4. ֱ�ӱ���ģ��
5. Ӧ����dp������ʱд�˺ܾ�ֻ����30���о��ĸ��ܹ���

��һ������
https://www.nowcoder.com/discuss/643588?type=post&order=time&pos=&page=1&channel=-1&source_id=search_post_nctrack
*/
/*
	���Ĵ���ģʽ����һ���������Խ�����ת������ת������ֵ�����С������
	b�����ֵ���С��a�����ֵ���Ķ��壺����j��ʹ�ö��������i < j��a[i] == b[i]��a[j] > b[j]
	1 2 3 4 �����С
	2 3 4 1
	3 4 1 2
	4 1 2 3
	�ҵ�˼·���Ƚ�����ֵ�ó�����Ȼ����ֵ1~ n - 1����ת���õ�������������������temp��������
	�����res��ȣ�temp[i] < res[i]��ôres = temp�����򲻶�������66%
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * @param S ListNode�� val��ʾȨֵ��nextָ����һ��Ԫ��
     * @return ListNode��
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
            //������
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

//��С��ʾ�� O(n)���ֵ�����С���ַ���
// https://blog.csdn.net/tianyuhang123/article/details/54919715?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-0&spm=1001.2101.3001.4242
int minimumRepresentation(string s) {
    int i = 0, j = 1, k = 0;
    int n = s.size();
    while (i < n && j < n && k < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) k++;
        else {
            if (s[(i + k) % n] > s[(j + k) % n]) i = i + k + 1; //��С�ַ�����������i ~ i + k��ͷ
            else {
                j = j + k + 1; // ��С�ַ�����������j ~j + k��ͷ
            }
            k = 0;
            if (i == j) j++;
        }
    }
    return i < j ? i : j;
}
