#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵����
	��ʱ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int maxVol = 0;
         int n = height.size();
         for(int i = 0; i < n - 1; i++){
             for(int j = i + 1; j < n; j++){
                 int minHeight = min(height[i], height[j]);
                 maxVol = max(maxVol, minHeight * (j - i));
             }
         }
         return maxVol;
     }
 };

 /**********************************************************************************************************
������˫ָ�뷨

˵����
    ��i��j������ָ�루����������ô��volumn = (j - i) * min(height[i], height[j])�����Կ�����volumn��������
    ȡ���ڸ߶ȣ���ȡ���ڿ�ȣ������ǽ�ָ������������ߴ������ұߴ�����ô��������ֵ����ʱ��ͨ���ƶ�
    �����ָ��++�������Ҳ�ָ��--����ʵ�ֿ�ȵļ��٣��߶ȵ����ӣ��Ӷ�ʵ������volumn������
    ��ô����ȥ�ƶ�ָ���أ�
    1. ���ƶ�����ָ���ж�Ӧ�߶���С����һ��ʱ���߶��п��ܻ����ӣ����һ������1���п��ܳ�������volumn����
    2. ���ƶ�����ָ���ж�Ӧ�߶�������һ��ʱ���߶�һ���������ӣ��п��ܲ��䣩�����һ������1����ʱ��õ���volumn�����ܱ�֮ǰ�Ĵ�
    ��˵õ����ԣ�
    1. ����ָ��
    2. �Ƚ������߶ȣ��Ǹ�С���ƶ��ı�
    3. ֱ��i < j������Ϊֹ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int n = height.size();
         int left = 0;
         int right = n - 1;
         int maxVol = 0;
         while (left < right) {
             maxVol = height[left] > height[right] ? max(maxVol, (right - left) * height[right--]) : max(maxVol, (right - left) * height[left++]);
         }
         return maxVol;
     }
 };