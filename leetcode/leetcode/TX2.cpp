#include <iostream>
#include <vector>
#include<stdlib.h>
#include<queue>
using std::vector;
using std::swap;

/*
    ��n���û�������nums���ţ�Ҫ����nums���ŷ���n���û��������ÿ���û������ŵ����ڣ�����i����ô�����ʼ���ʱ��ֱ�Ϊ�� i 2i 3i ������
    ����nums���ŵ��׷�������Щ�û����������ͬ��ʱ���ڣ�����ͬ���û���Ҫ���ţ���ôȡ���С�����ȷ���
    1 <= n <= nums <= 10^6
    1 <= ����T <= 1000

    �ҵ�˼·������������20%����ʱ
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
    ���ȼ����� + �Զ���ṹ��
    �Զ���ṹ���еıȽ�����ʹ�����������ȼ�����
    ʱ�临�Ӷȣ�O(n * logn  +  logn * k) 
*/

struct node {
    int t;
    int idx;
    int stamp;
    bool operator< (const node& other) const { //const����˼�Ǹ���������������޸ĳ�Ա����t��stamp��ֵ
        if (stamp != other.stamp) return other.stamp < stamp;
        else return other.idx < idx;
    }
};

//�ڶ��ֱȽϷ�ʽ���º���
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
            pq.push(node{ t, i, t }); //�ṹ���б��ʼ�����ȽϿ��
        }
        while (k--) { //�ȷ��أ���--�����д��--k����ô��--���ٷ���
            auto temp = pq.top();
            pq.pop();
            cout << temp.idx << endl;
            temp.stamp += temp.t; //������һ����Ҫ�����ʼ���ʱ��
            pq.push(temp); //�ٴ�ѹ�����ȼ�����
        }
    }
    return 0;
}

