#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
����1��˫ָ�뷨���������������н�����������ŷ�����

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m+n)  O(m)

�漰����֪ʶ�㣺

***********************************************************************************************************/
//��һ����д�ģ���Ҫ�Ľ�
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

//�Ľ���汾
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
����2������˫ָ�뷨

˵����
    ���Խ��ռ临�ӶȽ�һ�����ͣ���������һ�£�A�����к�n����û���õ����ݣ�������ǴӺ���ǰ���ô��ʹ
    �Ǻ�n����ȫ��B���������Ҳ�ոպò��Ḳ��Aǰm�����õ�������˴Ӻ���ǰ�ǰ�ȫ��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(m+n)  O(1)

�漰����֪ʶ�㣺

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