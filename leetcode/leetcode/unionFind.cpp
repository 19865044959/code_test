#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

//���鼯�����Ŀ��547��684
class UnionFind {
public:
    vector<int>roots;
    int size;

    //���캯��
    UnionFind(int n):roots(n), size(n){ //��ʼ��
        //roots = vector<int>(n); //��ֵ�������ǳ�ʼ��
        //size = n;
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }       
    }

    //��ѯ��·��ѹ��
    int find(int i) {
        if (i == roots[i]) return i;
        return roots[i] = find(roots[i]); //·��ѹ��
    }

    //�ϲ�
    bool Union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            roots[pRoot] = qRoot;
            size--; //ע�����
            return false;
        }
        return true;
    }
};
