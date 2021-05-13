#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/**********************************************************************************************************
���������� + bfs �����������

˵�����ο�104�����������������ȣ�������ȸĳ�push_back���Ԫ����ans���漴��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> q;
        vector<int> ans;
        TreeNode* p;

        q.push_back(root);

        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                p = q.front();
                q.pop_front();
                if (p->left) q.push_back(p->left);
                if (p->right) q.push_back(p->right);
            }
            //�õ�ÿһ�����һ��Ԫ�ض�Ӧ��ָ��
            ans.push_back(p->val);
        }
        return ans;
    }
};

/**********************************************************************************************************
������dfs

˵�������ա������ -> ������ -> ����������˳����ʣ� �Ϳ��Ա�֤ÿ�㶼�����ȷ������ұߵĽڵ�ġ�
          (��������� ������� -> ������ -> �������� �����෴���������ÿ�����ȷ��ʵ�������ߵĽڵ㣩

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺

***********************************************************************************************************/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0); // �Ӹ��ڵ㿪ʼ���ʣ����ڵ������0
        return ans;
    }

private:
    vector<int> ans;
    void dfs(TreeNode* p, int depth) {
        if (!p) return;
        // �ȷ��� ��ǰ�ڵ㣬�ٵݹ�ط��� ������ �� ��������
        if (depth == ans.size()) {  // �����ǰ�ڵ�������Ȼ�û�г�����res�˵���ڸ�����µ�ǰ�ڵ��ǵ�һ�������ʵĽڵ㣬��˽���ǰ�ڵ����res�С�
                                                 // �����depth�൱���±꣬ans.size()�ǳ��ȣ���ôһ�����飬��������±��볤��֮���ܻ����㣺indexMax = length - 1���������ˣ�˵������±�δ����
            ans.push_back(p->val);
        }
        depth++;
        dfs(p->right, depth);
        dfs(p->left, depth);
    }
};