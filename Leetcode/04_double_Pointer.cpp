
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;






/// <summary>
/// һ��ѭ��������
/// </summary>


/// <summary>
/// 1.ɾ�����������е��ظ���---��򵥵Ŀ���ָ�룡
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
/// �������������
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
/// ɾ�����������е��ظ��� II
/// </summary>

int removeDuplicates2(vector<int>& nums) {
    int slow = 2;
    if (nums.size() <= 2)  return nums.size();
    for (int fast = 2; fast < nums.size(); fast++)
    {
        if (nums[fast] != nums[slow - 2])  //��slow����fast
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
/// ��ɫ����
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
/// �����еĵ� K �����Ԫ��--��������
/// </summary>
int findKthLargest(vector<int>& nums, int k) {
    return 0;
}




/// </summary>
///�����е�˫ָ������
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





/// <summary>
/// ˫ָ��----�������ƶ�����������
/// </summary>
/// 
/// 
/// <summary>
/// ʢˮ��������
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


///˫ָ���ѧϰ֮�þ͵���ɣ���������һЩ�й�˫ָ�����ϰ�⣬Ҳ���ſ������Ժ����һ�°ɡ�����
/// 
/// ϰ��ѵ��
/// 
/// ��ӽ�������֮��
/// ����֮��
/// ����ˮ
/// ��С������֮��
/// ����ת������
/// �ȽϺ��˸���ַ���
/// �����е��ɽ��
/// ����ͧ
/// ��������
/// ���������ƽ��
/// С�� K ������֮��
/// ���Ż����ճ�
/// 


/// <summary>
/// ����֮��
/// </summary>
/// ����������֮�ͣ�
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

