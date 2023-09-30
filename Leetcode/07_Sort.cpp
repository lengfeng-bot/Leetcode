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
	for (int gap = nums.size() / 2; gap > 0; gap /= 2) // ��������������Ԫ��
	{

		for (int i = 0; i < gap; ++i) // �ڲ�ѭ������ÿ�����飬gap���ڷ�����
		{

			// ��ÿ���������ν��в�������
			for (int j = i + gap; j < nums.size(); j += gap) // ����ÿ���һ��Ԫ������Ȼ�������������
			{
				for (int k = i; k < j; k += gap) // ����߿�ʼ���α����������飬�ҵ����ʵ�λ�ã�Ȼ���λ������Ԫ����������һλ��������Ԫ�ز����λ��
				{
					// ע���ӵ�j������Ԫ�ؿ�ʼ����˵��ǰ����j-1���������飬��j�Ǳ�������������ֹ����
					if (nums[k] > nums[j]) // ������Ԫ�ش�����������ߵ�һ����ʼѰ�ң��ҵ���һ�����ڴ���Ԫ�ص�������ΪҪ�����λ�ã����û�ҵ�����˵�����ñ�
					{
						int tmp = nums[j];
						for (int p = j; p > k; p -= gap) // �ҵ���kԪ��ΪҪ�����λ�ã�k+gap�������Ԫ������������һλ��ֱ��jλ�ý�ֹ
						{
							nums[p] = nums[p - gap]; // ע�⣺����Ҫȷ�����������Ϊ������
						}
						nums[k] = tmp; // ��������Ԫ�ز����kλ�ã����һ������Ԫ������
						break; // ���������������飬������һ������Ԫ������
					}

				}
			}
		}
	}


}

/// <summary>
/// ������
/// </summary>

/// ������
void heapify(vector<int>&nums, int n, int i) {
	int largest = i;         //��˽ڵ�Ϊ���ڵ�
	int lson = i * 2 + 1;    //�ҵ����������±�
	int rson = i * 2 + 2;	//�ҵ��Һ����±�
	if (lson<n && nums[lson]>nums[largest])
	{
		largest = lson;
	}	
	if (rson<n && nums[rson]>nums[largest])
	{
		largest = rson;
	}
	if (largest != i) {
		swap(nums[largest], nums[i]);
		heapify(nums,n,largest);
	}


}




void heapSort(vector<int>&nums) {

	//����һ���󶥶�
	int n = nums.size();
	int lastNode = n - 1; //���鳤��Ϊn
	int parent = (lastNode - 1) / 2;

	for (int i = parent; i >= 0; i--) {
		heapify(nums,n,i);
	}  //�������Ѿ���Ϊ��һ���󶥶�

		//����
	for (int i = n - 1; i >= 0; i--) {
		swap(nums[i], nums[0]);  //���һ��Ԫ�غ͵�һ��Ԫ�أ��󶥶ѣ�������
		heapify(nums, i, 0);  //������֮��Ҫά���󶥶�����
	}



}


//��������
void quickSort(vector<int>& nums) {

}



void mergeSort(vector<int>& nums) {

}


int main() {
	vector<int>nums = { 1,6,2,3,5,4 };
	print(nums);
	//bubbleSort(nums);
	//selectionSort(nums);
	//insertSort(nums);
	//shellSort(nums);
	//heapSort(nums);
	print(nums);

}