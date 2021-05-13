#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
/**********************************************************************************************************
方法：
	利用BST的前序遍历，来解决BST的一系列问题，包括：
	1. 判断BST是否合法（98题）
	2. 增加节点
	3. 删除节点
	4. 查找节点

说明：

时间复杂度与空间复杂度：

涉及到的知识点：
	1. BST前序遍历：先访问根节点，再遍历左子树，再遍历右子树
		BST中序遍历：先遍历左子树，再访问根节点，再遍历右子树
		BST后序遍历：先遍历左子树，再遍历右子树，再访问根节点
	2. BST前序遍历模板
	    void traverse(TreeNode* root){
			//root需要做的事情
			//其他不用担心，直接抛给框架
			traverse(root->left);
			traverse(root->right);
		}
***********************************************************************************************************/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**********************************************************************************************************
	例子一：把二叉树的所有节点值加一
***********************************************************************************************************/
void plusOne(TreeNode* root) {
	if (!root) return;
	root->val += 1;
	plusOne(root->left);
	plusOne(root->right);
}

/**********************************************************************************************************
	例子二：判断两个二叉树是否完全相同
	拓展：剑指offer 26题：输入两个树（没有说是二叉搜索），判断B是不是A的子结构，定义空树不是任何树的子结构
***********************************************************************************************************/
//
bool isSameTree(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) return true;  //如果两棵树均为空树，那么当然是相同的了
	if (root1 == NULL || root2 == NULL) return false; //如果两棵树之中有一颗是空树，另一棵却不是，那么一定不完全相同
	if (root1->val != root2->val) return false; //如果指针对应的值不同，当然也不是完全相同的树

	//以上均是对root操作，下面的就是不变的框架（模板）啦
	return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right); //注意是&&而不是||，因为只要有一个不满足，那么就不满足
}
//分为：在A中查找各个节点，与B根节点匹配，前序遍历
//          判断A的子树与B是否全匹配，也是前序遍历
bool isSubStructure(TreeNode* A, TreeNode* B) {
	if (A == NULL || B == NULL) return false; //定义
	return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool recur(TreeNode* A, TreeNode* B) {
	if (B == NULL) return true;
	if (A == NULL || A->val != B->val) return false;
	return recur(A->left, B->left) && recur(A->right, B->right);
}

/**********************************************************************************************************
	例子三：判断BST是否合法
				 注意：我们必须要多传递两个参数，lower与upper，因为BST是否合法是看是否满足左子树所有节点
				 均小于根节点，右子树所有节点是否均大于根节点，而不是仅仅看与根节点连接在一起的孩子节点是否满足
***********************************************************************************************************/
bool dfs(TreeNode* q, int lower, int upper) {
	if (!q) return true;
	if (q->val <= lower || q->val >= upper) return false;

	return dfs(q->left, lower, q->val) && dfs(q->right, q->val, upper);
}
bool isValideBST(TreeNode* root) {
	int lower = INT_MIN;
	int upper = INT_MAX;
	return dfs(root, lower, upper);
}

/**********************************************************************************************************
	例子四：在一个BST中查找一个数是否存在
***********************************************************************************************************/
bool isInBST(TreeNode* root, int target) {
	if (!root) return false; //空树不包含任何节点，当然不存在啦
	if (root->val == target) return true;
	if (root->val > target) {
		return isInBST(root->left, target);
	}
	else {
		return isInBST(root->right, target);
	}
}

/**********************************************************************************************************
	例子五：在一个BST中插入一个数

	知识：new关键字，开辟一个空间，类似于C语言中的malloc，但是注意返回的是指针！！！		
***********************************************************************************************************/
TreeNode* insertIntoBST(TreeNode* root, int val) {

	//如果找到了空指针处，那么就直接将含有val的TreeNode指针插入到该处
	if (!root) return new TreeNode(val); //注意：在C++之中，new返回的是相应的结构体指针！而不是结构体本身！

	//如果根节点值大于val，说明val应该在根节点左侧插入，根节点左孩子就等于以左孩子为根节点，插入val后的指针值
	if (root->val > val) {
		root->left = insertIntoBST(root->left, val);
	}

	//如果根节点值小于val，说明val应该在根节点右侧插入，根节点右孩子就等于以右孩子为根节点，插入val后的指针值
	else {
		root->right = insertIntoBST(root->right, val);
	}
	return root; //返回插入后根节点指针
}

/**********************************************************************************************************
	例子六：在一个BST中删除一个数
	注意：删除该元素对应的节点，只是需要让这个值不在BST中出现即可，并且节点数-1，不是非要删除初始
	该元素在的那个节点值
***********************************************************************************************************/
TreeNode* getMin(TreeNode* root) {
	while (root->left) { //注意这里是root->left非空，若是写作root，那么返回的就是NULL了
		root = root->left; //注意：某个二叉树之中最小值，只需要一直找左子树即可找到，同理最大值
	}
	return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
	if (!root) return NULL;
	if (root->val == val) {
		//若待删除节点只有一个孩子，那么让孩子继承自己的位置即可
		if (root->right == NULL) return root->left;
		if (root->left == NULL) return root->right;

		//若待删除节点有两个孩子，那么必须从左子树之中找到值最大的节点，并让他继承自己
		//或者在右子树之中找到值最小的节点，并让它继承自己，这里选择了后者
		TreeNode* minNode = getMin(root->right); 

		root->val = minNode->val;
		root->right = deleteNode(root->right, minNode->val); //既然已经将minNode值找到并赋给了root，那么我们现在转而去删除minNode的值即可
	}

	else if (root->val > val) {
		root->left = deleteNode(root->left, val); //root的左子树是以左子树为根节点的树，删除了val对应的节点后的树
	}

	else {
		root->right = deleteNode(root->right, val);
	}
	return root;
}

/**********************************************************************************************************
	例子七(1)：计算一棵普通二叉树节点数目
	时间复杂度：O(n)
	空间复杂度：O(logn) 到 O(n)
***********************************************************************************************************/
int nodeNum(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + nodeNum(root->left) + nodeNum(root->right);
}

/**********************************************************************************************************
	例子七(2)：计算一棵满二叉树(perfect binary tree)节点数目
	时间复杂度：O(logn)
	空间复杂度：O(1)
***********************************************************************************************************/
int nodeNum(TreeNode* root) {
	int h = 0;
	while (root != NULL) {		
		root = root->left;
		h++;
	}
	return pow(2, h) - 1;
}

/**********************************************************************************************************
	例子七(3)：计算一棵完全二叉树(complete binary tree)节点数目
		注意：完全二叉树不一定是满二叉树，而满二叉树一定是完全二叉树
				  完全二叉树的左子树或者右子树一定有一个是满二叉树！

	时间复杂度：O(logn * logn)
		包括：首先求出lh与rh，用了O(logn)时间
				  接下来return值，用了O(logn)时间，至于为什么是logn时间，而不是n，是因为完全二叉树一半是满二叉树，
				  但为什么一半是满二叉树，时间复杂度变成了logn，不得而知

	空间复杂度：O(logn)
***********************************************************************************************************/
int nodeNum(TreeNode* root) {
	int lh = 0, rh = 0;
	TreeNode* temp = root;
	while (temp) {
		temp = temp->left;
		lh++;
	}
	temp = root;
	while (temp) {
		temp = temp->right;
		rh++;
	}
	if (lh == rh) return pow(2, lh) - 1; //如果左子树深度==右子树深度，说明是满二叉树，那么就可以直接返回
	return 1 + nodeNum(root->left) + nodeNum(root->right); //否则按照一般二叉树计算
}

/**********************************************************************************************************
	例子八：求出二叉树的所有路径
		注意：本题原题是257题二叉树的所有路径，不过由于这题特别典型，且变式非常多，最重要的是符合前序遍历
				  模板，因此拿来这里一说				 
		说明：相似题目：
				  257、112、113、
	时间复杂度：O(n)
	空间复杂度：O(n)
***********************************************************************************************************/
void binaryTreePaths(TreeNode* root, vector<string> ans, string temp) {
	if (root == NULL) return; //如果没有这个return，那么直接会报错，因为下面root->val会访问一个未定义的储存空间
	temp = temp + to_string(root->val);
	if (root->left == NULL && root->right == NULL) {
		ans.push_back(temp);
		return; //如果没有这个return，影响会是每个string后面多了一个->,比如说： 1->3->5->而不是1->3->5
	}
	binaryTreePaths(root->left, ans, temp + "->");
	binaryTreePaths(root->right, ans, temp + "->");
}

/**********************************************************************************************************
	其他例子：
	剑指offer 27 二叉树镜像
	剑指 Offer 28. 对称的二叉树
	104. 二叉树的最大深度
***********************************************************************************************************/

//有时候，可以在dfs里面加入层数信息，可以用dfs替代bfs -- > 515、

