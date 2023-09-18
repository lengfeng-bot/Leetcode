
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;






/// <summary>
/// 一、循环不变量
/// </summary>


/// <summary>
/// 1.删除有序数组中的重复项---最简单的快慢指针！
/// </summary>
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];

        }
    }
    return j + 1;
}

/// <summary>
/// 最长连续递增数列
/// </summary>
int findLengthOfLCIS(vector<int>& nums) {
    int l = 0;
    int len = 0;
    for (int r = 1; r < nums.size(); r++)
    {   
        if (nums[r] <= nums[r-1]) 
        {   
        l = r ;
       
        }
        int prelen = r - l+1;
        len = max(len, prelen);
    }

    return len;
}



//int main()
//{
//    vector<int>nums = {1,3,5,7 };
//    int a = findLengthOfLCIS(nums);
//    cout << a << endl;
//    return 0;
//}


/// <summary>
/// 删除排序数组中的重复项 II
/// </summary>

int removeDuplicates2(vector<int>& nums) {
    int slow = 2;
    if (nums.size() <= 2)  return nums.size();
    for (int fast = 2; fast < nums.size(); fast++)
    {
        if (nums[fast] != nums[slow - 2])  //是slow不是fast
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}


//int main()
//{
//    vector<int>nums = { 1,1,1,2,2,3 };
//    int a = removeDuplicates2(nums);
//    cout << a << endl;
//    return 0;
//}


/// <summary>
/// 颜色分类
/// </summary>
/// <param name="nums"></param>
void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    int i = 0;
    while (i<=r)
    {
        if (nums[i] == 2)
        {
            int tmp = nums[i];
            nums[i] = nums[r];
            nums[r] = tmp;
            r--;
        }
        else if (nums[i] == 0)
        {
            int tmp = nums[i];
            nums[i] = nums[l];
            nums[l] = tmp;
            l++;
        }
        else
            i++;
    }
}


/// <summary>
/// 数组中的第 K 个最大元素--快速排序
/// </summary>
int findKthLargest(vector<int>& nums, int k) {
    return 0;
}




/// </summary>
///链表中的双指针问题
/// /// </summary>
/// 
/// 
/// 
/// 
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
/// <summary>
/// 判断环形链表
/// </summary>
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}








//int main() {
//    // 创建一个有环的链表示例
//    ListNode* head = new ListNode(1);
//    ListNode* second = new ListNode(2);
//    ListNode* third = new ListNode(3);
//    ListNode* fourth = new ListNode(4);
//
//    head->next = second;
//    second->next = third;
//    third->next = fourth;
//    fourth->next = second;  // 使链表成环
//
//    if (hasCycle(head)) {
//        std::cout << "链表中存在环。" << std::endl;
//    }
//    else {
//        std::cout << "链表中不存在环。" << std::endl;
//    }
//
//    // 清理链表内存
//    delete fourth;
//    delete third;
//    delete second;
//    delete head;
//
//    return 0;
//}


/// <summary>
/// 删除链表的倒数第n个结点
/// </summary>
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* fast = dummyHead;
    ListNode* slow = dummyHead;
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* cur = slow->next;
    if (cur != nullptr){
    slow->next = cur->next;
    delete cur;
    }

    ListNode* retNode = dummyHead->next;
    delete dummyHead;
    return retNode;


}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

//int main() {
//    // 创建一个示例链表：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
//    ListNode* head = new ListNode(0);
//    head->next = new ListNode(1);
//    head->next->next = new ListNode(2);
//    head->next->next->next = new ListNode(3);
//    head->next->next->next->next = new ListNode(4);
//    head->next->next->next->next->next = new ListNode(5);
//    head->next->next->next->next->next->next = new ListNode(6);
//
//    std::cout << "原始链表：" << std::endl;
//    printList(head);
//
//    int valToRemove = 2;
//    head = removeNthFromEnd(head, valToRemove);
//
//    std::cout << "移除元素 " << valToRemove << " 后的链表：" << std::endl;
//    printList(head);
//
//    // 释放链表内存
//    while (head) {
//        ListNode* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    return 0;
//}

/// <summary>
/// 链表的中间结点
/// </summary>
/// 快指针走两步，慢指针走一步，这样的话，快指针到达终点时候，慢指针就到达了中点。
/// 如果链表节点数为偶数，需要返回第二个中间节点，这样的话，要保证此时快指针以及他的下一位都为空
ListNode* middleNode(ListNode* head) {

	ListNode* fast = head, * slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;

}


ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (fast == nullptr || fast->next == nullptr) return nullptr;
    fast = head;
    while (slow!= fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

/// <summary>
/// 相交链表
/// </summary>
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        // 如果 pA 到达链表末尾，则将其重定向到 headB
        pA = (pA == nullptr) ? headB : pA->next;

        // 如果 pB 到达链表末尾，则将其重定向到 headA
        pB = (pB == nullptr) ? headA : pB->next;
    }

    // 返回交叉点或 nullptr
    return pA;
}





/// <summary>
/// 双指针----相向交替移动的两个变量
/// </summary>
/// 
/// 
/// <summary>
/// 盛水最多的容器
/// </summary>

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int maxarea = 0;
    while (i<j)
    {   
        int area = min(height[j], height[i]) * (j - i);
        if (height[i] > height[j])
            j--;
        else
            i++;
        maxarea = max(maxarea, area);
        
    }
    return maxarea;
}


///双指针的学习之旅就到这吧！接下来是一些有关双指针的练习题，也许大概可能我以后会做一下吧。。。
/// 
/// 习题训练
/// 
/// 最接近的三数之和
/// 四数之和
/// 接雨水
/// 较小的三数之和
/// 有序转化数组
/// 比较含退格的字符串
/// 数组中的最长山脉
/// 救生艇
/// 长按键入
/// 有序数组的平方
/// 小于 K 的两数之和
/// 安排会议日程
/// 


/// <summary>
/// 四数之和
/// </summary>
/// 先来个四数之和！
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    if (n < 4)
        return res;

    int l = 0;
    int r = n - 1;
    int sum = 0;
    
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)break;
        {

        }
        for (int j = i+1; j < n-2; j++)
        {

        }
    }
    return res;
}

