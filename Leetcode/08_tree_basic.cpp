#include<iostream>
#include<vector>
#include <functional>
#include<deque>
#include <queue>

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
    if (!root)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}


/// <summary>
/// 计算二叉树最大深度
/// </summary>
int maxDepth(TreeNode* root) {

    if (!root)
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
/// 判断二叉树是否对称
/// </summary>
/// 
bool check(TreeNode* l, TreeNode* r) {
    if (!l && !r) return true;
    if (!l || !r)  return false;
    return l->val == r->val && check(l->left, r->right)&& check(l->right,r->left);
}
//bool isSymmetric(TreeNode* root) {
//    check(root->left, root->right);
//}





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



//int main() {
//    vector<int>  nums = {3, 2, 1, 6, 0, 5};
//    TreeNode* root = constructMaximumBinaryTree(nums);
//    printTree(root);
//    // 释放内存
//    freeTree(root);
//
//    return 0;
//}



/// <summary>
/// 二叉树层序遍历 -----BFS
/// </summary>
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        vector<int>vals;
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)  //这里不能直接 i<q.size(),因为for循环中的操作会改变size的大小
        {
            TreeNode* cur = q.front();
            q.pop();
            vals.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        ans.push_back(vals);
    }
    return ans;
}


/// <summary>
/// 二叉树锯齿形层序遍历
/// </summary>
/// 跟上面的很接近，就是需要在偶数层进行方向的翻转，这时候，双端队列就更适合了
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    deque<TreeNode*>dq;
    if (root)
       dq.push_front(root);
    bool leftToRight = true; // 控制遍历方向
    while (!dq.empty())
    {
        vector<int>vals;
        int levelSize = dq.size();
        for (int i = 0; i < levelSize; i++)  //这里不能直接 i<q.size(),因为for循环中的操作会改变size的大小
        {
            if (leftToRight)
            {
            TreeNode* cur = dq.front();
            dq.pop_front();

            vals.push_back(cur->val);
            if (cur->left)
                dq.push_back(cur->left);
            if (cur->right)
                dq.push_back(cur->right);
            }
            else
            {  
                TreeNode* cur = dq.back();
                dq.pop_back();
                vals.push_back(cur->val);
                if (cur->right)
                    dq.push_front(cur->right);
                if (cur->left)
                    dq.push_front(cur->left);

            }

        }
        leftToRight = !leftToRight;
        ans.push_back(vals);
    }
    return ans;
}


/// <summary>
/// 二叉树的直径
/// </summary>
/// 
/// 
//int dfs(TreeNode* node, int& diameter) {
//    if (!node) return 0;
//    int L = dfs(node->left, diameter);
//    int R = dfs(node->right, diameter);
//
//    diameter =max(diameter, L + R);
//    return max(L , R) + 1;
//}
//
//int diameterOfBinaryTree(TreeNode* root) {
//    if (root == nullptr)
//        return 0;
//
//    int diameter = 0;
//    dfs(root, diameter);
//    return diameter;
//}


//int main() {
//    // 构建一棵二叉树的示例
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//
//    int result =diameterOfBinaryTree(root);
//
//    cout << "二叉树的直径是: " << result << endl;
//
//    return 0;
//}

/// <summary>
/// 相同的树
/// </summary>
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    else if (p == nullptr || q == nullptr) {
        return false;
    }
    else if (p->val != q->val) {
        return false;
    }
    else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
/// <summary>
/// 二叉树中的链表
/// </summary>
bool dfs(TreeNode* rt, ListNode* head) {
    // 链表已经全部匹配完，匹配成功
    if (head == NULL) return true;
    // 二叉树访问到了空节点，匹配失败
    if (rt == NULL) return false;
    // 当前匹配的二叉树上节点的值与链表节点的值不相等，匹配失败
    if (rt->val != head->val) return false;
    return dfs(rt->left, head->next) || dfs(rt->right, head->next);
}

bool isSubPath(ListNode* head, TreeNode* root) {
     if (root == NULL) return false;
     return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
}


/// <summary>
/// 找树左下角的值
/// </summary>
/// 先用一下BFS求解吧
/// 
int findBottomLeftValue1(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    int result = 0;
    while (!q.empty())
    {
        vector<int>layer;
        int layersize = q.size();
        for (int i = 0; i < layersize; i++)
        {
             TreeNode* cur = q.front();
             q.pop();
             layer.push_back(cur->val);
             if (cur->left)
                q.push(cur->left);
             if (cur->right)
                q.push(cur->right);
        }
        result = layer[0];
       
    }
    return result;
}

/// <summary>
/// 再用一下DFS求解
/// </summary>
/// 相同深度，最左边，不同深度，最深的最左边
/// 

//void dfs(TreeNode* root, int height, int& curval, int& curheight) {
//    if (root == nullptr) return;
//    height++;
//    dfs(root->left, height, curval, curheight);
//    dfs(root->right, height, curval, curheight);
//    if (height > curheight) {
//        curheight = height;
//        curval = root->val;
//    }
//}
//int findBottomLeftValue(TreeNode* root) {
//    int curval = 0;
//    int curheight = 0;
//    dfs(root, 0, curval, curheight);
//    return curval;
//}



/// <summary>
/// 在每个树行中找最大值
/// </summary>
/// <param name="root"></param>
/// <returns></returns>
vector<int> largestValues(TreeNode* root) {
    if (!root)  return {};
    queue<TreeNode*>q;
    q.push(root);
    int result = 0;
    vector<int>layer;
    while (!q.empty())
    {
        
        int layersize = q.size();
        int a = 0;
        for (int i = 0; i < layersize; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            a = max(a, cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        layer.push_back(a);

    }
    return layer;
}


/// <summary>
/// 完全二叉树节点个数
/// </summary>
int countNodes1(TreeNode* root) {
    if (!root) return 0;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    int leftdepth = 0, rightdepth = 0;
    while (l)
    {
        l = l->left;
        leftdepth++;
    }
    while (r)
    {
        r = r->right;
        rightdepth++;
    }
    if (leftdepth == rightdepth)  return (2 << leftdepth) - 1;
    return  countNodes(root->left) + countNodes(root->right) + 1;
}



/// <summary>
/// 平衡二叉树
/// </summary>
/// 
int treeHeight(TreeNode* root) {
    if (!root) return 0;
    int leftHeight = treeHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = treeHeight(root->right);
    if (rightHeight == -1) return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return treeHeight(root) == -1 ? false : true;
}


/// <summary>
/// 二叉树的所有路径
/// </summary>
/// 
/// 
//void dfs(TreeNode* root, vector<string>& paths, string cur_path) {
//
//    if (root == nullptr) return;
//
//    cur_path += to_string(root->val);
//    
//    if (root->left == nullptr && root->right == nullptr) {
//        paths.push_back(cur_path);
//        return;
//    }
//    cur_path += "->";
//    dfs(root->left, paths, cur_path);
//    dfs(root->right, paths, cur_path);
//}


//vector<string> binaryTreePaths(TreeNode* root) {
//    vector<std::string> paths;
//    string cur_path = "";
//    dfs(root, paths, cur_path);
//    return paths;
//}


/// <summary>
/// 二叉树的左视图
/// </summary>
/// bfs写法
//vector<int> rightSideView(TreeNode* root) {
//    vector<int>ans;
//    if (root == nullptr)  return ans;
//    queue<TreeNode*>q;
//    q.push(root);
//    while (!q.empty())
//    {
//        int size = q.size();
//        for (int i = 0; i < size; i++)
//        {
//            TreeNode* cur = q.front();
//            q.pop();
//            if (cur->left)q.push(cur->left);
//            if (cur->right)q.push(cur->right);
//            if (i == size - 1) ans.push_back(cur->val);
//        }
//
//    }
//    return ans;
//}

//void dfs(TreeNode* root, int depth,vector<int>&ans) {
//    if (root == nullptr)  return;
//    if (depth == ans.size()) ans.push_back(root->val);
//    depth++;
//    dfs(root->right, depth, ans);
//    dfs(root->left, depth, ans);
//}
//
//vector<int> rightSideView(TreeNode* root) {
//    vector<int>ans;
//    dfs(root, 0, ans);
//    return ans;
//
//}



//int main() {
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->right = new TreeNode(4);
//    vector<int>ans = rightSideView(root);
//
//    for (auto a : ans) cout << a << " ";
//    return 0;
//}



/// <summary>
/// 二叉树的所有路径
/// </summary>
/// 
/// 
//void dfs(TreeNode* root, vector<string>& paths, string cur_path) {
//
//    if (root == nullptr) return;
//
//    cur_path += to_string(root->val);
//    
//    if (root->left == nullptr && root->right == nullptr) {
//        paths.push_back(cur_path);
//        return;
//    }
//    cur_path += "->";
//    dfs(root->left, paths, cur_path);
//    dfs(root->right, paths, cur_path);
//}


//vector<string> binaryTreePaths(TreeNode* root) {
//    vector<std::string> paths;
//    string cur_path = "";
//    dfs(root, paths, cur_path);
//    return paths;
//}


/// <summary>
/// 路径之和
/// </summary>
bool hasPathSum(TreeNode* root, int targetSum) {

    if (!root) return false;

    if (!root->left && !root->right && targetSum == root->val) return true;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}


/// <summary>
/// 路径之和2
/// </summary>
/// 
//void dfs(TreeNode* root, vector<vector<int>>&paths, vector<int>cur_path, int targetSum) {
//    if (!root) return;
//
//    cur_path.push_back(root->val);
//
//    if (!root->left && !root->right) {
//        if (targetSum == root->val)  paths.push_back(cur_path);
//    }
//
//    dfs(root->left, paths, cur_path, targetSum - root->val);
//    dfs(root->right, paths, cur_path, targetSum - root->val);
//    cur_path.pop_back();
//}
//
//
//vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//    vector<vector<int>>ans;
//    vector<int>cur_path;
//    dfs(root, ans, cur_path, targetSum);
//    return ans;
//}


//int main() {
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(1);
//    root->left->right = new TreeNode(5);
//
//    int targetSum = 4;
//    vector<vector<int>>ans = pathSum(root, targetSum);
//
//    for (auto an : ans) {
//        for (auto a : an) cout << a << " ";
//
//        cout << endl;
//    }
//
//    return 0;
//}

/// <summary>
/// 路径之和3
/// </summary>
/// 
void dfs(TreeNode* root, int& sum, int targetSum, int& num_path) {

    if (!root) return;
    sum += root->val;
    if (sum == targetSum) {num_path++; sum = 0;}
    dfs(root->left, sum, targetSum, num_path);
    sum = 0;
    dfs(root->right, sum, targetSum, num_path);

}



int pathSum3(TreeNode* root, int targetSum) {
    int num_path = 0;
    int sum = 0;
    dfs(root, sum, targetSum, num_path);

    return num_path;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->right->right = new TreeNode(4);

    int targetSum = 3;
    int ans = pathSum3(root, targetSum);
    cout << ans;
    return 0;


}