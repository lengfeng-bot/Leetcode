#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;



/// 介绍几个单调栈的题目
/// 
/// 
/// 
/// <summary>
/// 1.股票价格跨度
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
/// 2.每日温度
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
/// 下一个更大元素1
/// </summary>
/// 单调栈加上哈希表
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
		map[st.top()] = -1; // 栈中剩余元素没有下一个更大元素
		st.pop();
	}
	for (int i = 0; i < nums1.size(); i++) {
		ans.push_back(map[nums1[i]]);
	}
	return ans;



}
/// <summary>
/// 下一个更大元素1
/// </summary>
/// 这个和上面的不同之处在于，变成循环数组了，而且不需要哈希映射，更简单了好像
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
/// 3.接雨水
/// </summary>
/// 这道题的关键是，既要找左边第一个比当前元素大的，又要找右边的，我觉得可以建立两个数组，分别表示当前元素下一个更大元素的位置。
/// 得到这两个数组之后，加上一点小小的判断，便可以轻易得到每个元素能接到水的量了。
/// 我上面的思路有些问题：我要找的不是第一个比当前大的元素，而是当前元素左边或者右边最大的元素才行。需要改进这个问题.
/// 果然，改进之后，拿下了！！！但是看了看官方题解，用到单调栈，还更简单了。我把官方解法列在下面
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
/// 最小栈
/// </summary>
class MinStack {
public:
	MinStack() {
	}

	// 压栈操作，同时更新最小值
	void push(int x) {
		dataStack.push(x);
		if (minStack.empty() || x <= minStack.top()) {
			minStack.push(x);
		}
	}

	// 弹栈操作，同时更新最小值
	void pop() {
		if (!dataStack.empty()) {
			if (dataStack.top() == minStack.top()) {
				minStack.pop();
			}
			dataStack.pop();
		}
	}

	// 获取栈顶元素
	int top() {
		return dataStack.top();
	}

	// 获取栈中最小元素
	int getMin() {
		return minStack.top();
	}

private:
	std::stack<int> dataStack; // 存储数据的栈
	std::stack<int> minStack;  // 存储最小值的栈
};

//int main() {
//	MinStack minStack;
//
//	minStack.push(-2);
//	minStack.push(0);
//	minStack.push(-3);
//
//	std::cout << "栈中最小元素是：" << minStack.getMin() << std::endl; // 输出 -3
//
//	minStack.pop();
//
//	std::cout << "栈中顶部元素是：" << minStack.top() << std::endl; // 输出 0
//	std::cout << "栈中最小元素是：" << minStack.getMin() << std::endl; // 输出 -2
//
//	return 0;
//}


/// <summary>
/// 队列中可以看到的人数
/// </summary>
vector<int> canSeePersonsCount(vector<int>& heights) {
	int n = heights.size();
	vector<int>ans(n, 0); return ans;

}