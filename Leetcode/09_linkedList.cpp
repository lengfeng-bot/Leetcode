#include<iostream>
#include<vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(nullptr) {}
};



void insertNode(ListNode* &head,int val) {
	ListNode* newNode = new ListNode(val);
	if (!head) head = newNode;
	else
	{
		ListNode* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    std::cout << "nullptr" << std::endl;
}

/// <summary>
/// 删除链表1
/// </summary>
void deleteList(ListNode* &head,int value) {
    ListNode*  pre= head;
    ListNode* cur = head->next;
    while (cur)
    {   
        if (cur->val == value)
        {
            pre->next = cur->next;
            delete cur;  // Don't forget to free the memory of the deleted node.
            cur = pre->next;  // Move cur to the next node
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

}

/// <summary>
/// 删除链表2
/// </summary>
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pre = head;
    ListNode* cur = head->next;
    int value;
    while (cur)
    {
        if (cur->val == pre->val) {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
            value = pre->val;
        }

        else
        {
            if (pre->val == value) {
                cur->next = cur->next->next;
                pre->next = cur->next;
                delete pre;
            }
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}


/// <summary>
/// 反转链表
/// </summary>
ListNode*& reverseList(ListNode* head) {
    
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur)
    {
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    head= pre;
    return head;
}

/// <summary>
/// 回文链表
/// </summary>
/// 1.首先想到的思路是，创建一个翻转链表，然后每个元素进行对比，如果都一样的话，那就是回文链表，先实现一下
/// 这个思路不对，我反转了链表，就改变了原有链表的结构，就没法与原来的链表比较了。
/// 2.想起了可以用快慢指针，但是有一个问题，我不能从两头到中间进行比较，因为链表是单向的，只能从一个方向运动。
/// 那只能把链表的值赋值到数组中，再使用双指针了
bool isPalindrome(ListNode* head) {
    ListNode* cur = head;
    vector<int>nums;
    while (cur)
    {   nums.push_back(cur->val);
        cur = cur->next;
        
    }
    for (auto num : nums) { cout << num<<" "; }cout << endl;
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
        if (nums[l] != nums[r])
            return false;
        l++;
        r--;

    }
    return true;
}

/// <summary>
/// 合并两个有序列表
/// </summary>
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
    
}


/// <summary>
/// 两两交换链表中的节点
/// </summary>
//ListNode* swapPairs(ListNode* head) {
//
//}




//int main() {
//	ListNode* head = nullptr;
//	insertNode(head, 1);
//	insertNode(head, 2);
//	insertNode(head, 3);
//	insertNode(head, 2);
//	insertNode(head, 1);
//	printList(head);
//    //deleteList(head, 4);
//    int a = isPalindrome(head);
//    cout << a;
//    //printList(head);
//
//}





/// </summary>
///链表中的双指针问题
/// /// </summary>
/// 
/// 
/// 
/// 


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
    if (cur != nullptr) {
        slow->next = cur->next;
        delete cur;
    }

    ListNode* retNode = dummyHead->next;
    delete dummyHead;
    return retNode;


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
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (fast == nullptr || fast->next == nullptr) return nullptr;
    fast = head;
    while (slow != fast)
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