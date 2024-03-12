#include<iostream>
#include<vector>
#include <functional>
#include<deque>
#include <queue>

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

    if (!root)
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
/// �ж϶������Ƿ�Գ�
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



//int main() {
//    vector<int>  nums = {3, 2, 1, 6, 0, 5};
//    TreeNode* root = constructMaximumBinaryTree(nums);
//    printTree(root);
//    // �ͷ��ڴ�
//    freeTree(root);
//
//    return 0;
//}



/// <summary>
/// ������������� -----BFS
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
        for (int i = 0; i < levelSize; i++)  //���ﲻ��ֱ�� i<q.size(),��Ϊforѭ���еĲ�����ı�size�Ĵ�С
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
/// ����������β������
/// </summary>
/// ������ĺܽӽ���������Ҫ��ż������з���ķ�ת����ʱ��˫�˶��о͸��ʺ���
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    deque<TreeNode*>dq;
    if (root)
       dq.push_front(root);
    bool leftToRight = true; // ���Ʊ�������
    while (!dq.empty())
    {
        vector<int>vals;
        int levelSize = dq.size();
        for (int i = 0; i < levelSize; i++)  //���ﲻ��ֱ�� i<q.size(),��Ϊforѭ���еĲ�����ı�size�Ĵ�С
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
/// ��������ֱ��
/// </summary>
/// 
/// 
int dfs(TreeNode* node, int& diameter) {
    if (!node) return 0;
    int L = dfs(node->left, diameter);
    int R = dfs(node->right, diameter);

    diameter =max(diameter, L + R);
    return max(L , R) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}


//int main() {
//    // ����һ�ö�������ʾ��
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//
//    int result =diameterOfBinaryTree(root);
//
//    cout << "��������ֱ����: " << result << endl;
//
//    return 0;
//}

/// <summary>
/// ��ͬ����
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
/// �������е�����
/// </summary>
bool dfs(TreeNode* rt, ListNode* head) {
    // �����Ѿ�ȫ��ƥ���꣬ƥ��ɹ�
    if (head == NULL) return true;
    // ���������ʵ��˿սڵ㣬ƥ��ʧ��
    if (rt == NULL) return false;
    // ��ǰƥ��Ķ������Ͻڵ��ֵ������ڵ��ֵ����ȣ�ƥ��ʧ��
    if (rt->val != head->val) return false;
    return dfs(rt->left, head->next) || dfs(rt->right, head->next);
}

bool isSubPath(ListNode* head, TreeNode* root) {
     if (root == NULL) return false;
     return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
}


/// <summary>
/// �������½ǵ�ֵ
/// </summary>
/// ����һ��BFS����
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
/// ����һ��DFS���
/// </summary>
/// ��ͬ��ȣ�����ߣ���ͬ��ȣ�����������
/// 

void dfs(TreeNode* root, int height, int& curval, int& curheight) {
    if (root == nullptr) return;
    height++;
    dfs(root->left, height, curval, curheight);
    dfs(root->right, height, curval, curheight);
    if (height > curheight) {
        curheight = height;
        curval = root->val;
    }
}
int findBottomLeftValue(TreeNode* root) {
    int curval = 0;
    int curheight = 0;
    dfs(root, 0, curval, curheight);
    return curval;
}



/// <summary>
/// ��ÿ�������������ֵ
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
/// ������������ͼ
/// </summary>
void bfs(TreeNode* node, int height, vector<int>& nums) {
    if (node == nullptr) return;

    if (nums.size() == height) {
        nums.push_back(node->val);
    }

    height++;
    bfs(node->right, height, nums);
    bfs(node->left, height, nums);

}

vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    if (root == nullptr) return ans; // ���ڵ�Ϊ��ʱֱ�ӷ��ؿ�����
    bfs(root, 0, ans);
    return ans;

}