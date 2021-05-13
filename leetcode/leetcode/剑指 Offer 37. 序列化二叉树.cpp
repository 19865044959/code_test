#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

/**********************************************************************************************************
方法：

说明：

时间复杂度与空间复杂度：

涉及到的知识点：
    1. string的各种操作：
        string -> int    atoi(str.c_str())
        int -> string    to_string()
        两个string相加： str1.append(str2) 建议不要用str1 = str1 + str2;
        string后加上一个char：str.push_back(char1);
        string初始化要用""

    2. 层序遍历
    3. 字符串切割函数strcut
        
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
            for (int i = 0; i < sz; i++) { //加不加在这里没有影响
                TreeNode* tempNode = que.front();
                que.pop();
                if (tempNode != NULL) {
                    res.append(to_string(tempNode->val) + ',');
                    // res = res + to_string(tempNode->val); //空间效率差10多倍，时间效率差3-4倍
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
            end++; //不加这个会死循环，因为end就只会停在1处不会动，永远都出不去
            begin = end;
        }
        return res;
    }
};