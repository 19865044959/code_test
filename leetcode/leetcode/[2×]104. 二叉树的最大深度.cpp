#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

/**********************************************************************************************************
�������ݹ�+dfs

˵������559����Ƚ�
    ����111�⹲ͬ���ã�Ч������
    һ���ڵ�ġ��߶ȡ����ں��ӽڵ㡰�߶ȡ�+1�����ָ��ĸ߶�Ϊ0����ô�ݹ���ü��ɵõ���

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)������ȫ��ƽ�⣩- O(log(n))������ȫƽ�⣩

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
     int maxDepth(TreeNode* root) {
         if(root == NULL) return 0;
         int left_length = maxDepth(root->left);
         int right_length = maxDepth(root->right);
         return 1+max(left_length, right_length);
     }    
 };

 /**********************************************************************************************************
����������+bfs�����������

˵����
    bfs����Ҳ�������Ϊ������������Ǳ�����һ�㣬��ôdepth+1��ֱ��û�в�ɱ����ˣ�
    ��ô������㡱�ļ�¼�����ʵ���أ�����˫����д��棬ȥ�鿴��

ʱ�临�Ӷ���ռ临�Ӷȣ�O(n) O(n)

�漰����֪ʶ�㣺
    1. ˫�����deque<int/char/string>a �Ĳ�����
        a.front() //����˫����еĶ�ͷ
        a.push_front() //���ͷ����Ԫ��
        a.pop_front() //������ͷԪ�أ�ע�ⷵ��ֵΪvoid����˲��������� auto p = a.pop_front()ȥ��ȡ��ͷԪ�أ�
        ͬ��backҲ��һ��
        a.empty()  //�����Ƿ�Ϊ�գ���true  ����false

***********************************************************************************************************/
 class Solution {
 public:
     int maxDepth(TreeNode* root) {
         if (root == NULL) return 0;
         deque<TreeNode*> q; //q��һ��˫����У����洢�����TreeNode����ָ��
         q.push_back(root); //��root���ڵ�ѹ�����
         int depth = 0;
         while (!q.empty()) { //ֻҪ�����в�Ϊ��
             depth++;
             int num = q.size();

             //�����ѭ�������г���Ĺؼ��㣬��˼�ǽ����е�k��Ľڵ�ȫ��pop��������ѹ��k+1��Ľڵ�
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