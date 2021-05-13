#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������������

˵������Ϊ����״̬��һ���ǲ��������ڶ����ǣ��������й�Ʊ��������������û��Ʊ������

ʱ�临�Ӷ���ռ临�Ӷȣ�O(2^n), O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
//������
//��Ϊ����״̬��һ���ǲ��������ڶ����ǣ��������й�Ʊ��������������û��Ʊ������
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dfs(prices, 0, 0, 0);
        return res;
    }
private:
    int res = 0;
    int n;
    /*
    @param prices:����
    @param index:������������0��ʼ
    @param profit:����
    @param status:0�������У�1������й�Ʊ
    */
    void dfs(vector<int>& prices, int index, int profit, int status) {
        if (n == index) {
            res = max(res, profit);
            return;
        }
        dfs(prices, index + 1, profit, status);//��һ������ݹ飬ע�⣺�����д����ݹ飬��ô�ͻ����˲����������������ϵͳֻ������߲�������Ȼ�ǲ��Ե�
        //�ڶ��������������С�����ɣ�
        if (status == 0) {
            //ת�����й�Ʊ,status = 1
            dfs(prices, index + 1, profit - prices[index], 1);
        }
        else {
            //ת��������Ʊ��status = 0
            dfs(prices, index + 1, profit + prices[index], 0);
        }
    }
};


/**********************************************************************************************************
������̰���㷨

˵����
    ���˼��
    δ�����

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n), O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            //res += prices[i] - prices[i-1] > 0 ? (prices[i] - prices[i-1]) : 0;
            int temp = prices[i] - prices[i - 1];
            if (temp > 0) res += temp;
        }
        return res;
    }
};