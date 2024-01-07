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
/// ��һ������Ԫ��1
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
/// <summary>
/// ��һ������Ԫ��1
/// </summary>
/// ���������Ĳ�֮ͬ�����ڣ����ѭ�������ˣ����Ҳ���Ҫ��ϣӳ�䣬�����˺���
/// 
vector<int> nextGreaterElements2(vector<int>& nums) {
	int n = nums.size();
	vector<int>ans(n,-1);
	
	stack<int>st;
	for (int i = 0; i < 2*n; i++)
	{
		int index = i % n;
		while (!st.empty()&&nums[index]>nums[st.top()])
		{
			ans[st.top()] = nums[index];
			st.pop();
		}
		st.push(index);
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
/// �����Ĺؼ��ǣ���Ҫ����ߵ�һ���ȵ�ǰԪ�ش�ģ���Ҫ���ұߵģ��Ҿ��ÿ��Խ����������飬�ֱ��ʾ��ǰԪ����һ������Ԫ�ص�λ�á�
/// �õ�����������֮�󣬼���һ��СС���жϣ���������׵õ�ÿ��Ԫ���ܽӵ�ˮ�����ˡ�
/// �������˼·��Щ���⣺��Ҫ�ҵĲ��ǵ�һ���ȵ�ǰ���Ԫ�أ����ǵ�ǰԪ����߻����ұ�����Ԫ�ز��С���Ҫ�Ľ��������.
/// ��Ȼ���Ľ�֮�������ˣ��������ǿ��˿��ٷ���⣬�õ�����ջ���������ˡ��Ұѹٷ��ⷨ��������
//int trap(vector<int>& height) {
//	int n = height.size();
//	vector<int>rmax(n, -1);
//	vector<int>lmax(n, -1);
//	stack<int>s;
//	
//
//	int maxRight = height[n - 1];
//	for (int i = n - 2; i >= 0; --i) {
//		if (height[i] < maxRight) {
//			rmax[i] = maxRight;
//		}
//		else {
//			maxRight = height[i];
//		}
//	}
//	int maxLeft = height[0];
//	for (int i = 1; i < n; ++i) {
//		if (height[i] < maxLeft) {
//			lmax[i] = maxLeft;
//		}
//		else {
//			maxLeft = height[i];
//		}
//	}
//
//	//for (int i = 0; i < n; i++)
//	//{	
//	//	while (!s.empty() && height[i] > height[s.top()]) {
//	//		rmax[s.top()] = height[i];
//	//		s.pop();
//	//	}
//	//	s.push(i);
//	//	
//	//}
//	//for (int i = n-1; i >=0; i--)
//	//{
//	//	while (!s.empty() && height[i] > height[s.top()]) {
//	//		lmax[s.top()] = height[i];
//	//		s.pop();
//	//	}
//	//	s.push(i);
//	//}
//
//	for(auto m:height)
//		cout << m << " ";
//	cout << endl;
//	for (auto m : rmax)
//		cout << m << " ";
//	cout << endl;
//	for (auto m : lmax)
//		cout << m << " ";
//
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (lmax[i] != -1 && rmax[i] != -1) {
//		sum += (min(lmax[i], rmax[i]) - height[i]);
//		}
//
//	}
//	return sum;
//}

int trap(vector<int>& height) {
	stack<int> st;
	st.push(0);
	int sum = 0;
	for (int i = 1; i < height.size(); i++) {
		while (!st.empty() && height[i] > height[st.top()]) {
			int mid = st.top();
			st.pop();
			if (!st.empty()) {
				int h = min(height[st.top()], height[i]) - height[mid];
				int w = i - st.top() - 1;
				sum += h * w;
			}
		}
		st.push(i);
	}
	return sum;
}



int main() {
	vector<int>nums = { 4,2,0,3,2,5 };
	int a = trap(nums);
	cout <<endl<< a;
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

//int main() {
//	MinStack minStack;
//
//	minStack.push(-2);
//	minStack.push(0);
//	minStack.push(-3);
//
//	std::cout << "ջ����СԪ���ǣ�" << minStack.getMin() << std::endl; // ��� -3
//
//	minStack.pop();
//
//	std::cout << "ջ�ж���Ԫ���ǣ�" << minStack.top() << std::endl; // ��� 0
//	std::cout << "ջ����СԪ���ǣ�" << minStack.getMin() << std::endl; // ��� -2
//
//	return 0;
//}


/// <summary>
/// �����п��Կ���������
/// </summary>
vector<int> canSeePersonsCount(vector<int>& heights) {
	int n = heights.size();
	vector<int>ans(n, 0); return ans;

}