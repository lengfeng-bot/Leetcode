#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


/*
///�����㷨ͨ������ʱ�临�ӶȽ��з���
1.ʱ�临�Ӷ�ΪO(n2)  
  --ð������
  --ѡ������
  --��������
2.ʱ�临�Ӷ�ΪO(nlog(n))
  --ϣ������
  --������
  --��������
  --�鲢����
3.ʱ�临�Ӷ�ΪO(n))
  --��������
  --��������
  --Ͱ����
*/
void swap(int &a, int &b) {
	int tem = a;
	a = b;
	b = tem;
}

void print(vector<int> nums) {
	for (const int& num : nums) {
		std::cout << num << " ";
	}

	std::cout << std::endl;
}

/*
����ʱ�临�Ӷ�ΪO(n2)�����򷽷����������ò������������Ե�ʱ���п��ܻ�������һ��������Ҫ���Լ��ò���
*/

//ð������(�ȶ���
void bubbleSort(vector<int> &nums)
{
	int n = nums.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n-i-1; j++)
		{
			if (nums[j + 1] < nums[j])
				swap(nums[j + 1], nums[j]);
		}

}

/// <summary>
/// ѡ������(���ȶ�)
/// </summary>
void selectionSort(vector<int>& nums)
{
	int n = nums.size();
	int minIndex = 0;
	for (int i = 0; i < n - 1; i++) 
	{
		minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (nums[minIndex] > nums[j])
				minIndex = j;
		}
	// ����СԪ�ؽ�������λ
	int temp = nums[i];
	nums[i] = nums[minIndex];
	nums[minIndex] = temp;
	}

}

/// <summary>
/// ��������(�ȶ�)
/// </summary>
void insertSort(vector<int>& nums) {

	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j >= 1 && nums[j] < nums[j - 1]) {
			swap(nums[j], nums[j - 1]);
			j--;
		}	
	}
}

/// <summary>
/// ����������һ����Ҫ��;--��������
/// </summary>
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* insertionSortList(ListNode* head) {

	if (head == nullptr) {
		return head;
	}
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* lastSorted = head;
	ListNode* curr = head->next;
	while (curr != nullptr) {
		if (lastSorted->val <= curr->val) {
			lastSorted = lastSorted->next;
		}
		else {
			ListNode* prev = dummyHead;
			while (prev->next->val <= curr->val) {
				prev = prev->next;
			}
			lastSorted->next = curr->next;
			curr->next = prev->next;
			prev->next = curr;
		}
		curr = lastSorted->next;
	}
	return dummyHead->next;
}

/// <summary>
/// ϣ������
/// </summary>
void shellSort(vector<int>& nums)
{

}



int main() {
	vector<int>nums = { 1,6,2,3,5,4 };
	print(nums);
	//bubbleSort(nums);
	//selectionSort(nums);
	//insertSort(nums);
	print(nums);

}