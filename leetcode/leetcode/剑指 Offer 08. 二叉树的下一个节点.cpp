#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
	题目：给定一个二叉树和其中一个节点，如何找出中序遍历序列的下一个节点？该二叉搜索树除了有左、右节点外，
	还有其父亲节点
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL){}
};

/**********************************************************************************************************
方法：分析法

说明：
    1. 当该节点有右子树时，它的下一个节点是其右子树中最左侧的节点
    2. 当该节点没有右子树，但有父亲节点时，如果该节点是其父亲节点的左子树节点，那么该节点的下一个节点是其父亲节点
    3. 当该节点没有右子树，但有父亲节点时，如果该节点是其父亲节点的右子树节点，那么继续向上遍历，直到找到一个父亲节点，满足2为止

时间复杂度与空间复杂度：O(n) O(1)

涉及到的知识点：

***********************************************************************************************************/
class Solution {
    TreeNode* findNextNode(TreeNode* node, TreeNode* root) {
        if (node == NULL) return NULL; //***空指针检查
        TreeNode* nextNode = NULL;
        if (node->right != NULL) { //情况1
            TreeNode* tempNode = node->right;
            while (tempNode->left != NULL) {
                tempNode = tempNode->left;
            }
            nextNode = tempNode;
        }
        else if (node->father != NULL){ //情况2、3
            TreeNode* fatherNode = node->father;
            TreeNode* currentNode = node;
            while (fatherNode != NULL && fatherNode->right == currentNode) {
                currentNode = fatherNode;
                fatherNode = fatherNode->father;
            }
            if (fatherNode != root) { //注意特殊情况：如果node是二叉树最右下侧的节点，那么该节点中序遍历是最后一个节点，不存在下一个节点
                nextNode = fatherNode;
            }            
        }
        return nextNode;
    }
};
