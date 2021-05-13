#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

//并查集相关题目：547、684
class UnionFind {
public:
    vector<int>roots;
    int size;

    //构造函数
    UnionFind(int n):roots(n), size(n){ //初始化
        //roots = vector<int>(n); //赋值，而不是初始化
        //size = n;
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }       
    }

    //查询与路径压缩
    int find(int i) {
        if (i == roots[i]) return i;
        return roots[i] = find(roots[i]); //路径压缩
    }

    //合并
    bool Union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            roots[pRoot] = qRoot;
            size--; //注意这个
            return false;
        }
        return true;
    }
};
