#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
������

˵����

ʱ�临�Ӷ���ռ临�Ӷȣ�

�漰����֪ʶ�㣺
    1. string�ĸ��ֲ�����
        string -> int    atoi(str.c_str())
        int -> string    to_string()
        ����string��ӣ� str1.append(str2) ���鲻Ҫ��str1 = str1 + str2;
        string�����һ��char��str.push_back(char1);
        string��ʼ��Ҫ��""

    2. �������
    3. �ַ����и��strcut
        
***********************************************************************************************************/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; i++) { //�Ӳ���������û��Ӱ��
                TreeNode* tempNode = que.front();
                que.pop();
                if (tempNode != NULL) {
                    res.append(to_string(tempNode->val) + ',');
                    // res = res + to_string(tempNode->val); //�ռ�Ч�ʲ�10�౶��ʱ��Ч�ʲ�3-4��
                    // res += ',';
                    que.push(tempNode->left);
                    que.push(tempNode->right);
                }
                else {
                    res.append("null,");
                    // res += "null";
                    // res += ',';
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<int> words = strCut(data);
        TreeNode* root = new TreeNode(words[0]);
        queue<TreeNode*>q;
        q.push(root);
        int idx = 1;
        while (!q.empty() && idx < words.size()) {
            TreeNode* tempNode = q.front();
            q.pop();
            if (words[idx] != INT_MAX) {
                tempNode->left = new TreeNode(words[idx]); //
                q.push(tempNode->left);
            }
            idx++;
            if (words[idx] != INT_MAX) {
                tempNode->right = new TreeNode(words[idx]);
                q.push(tempNode->right);
            }
            idx++;
        }
        return root;
    }

private:
    vector<int> strCut(const string& data) {
        int begin = 0;
        int end = 0;
        vector<int> res;
        string temp;
        while (begin < data.size() && end < data.size()) {
            while (end < data.size() && data[end] != ',') end++;
            temp = data.substr(begin, end - begin);
            if (temp == "null") {
                res.push_back(INT_MAX);
            }
            else {
                res.push_back(atoi(temp.c_str()));
            }
            end++; //�����������ѭ������Ϊend��ֻ��ͣ��1�����ᶯ����Զ������ȥ
            begin = end;
        }
        return res;
    }
};