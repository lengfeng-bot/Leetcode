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
/// ɾ������1
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
/// ɾ������2
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
/// ��ת����
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
/// ��������
/// </summary>
/// 1.�����뵽��˼·�ǣ�����һ����ת����Ȼ��ÿ��Ԫ�ؽ��жԱȣ������һ���Ļ����Ǿ��ǻ���������ʵ��һ��
/// ���˼·���ԣ��ҷ�ת�������͸ı���ԭ������Ľṹ����û����ԭ��������Ƚ��ˡ�
/// 2.�����˿����ÿ���ָ�룬������һ�����⣬�Ҳ��ܴ���ͷ���м���бȽϣ���Ϊ�����ǵ���ģ�ֻ�ܴ�һ�������˶���
/// ��ֻ�ܰ������ֵ��ֵ�������У���ʹ��˫ָ����
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
/// �ϲ����������б�
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
/// �������������еĽڵ�
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
///�����е�˫ָ������
/// /// </summary>
/// 
/// 
/// 
/// 


/// <summary>
/// �жϻ�������
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
//    // ����һ���л�������ʾ��
//    ListNode* head = new ListNode(1);
//    ListNode* second = new ListNode(2);
//    ListNode* third = new ListNode(3);
//    ListNode* fourth = new ListNode(4);
//
//    head->next = second;
//    second->next = third;
//    third->next = fourth;
//    fourth->next = second;  // ʹ����ɻ�
//
//    if (hasCycle(head)) {
//        std::cout << "�����д��ڻ���" << std::endl;
//    }
//    else {
//        std::cout << "�����в����ڻ���" << std::endl;
//    }
//
//    // ���������ڴ�
//    delete fourth;
//    delete third;
//    delete second;
//    delete head;
//
//    return 0;
//}


/// <summary>
/// ɾ������ĵ�����n�����
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
//    // ����һ��ʾ������1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
//    ListNode* head = new ListNode(0);
//    head->next = new ListNode(1);
//    head->next->next = new ListNode(2);
//    head->next->next->next = new ListNode(3);
//    head->next->next->next->next = new ListNode(4);
//    head->next->next->next->next->next = new ListNode(5);
//    head->next->next->next->next->next->next = new ListNode(6);
//
//    std::cout << "ԭʼ����" << std::endl;
//    printList(head);
//
//    int valToRemove = 2;
//    head = removeNthFromEnd(head, valToRemove);
//
//    std::cout << "�Ƴ�Ԫ�� " << valToRemove << " �������" << std::endl;
//    printList(head);
//
//    // �ͷ������ڴ�
//    while (head) {
//        ListNode* temp = head;
//        head = head->next;
//        delete temp;
//    }
//
//    return 0;
//}

/// <summary>
/// ������м���
/// </summary>
/// ��ָ������������ָ����һ���������Ļ�����ָ�뵽���յ�ʱ����ָ��͵������е㡣
/// �������ڵ���Ϊż������Ҫ���صڶ����м�ڵ㣬�����Ļ���Ҫ��֤��ʱ��ָ���Լ�������һλ��Ϊ��
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
/// �ཻ����
/// </summary>
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        // ��� pA ��������ĩβ�������ض��� headB
        pA = (pA == nullptr) ? headB : pA->next;

        // ��� pB ��������ĩβ�������ض��� headA
        pB = (pB == nullptr) ? headA : pB->next;
    }

    // ���ؽ����� nullptr
    return pA;
}