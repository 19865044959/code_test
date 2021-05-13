#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**********************************************************************************************************
方法：暴力法，直接sort

说明：

时间复杂度与空间复杂度：O(nlogn)   O(1)

涉及到的知识点：sort第三个参数

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
 方法：快排变形

 说明：

 时间复杂度与空间复杂度：O(nlogn)   O(1)

 涉及到的知识点：快排源码

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
        //三数取中
        int medium = low + (high - low) / 2;
        if (ODistance(points[low][0], points[low][1]) > ODistance(points[high][0], points[high][1])) swap(points[low], points[high]); //points[low]是较小距离
        if (ODistance(points[medium][0], points[medium][1]) > ODistance(points[high][0], points[high][1])) swap(points[medium], points[high]); //points[medium]是较小距离
        if (ODistance(points[low][0], points[low][1]) < ODistance(points[medium][0], points[medium][1])) swap(points[low], points[medium]); //points[low]是中间值

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
