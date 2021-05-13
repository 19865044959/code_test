#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
	��Ŀ������һ��������������һ���ڵ㣬����ҳ�����������е���һ���ڵ㣿�ö������������������ҽڵ��⣬
	�����丸�׽ڵ�
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL){}
};

/**********************************************************************************************************
������������

˵����
    1. ���ýڵ���������ʱ��������һ���ڵ������������������Ľڵ�
    2. ���ýڵ�û�������������и��׽ڵ�ʱ������ýڵ����丸�׽ڵ���������ڵ㣬��ô�ýڵ����һ���ڵ����丸�׽ڵ�
    3. ���ýڵ�û�������������и��׽ڵ�ʱ������ýڵ����丸�׽ڵ���������ڵ㣬��ô�������ϱ�����ֱ���ҵ�һ�����׽ڵ㣬����2Ϊֹ

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(1)

�漰����֪ʶ�㣺

***********************************************************************************************************/
class Solution {
    TreeNode* findNextNode(TreeNode* node, TreeNode* root) {
        if (node == NULL) return NULL; //***��ָ����
        TreeNode* nextNode = NULL;
        if (node->right != NULL) { //���1
            TreeNode* tempNode = node->right;
            while (tempNode->left != NULL) {
                tempNode = tempNode->left;
            }
            nextNode = tempNode;
        }
        else if (node->father != NULL){ //���2��3
            TreeNode* fatherNode = node->father;
            TreeNode* currentNode = node;
            while (fatherNode != NULL && fatherNode->right == currentNode) {
                currentNode = fatherNode;
                fatherNode = fatherNode->father;
            }
            if (fatherNode != root) { //ע��������������node�Ƕ����������²�Ľڵ㣬��ô�ýڵ�������������һ���ڵ㣬��������һ���ڵ�
                nextNode = fatherNode;
            }            
        }
        return nextNode;
    }
};
