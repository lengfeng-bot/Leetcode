#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


/*
///排序算法通常按照时间复杂度进行分类
1.时间复杂度为O(n2)  
  --冒泡排序
  --选择排序
  --插入排序
2.时间复杂度为O(nlog(n))
  --希尔排序
  --堆排序
  --快速排序
  --归并排序
3.时间复杂度为O(n))
  --计数排序
  --基数排序
  --桶排序
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
对于时间复杂度为O(n2)的排序方法，基本上用不到，但是面试的时候有可能会让你敲一个，所以要会自己敲才行
*/

//冒泡排序(稳定）
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
/// 选择排序(不稳定)
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
	// 将最小元素交换至首位
	int temp = nums[i];
	nums[i] = nums[minIndex];
	nums[minIndex] = temp;
	}

}

/// <summary>
/// 插入排序(稳定)
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
/// 插入排序还有一个重要用途--操作链表！
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
/// 希尔排序
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