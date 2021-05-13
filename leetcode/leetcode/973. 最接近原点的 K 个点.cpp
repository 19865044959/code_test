#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
��������������ֱ��sort

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)   O(1)

�漰����֪ʶ�㣺sort����������

***********************************************************************************************************/
 class Solution {
 public:
     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
         sort(points.begin(), points.end(), cmp);
         return vector<vector<int>>(points.begin(), points.begin() + K);
     }

 private:
     static bool cmp(vector<int>& a, vector<int>& b){
         return sqrt(a[0] * a[0] + a[1] * a[1]) < sqrt(b[0] * b[0] + b[1] * b[1]);
     }
 };


 /**********************************************************************************************************
 ���������ű���

 ˵����

 ʱ�临�Ӷ���ռ临�Ӷȣ�O(nlogn)   O(1)

 �漰����֪ʶ�㣺����Դ��

 ***********************************************************************************************************/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int low = 0;
        int high = points.size() - 1;
        while (low < high) {
            int pivot = partition(points, low, high);
            if (pivot == K) break;
            else if (pivot > K) {
                high = pivot - 1;
            }
            else {
                low = pivot + 1;
            }
        }
        points.resize(K);
        return points;
    }

private:
    int ODistance(int a, int b) {
        return (a * a + b * b);
    }
    int partition(vector<vector<int>>& points, int low, int high) {
        //����ȡ��
        int medium = low + (high - low) / 2;
        if (ODistance(points[low][0], points[low][1]) > ODistance(points[high][0], points[high][1])) swap(points[low], points[high]); //points[low]�ǽ�С����
        if (ODistance(points[medium][0], points[medium][1]) > ODistance(points[high][0], points[high][1])) swap(points[medium], points[high]); //points[medium]�ǽ�С����
        if (ODistance(points[low][0], points[low][1]) < ODistance(points[medium][0], points[medium][1])) swap(points[low], points[medium]); //points[low]���м�ֵ

        int pivotkey = ODistance(points[low][0], points[low][1]);
        vector<int> temp = points[low];
        while (low < high) {
            while (low < high && ODistance(points[high][0], points[high][1]) >= pivotkey) {
                high--;
            }
            points[low] = points[high];
            while (low < high && ODistance(points[low][0], points[low][1]) <= pivotkey) {
                low++;
            }
            points[high] = points[low];
        }
        points[low] = temp;
        return low;
    }

};
