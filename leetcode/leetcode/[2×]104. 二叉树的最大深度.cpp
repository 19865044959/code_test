#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/**********************************************************************************************************
方法：递归+dfs

说明：与559题相比较
    请与111题共同服用，效果更佳
    一个节点的“高度”等于孩子节点“高度”+1，设空指针的高度为0，那么递归调用即可得到答案

时间复杂度与空间复杂度：O(n) O(n)（树完全不平衡）- O(log(n))（树完全平衡）

涉及到的知识点：

***********************************************************************************************************/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution {
 public:
     int maxDepth(TreeNode* root) {
         if(root == NULL) return 0;
         int left_length = maxDepth(root->left);
         int right_length = maxDepth(root->right);
         return 1+max(left_length, right_length);
     }    
 };

 /**********************************************************************************************************
方法：队列+bfs（层序遍历）

说明：
    bfs，你也可以理解为层序遍历，就是遍历完一层，那么depth+1，直到没有层可遍历了，
    那么这个“层”的记录该如何实现呢？利用双向队列储存，去查看！

时间复杂度与空间复杂度：O(n) O(n)

涉及到的知识点：
    1. 双向队列deque<int/char/string>a 的操作：
        a.front() //返回双向队列的队头
        a.push_front() //向队头插入元素
        a.pop_front() //弹出队头元素，注意返回值为void！因此不允许利用 auto p = a.pop_front()去获取队头元素！
        同理back也是一样
        a.empty()  //队列是否为空，空true  不空false

***********************************************************************************************************/
 class Solution {
 public:
     int maxDepth(TreeNode* root) {
         if (root == NULL) return 0;
         deque<TreeNode*> q; //q是一个双向队列，里面储存的是TreeNode类型指针
         q.push_back(root); //将root根节点压入队列
         int depth = 0;
         while (!q.empty()) { //只要当队列不为空
             depth++;
             int num = q.size();

             //这里的循环是所有程序的关键点，意思是将所有第k层的节点全部pop出来，并压入k+1层的节点
             for (int i = 1; i <= num; i++) {
                 TreeNode* p = q.front();
                 q.pop_front();
                 if (p->left) q.push_back(p->left);
                 if (p->right) q.push_back(p->right);
             }
         }
         return depth;
     }
 };