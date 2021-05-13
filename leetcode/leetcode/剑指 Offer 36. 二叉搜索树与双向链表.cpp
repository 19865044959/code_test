#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
�������ݹ����

˵���������һ��������������������ôͨ����������ֽ��С���飬
    ��ӦҲ�����������������������С���鶼��������������ô��������Ҳ��������������

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(n) �ֱ��ǣ�ѭ������Ӷȣ�O(n) �ݹ�����Ӷ�O(n)������Ƕ��η�

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

private:
    bool recur(vector<int>& postorder, int left, int right) {
        if (left >= right) return true; //һ��������Ȼ�Ƿ��Ϻ��������
        int rootVal = postorder[right];
        //���ǵ��п���ֻ�����������������ô�����ѭ����������У���ô��ʱ������Ӧ��Ϊ�գ�
        //��recur(postorder, right, right - 1);��˳�ֵ��Ҫ��right
        int midIdx = right;
        int i;
        for (i = left; i <= right; i++) {//O(n)
            if (postorder[i] > rootVal) {
                midIdx = i;
                break;
            }
        }
        //������������������ֽ����Ҳ�һ����Ҫ����postorder[right]��Ҫ��Ȼ�Ͳ����������������������е�ֵ������rootֵ��
        for (int i = midIdx; i < right; i++) {//O(n)
            if (postorder[i] < postorder[right]) return false;
        }
        return recur(postorder, left, midIdx - 1) && recur(postorder, midIdx, right - 1);
    }
};