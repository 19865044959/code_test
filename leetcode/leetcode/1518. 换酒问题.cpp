#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
�������ݹ鷨

˵����
	��������ײ���˼·���ң�Ҫ���屾�κȹ���numBottlesʣ�µĿ�ƿ�����ϴ�δ�ܱ��numBottles�Ŀ�ƿ��

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        iteration(numBottles, 0, ans, numExchange);
        return ans;
    }
    void iteration(int numBottles, int emptyBottles, int& ans, int numExchange) {
        if (numBottles == 0) return;
        ans += numBottles;
        iteration((numBottles + emptyBottles) / numExchange, (numBottles + emptyBottles) % numExchange, ans, numExchange);
    }
};

/**********************************************************************************************************
������������
˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return ans;
    }
};