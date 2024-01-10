#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> findPeaks(vector<int>& mountain) {
	vector<int>ans;
	int n = mountain.size();
	for (int i = 1; i < n-1; i++)
	{
		if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
			ans.push_back(i);
	}
	return ans;
}

/// <summary>
/// ����Ϊ���ǵ�dp��Ŀ��û�뵽�Ǹ�̰����Ŀ
/// </summary>
/// �������ɣ�����
int minimumAddedCoins(vector<int>& coins, int target) {
	int n = coins.size();
	vector<bool>dp(target + 1, 0);
	int count = 0;
	dp[0] = 1;
	int m = 0;
	for (int i = coins.size(); i >=0; i--) {
		for (int j = target; j >= coins[i]; j--)
		{
			dp[j] = dp[j - coins[i]];
		}

		for (int k = target; k >= 0; k--)
		{
			if (dp[k] == 0) {
			m = k;
			break;
		    }
		}
		if (dp[m] == 0) {
			coins.push_back(m);
			sort(coins.begin(), coins.end());
		}
		
	}
	return coins.size()-n;
}


//int main() {
//	vector<int> nums = { 1,4,10 };
//	int ans = minimumAddedCoins(nums,19);
//	cout << ans;
//}

int minLength(string s) {
	int n = s.size();
	int i = 0;

	while (i < n - 1) {
		if (s[i] == 'A' && s[i + 1] == 'B') {
			// Erase 2 characters starting from index i
			s.erase(i, 2);
			n = s.size();  // Update the size after erasing
			i = std::max(0, i - 1);  // Decrement i, but not below 0
		}
		else if (s[i] == 'C' && s[i + 1] == 'D') {
			// Erase 2 characters starting from index i
			s.erase(i, 2);
			n = s.size();  // Update the size after erasing
			i = std::max(0, i - 1);  // Decrement i, but not below 0
		}
		else {
			i++;
		}
	}

	return s.size();
}

///ģ��һ��ջ�ƺ������㣬һ�����������Ŀ��Ҫ����ƥ����ĸ�������ŵĻ����󲿷ֶ�������ջ���
int minLength2(string s) {
	string stack;

	// �����ַ���
	for (char ch : s) {
		// ��ջ��Ϊ�գ��ҵ�ǰ�ַ���ջ���ַ���� "AB" �� "CD" �Ӵ�ʱ������ջ���ַ�
		if (!stack.empty() && (stack.back() == 'A' && ch == 'B' || stack.back() == 'C' && ch == 'D')) {
			stack.pop_back();
		}
		else {
			// ���򣬽���ǰ�ַ�ѹ��ջ
			stack.push_back(ch);
		}
	}

	// ջ��ʣ���ַ���������Ϊ�����ַ�������С���ܳ���
	return stack.size();
}