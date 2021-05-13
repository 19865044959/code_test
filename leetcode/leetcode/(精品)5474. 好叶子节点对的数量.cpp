#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**********************************************************************************************************
�������������

˵����
    1. ���ò���������ÿ���ڵ�ĵ����ڵ��·��ͼ����string��ʾ������0������������1����������
    2. ����Ѱ�ҵ����������ڵ㵽����Ҷ�ӽ���·��ͼ
    3. ��������Ҷ�ӽ�㣬������LCA������������ȣ��������乫���������������ǵľ���
    4. ������<=ָ������ʱ��ans++

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n^2*depth), O(n^2)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> q;
        vector<string> s;
        q.push_back(root);
        s.push_back("");
        for (int i = 0; i < q.size(); i++) { //ע��������q.size()�����ǽ�int n = q.size()������Ϊÿ��push_back����ʹ��q.size()��̬�����ı䣬��һ�㲻��a.end()һ������
            TreeNode* nodeptr = q[i];
            string nodestr = s[i];
            if (nodeptr->left != NULL) {
                q.push_back(nodeptr->left);
                s.push_back(nodestr + "0");
            }
            if (nodeptr->right != NULL) {
                q.push_back(nodeptr->right);
                s.push_back(nodestr + "1");
            }
        }
        int ans = 0;
        for (int i = 0; i < q.size() - 1; i++) {
            for (int j = i + 1; j < q.size(); j++) {
                if (q[i]->left != NULL || q[i]->right != NULL || q[j]->left != NULL || q[j]->right != NULL) continue; //��仰����˼���ҵ�����Ҷ�ӽ�㣬��ΪҶ�ӽڵ����Ů��Ϊ�սڵ�
                int size = s[i].size() + s[j].size();
                for (int k = 0; k < s[i].size() && k < s[j].size(); k++) {
                    if (s[i][k] == s[j][k]) size -= 2; //������ڹ���·�����������ȣ�����ô������-2,
                    else break; //��仰�ǳ�����Ҳ�ǳ������������ǵ�һ��·���ַ���ʼȫ��Ҫ��ͬ�������һ������ͬ��˵����һ������LCA�����������仰����ô0011��0111�Ĺ�ͬ������
                                      //�ʹ�1��'0'�����3���� '0'��'1'��'1'�����¼������
                }
                if (size <= distance) ans++;
            }
        }
        return ans;
    }
};
