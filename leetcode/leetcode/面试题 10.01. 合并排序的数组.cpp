#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法1：双指针法（对两个有序数列进行排序的最优方法）

说明：

时间复杂度与空间复杂度：O(m+n)  O(m)

涉及到的知识点：

***********************************************************************************************************/
//第一次我写的，需要改进
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> C(m);
        for (int i = 0; i < m; i++) {
            C[i] = A[i];
        }
        int i = 0, j = 0, k = 0;
        for (; i < m && j < n; k++) {
            if (C[i] > B[j]) {
                A[k] = B[j];
                j++;
            }
            else {
                A[k] = C[i];
                i++;
            }
        }
        if (i == m) {
            for (; j < n; j++) {
                A[k] = B[j];
                k++;
            }
        }
        else if (j == n) {
            for (; i < m; i++) {
                A[k] = C[i];
                k++;
            }
        }
    }
};

//改进后版本
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int>C(m);
        for (int i = 0; i < m; i++) {
            C[i] = A[i];
        }
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (C[i] > B[j]) {
                A[k++] = B[j++];
            }
            else {
                A[k++] = C[i++];
            }
        }
        while (i < m) {
            A[k++] = C[i++];
        }
        while (j < n) {
            A[k++] = B[j++];
        }
    }
};

/**********************************************************************************************************
方法2：逆向双指针法

说明：
    可以将空间复杂度进一步降低，可以试想一下：A数组中后n个是没有用的数据，如果我们从后向前填，那么即使
    是后n个数全是B数组的数，也刚刚好不会覆盖A前m个有用的数，因此从后向前是安全的

时间复杂度与空间复杂度：O(m+n)  O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (B[j] > A[i]) {
                A[k--] = B[j--];
            }
            else {
                A[k--] = A[i--];
            }
        }
        while (i >= 0) {
            A[k--] = A[i--];
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};