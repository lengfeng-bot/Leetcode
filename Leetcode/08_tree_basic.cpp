#include<iostream>
#include<vector>
#include <functional>

using namespace std;



// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/// <summary>
/// 释放二叉树
/// </summary>
void  freeTree(TreeNode* root) {
    if(root)
    {
        freeTree(root->right);
        freeTree(root->left);
        delete  root;

    }
}


///二叉树的遍历
/// 前序遍历  根 左 右
/// 中序遍历  左 根 右
/// 后续遍历  左 右 根
// 辅助递归函数
void inorderHelper(TreeNode* node, vector<int>& result) {
    if (node == nullptr)
        return;
    inorderHelper(node->left, result);
    result.push_back(node->val);
    inorderHelper(node->right, result);
}

// 中序遍历函数
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

/// <summary>
/// 计算二叉树的节点个数
/// </summary>
int countNodes(TreeNode* root) {
    while (!root)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}


/// <summary>
/// 计算二叉树最大深度
/// </summary>
int maxDepth(TreeNode* root) {

    while (!root)
    {
        return 0;
    }
    return max(maxDepth(root->right), maxDepth(root->left))+1;

}

/// <summary>
/// 计算二叉树的最小深度
/// </summary>
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left || !root->right)  return minDepth(root->right) + minDepth(root->left) + 1;  //important!
    return min(minDepth(root->right), minDepth(root->left)) + 1;
}


//int main() {
// /*创建一个二叉树
//        1
//       / \
//      5    2
//          / \
//         3   4
//*/
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(5);
//    root->right = new TreeNode(2);
//    root->right->left = new TreeNode(3);
//    root->right->right = new TreeNode(4);
//
//    //// 进行中序遍历
//    //vector<int> result = inorderTraversal(root);
//
//    //// 输出遍历结果
//    //cout << "中序遍历结果: ";
//    //for (int val : result) {
//    //    cout << val << " ";
//    //}
//    //cout << endl;
//
//    int depth = minDepth(root);
//    cout << "二叉树最小深度: " << depth << endl;
//
//
//    // 释放内存
//    freeTree(root);
//
//    return 0;
//}


/// <summary>
/// 翻转二叉树
/// </summary>
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    // 备份左子树
    TreeNode* temp = root->left;

    // 翻转左子树为右子树
    root->left = invertTree(root->right);

    // 翻转右子树为备份的左子树
    root->right = invertTree(temp);

    return root;
}




/// <summary>
/// 二叉树中最小节点
/// </summary>
int findMinimumValue(TreeNode* root) {
    if (!root) return INT_MAX;

  
    int min1 = min(findMinimumValue(root->left), findMinimumValue(root->right));

    return min(min1,root->val);


}

/// <summary>
/// 二叉树中倒数第二小的节点
/// </summary>
/// 用到了dfs，不会哇
int findSecondMinimumValue(TreeNode* root) {
    if (!root) return -1;

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;

        if (node->val < min1) {
            min2 = min1;
            min1 = node->val;
        }
        else if (node->val > min1 && node->val < min2) {
            min2 = node->val;
        }

        dfs(node->left);
        dfs(node->right);
        };

    dfs(root);

    return (min2 == INT_MAX) ? -1 : min2;

}





void printTree(TreeNode* root, int depth = 0, char prefix = ' ') {
    if (!root) {
        return;
    }

    // 打印右子树
    printTree(root->right, depth + 1, '/');

    // 打印当前节点
    std::cout << std::string(depth * 4, ' ') << prefix << "[" << root->val << "]" << std::endl;

    // 打印左子树
    printTree(root->left, depth + 1, '\\');
}


/// <summary>
/// 构建最大二叉树
/// </summary>
TreeNode* constructMaximumBinaryTree(vector<int>& nums,int left,int right) {
    if (left > right) {
        return nullptr;
    }
    int maxIndex = left;
    for (int i = left+1; i <= right; i++)
    {  
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }

    }

    TreeNode* root = new TreeNode(nums[maxIndex]);

    root->left = constructMaximumBinaryTree(nums,left, maxIndex - 1);
    root->right = constructMaximumBinaryTree(nums, maxIndex + 1,right);

    return root;

}

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
}



int main() {
    vector<int>  nums = {3, 2, 1, 6, 0, 5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    printTree(root);
    // 释放内存
    freeTree(root);

    return 0;
}