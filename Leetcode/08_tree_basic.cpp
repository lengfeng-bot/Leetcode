#include<iostream>
#include<vector>
#include <functional>

using namespace std;



// ����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/// <summary>
/// �ͷŶ�����
/// </summary>
void  freeTree(TreeNode* root) {
    if(root)
    {
        freeTree(root->right);
        freeTree(root->left);
        delete  root;

    }
}


///�������ı���
/// ǰ�����  �� �� ��
/// �������  �� �� ��
/// ��������  �� �� ��
// �����ݹ麯��
void inorderHelper(TreeNode* node, vector<int>& result) {
    if (node == nullptr)
        return;
    inorderHelper(node->left, result);
    result.push_back(node->val);
    inorderHelper(node->right, result);
}

// �����������
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

/// <summary>
/// ����������Ľڵ����
/// </summary>
int countNodes(TreeNode* root) {
    while (!root)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}


/// <summary>
/// ���������������
/// </summary>
int maxDepth(TreeNode* root) {

    while (!root)
    {
        return 0;
    }
    return max(maxDepth(root->right), maxDepth(root->left))+1;

}

/// <summary>
/// �������������С���
/// </summary>
int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left || !root->right)  return minDepth(root->right) + minDepth(root->left) + 1;  //important!
    return min(minDepth(root->right), minDepth(root->left)) + 1;
}


//int main() {
// /*����һ��������
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
//    //// �����������
//    //vector<int> result = inorderTraversal(root);
//
//    //// ����������
//    //cout << "����������: ";
//    //for (int val : result) {
//    //    cout << val << " ";
//    //}
//    //cout << endl;
//
//    int depth = minDepth(root);
//    cout << "��������С���: " << depth << endl;
//
//
//    // �ͷ��ڴ�
//    freeTree(root);
//
//    return 0;
//}


/// <summary>
/// ��ת������
/// </summary>
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    // ����������
    TreeNode* temp = root->left;

    // ��ת������Ϊ������
    root->left = invertTree(root->right);

    // ��ת������Ϊ���ݵ�������
    root->right = invertTree(temp);

    return root;
}




/// <summary>
/// ����������С�ڵ�
/// </summary>
int findMinimumValue(TreeNode* root) {
    if (!root) return INT_MAX;

  
    int min1 = min(findMinimumValue(root->left), findMinimumValue(root->right));

    return min(min1,root->val);


}

/// <summary>
/// �������е����ڶ�С�Ľڵ�
/// </summary>
/// �õ���dfs��������
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

    // ��ӡ������
    printTree(root->right, depth + 1, '/');

    // ��ӡ��ǰ�ڵ�
    std::cout << std::string(depth * 4, ' ') << prefix << "[" << root->val << "]" << std::endl;

    // ��ӡ������
    printTree(root->left, depth + 1, '\\');
}


/// <summary>
/// ������������
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
    // �ͷ��ڴ�
    freeTree(root);

    return 0;
}