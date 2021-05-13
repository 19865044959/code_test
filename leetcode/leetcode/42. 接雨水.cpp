#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1�����м���

˵����
	��ʱ(314/315)

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n * height) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxHeight = INT_MIN;

        //�ҵ����߶�
        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, height[i]);
        }
        int ans = 0;
        for (int i = 1; i <= maxHeight; i++) {
            int j = 0;
            int temp = 0;
            //�ҵ���һ���߶� >= i�ĵ㣬��ʼѭ��
            while (j < n && height[j] < i) j++;
            //��ѭ�������߶� >= i ʱ�� ans += temp�����߶� < iʱ�� temp++������ˮ
            while (j < n) {
                if (height[j] >= i) {
                    ans += temp;
                    temp = 0;
                }
                else {
                    temp++;
                }
                j++;
            }
        }
        return ans;
    }
};

/**********************************************************************************************************
����2�����м���

˵����
    �չ�

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMaxHeight = INT_MIN;
        int rightMaxHeight;
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {//��ȥ����������ұߵ���
            leftMaxHeight = max(leftMaxHeight, height[i - 1]);
            rightMaxHeight = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                rightMaxHeight = max(rightMaxHeight, height[j]);
            }
            int minVal = min(leftMaxHeight, rightMaxHeight);
            sum += height[i] > minVal ? 0 : (minVal - height[i]);
        }
        return sum;
    }
};

/**********************************************************************************************************
����3�����м��� + �ռ任ʱ��

˵����
    ��rightMaxHeight���浽һ������֮�У���leftMaxHeight��ֱ�Ӹ��¼���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMaxHeight = INT_MIN;
        vector<int> rightMaxHeight(n, 0);
        //�ÿռ任ʱ�䣬��rightMaxHeightֵ�������飬ע���ǴӸߵ��ͣ�����rightMaxHeight[i]������height[i]Ԫ��
        for (int i = n - 2; i >= 1; i--) {
            rightMaxHeight[i] = max(height[i + 1], rightMaxHeight[i + 1]);
        }
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            leftMaxHeight = max(leftMaxHeight, height[i - 1]); //���ֱ�Ӹ���
            int minVal = min(leftMaxHeight, rightMaxHeight[i]); //�ұ�ֱ���ô����ֵ������
            sum += height[i] >= minVal ? 0 : (minVal - height[i]);
        }
        return sum;
    }
};