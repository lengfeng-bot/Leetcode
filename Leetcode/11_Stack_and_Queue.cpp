#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;



/// ���ܼ�������ջ����Ŀ
/// 
/// 
/// 
/// <summary>
/// 1.��Ʊ�۸���
/// </summary>
class StockSpanner {
public:
	StockSpanner() {
		this->stk.emplace(-1, INT_MAX);
		this->idx = -1;
	}

	int next(int price) {
		idx++;
		while (price >= stk.top().second)
		{
			stk.pop();
		}
		int m = idx - stk.top().first;
		stk.emplace(idx, price);

		return m;


	}

private:
	stack<pair<int, int>> stk;
	int idx;
};


//int main() {
//    StockSpanner spanner;
//    std::vector<int> prices = { 100, 80, 60, 70, 60, 75, 85 };
//
//    for (int price : prices) {
//        int span = spanner.next(price);
//        std::cout << span << " ";
//    }
//
//    return 0;
//}


/// <summary>
/// 2.ÿ���¶�
/// </summary>
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> res(n, 0);
	stack<pair<int, int>>stk;

	for (int i = 0; i < n; i++)
	{
		while (!stk.empty() && temperatures[i] > stk.top().second)
		{
			int t = stk.top().first;
			stk.pop();
			res[t] = i - t;
		}
		stk.emplace(i, temperatures[i]);
	}
	return res;
}




/// <summary>
/// ��һ������Ԫ��
/// </summary>
/// ����ջ���Ϲ�ϣ��
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int>ans;
	unordered_map<int, int>map;
	stack<int>st;
	for (int i = 0; i < nums2.size(); i++)
	{
		int num = nums2[i];
		while (!st.empty() && nums2[i] > st.top())
		{

			map[st.top()] = num;
			st.pop();
		}
		st.push(num);
	}

	while (!st.empty()) {
		map[st.top()] = -1; // ջ��ʣ��Ԫ��û����һ������Ԫ��
		st.pop();
	}
	for (int i = 0; i < nums1.size(); i++) {
		ans.push_back(map[nums1[i]]);
	}
	return ans;



}
  

//int main() {
//	vector<int>nums1 = { 4,1,2 };
//	vector<int>  nums2 = { 1,3,4,2 };
//	vector<int>
//		ans = nextGreaterElement(nums1, nums2);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << endl;
//	}
//
//
//}

/// <summary>
/// 3.����ˮ
/// </summary>
int trap(vector<int>& height) {
	return 0;
}






/// <summary>
/// ��Сջ
/// </summary>
class MinStack {
public:
	MinStack() {
	}

	// ѹջ������ͬʱ������Сֵ
	void push(int x) {
		dataStack.push(x);
		if (minStack.empty() || x <= minStack.top()) {
			minStack.push(x);
		}
	}

	// ��ջ������ͬʱ������Сֵ
	void pop() {
		if (!dataStack.empty()) {
			if (dataStack.top() == minStack.top()) {
				minStack.pop();
			}
			dataStack.pop();
		}
	}

	// ��ȡջ��Ԫ��
	int top() {
		return dataStack.top();
	}

	// ��ȡջ����СԪ��
	int getMin() {
		return minStack.top();
	}

private:
	std::stack<int> dataStack; // �洢���ݵ�ջ
	std::stack<int> minStack;  // �洢��Сֵ��ջ
};

int main() {
	MinStack minStack;

	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);

	std::cout << "ջ����СԪ���ǣ�" << minStack.getMin() << std::endl; // ��� -3

	minStack.pop();

	std::cout << "ջ�ж���Ԫ���ǣ�" << minStack.top() << std::endl; // ��� 0
	std::cout << "ջ����СԪ���ǣ�" << minStack.getMin() << std::endl; // ��� -2

	return 0;
}
