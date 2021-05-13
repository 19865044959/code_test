#include <iostream>
#include <vector>
#include<stdlib.h>
#include<queue>
using std::vector;
using std::swap;

/*
    有n个用户，共有nums封信，要将这nums封信发到n个用户手里，给了每个用户接受信的周期，比如i，那么发送邮件的时间分别为： i 2i 3i 。。。
    求这nums封信到底发给了哪些用户，如果在相同的时间内，有相同的用户需要发信，那么取编号小的优先发送
    1 <= n <= nums <= 10^6
    1 <= 周期T <= 1000

    我的思路：暴力遍历，20%，超时
*/
using namespace std;

int main() {
    int n, nums;
    while (cin >> n >> nums) {
        vector<vector<int>>Time(1001);
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            Time[temp].push_back(i);
        }
        int t = 0;
        while (nums) {
            t++;
            for (int i = 1; i <= 1000; i++) {
                if (i > t) {
                    break;
                }
                if ((!Time[i].empty()) && (t % i == 0)) {
                    for (auto num : Time[i]) {
                        cout << num << endl;
                        nums--;
                    }
                }
            }
        }
    }
    return 0;
}


/*
    优先级队列 + 自定义结构体
    自定义结构体中的比较器，使得适用于优先级队列
    时间复杂度：O(n * logn  +  logn * k) 
*/

struct node {
    int t;
    int idx;
    int stamp;
    bool operator< (const node& other) const { //const：意思是该重载运算符不会修改成员变量t与stamp的值
        if (stamp != other.stamp) return other.stamp < stamp;
        else return other.idx < idx;
    }
};

//第二种比较方式：仿函数
struct cmp {
    bool operator() (const node& n1, const node& n2) {
        if (n1.stamp != n2.stamp) return n1.stamp > n2.stamp;
        else return n1.idx > n2.idx;
    }
};


int main() {
    int n, k;
    while (cin >> n >> k) {
        priority_queue<node, vector<node>, cmp> pq;
        //priority_queue<node> pq;
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            pq.push(node{ t, i, t }); //结构体列表初始化，比较快捷
        }
        while (k--) { //先返回，再--，如果写成--k，那么先--，再返回
            auto temp = pq.top();
            pq.pop();
            cout << temp.idx << endl;
            temp.stamp += temp.t; //更新下一次需要发送邮件的时间
            pq.push(temp); //再次压入优先级队列
        }
    }
    return 0;
}

