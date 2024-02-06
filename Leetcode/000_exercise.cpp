#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <stack>
#include <queue>

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


int addMinimum(string word) {
	int n = word.size(), cnt = 1;
	for (int i = 1; i < n; i++) {
		if (word[i] <= word[i - 1]) {
			cnt++;
		}
	}
	return cnt * 3 - n;
}



bool searchMatrix(vector<vector<int>>& matrix, int target) {


	int m = matrix.size();
	int n = matrix[0].size();
	int num =0;
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] > target)
		{
			num = max(i - 1, 0);
			break;
		}

	}
	cout << "�ڵ�" << num+1 << "�в�ѯ" << endl;

	for (int i = 0; i < n; i++)
	{
		if (matrix[num][i] == target)	return true;
	}

//���в�ѯ
	for (int i = 0; i < n; i++)
	{
		if (matrix[0][i] > target)
		{
			num = max(i - 1, 0);
			break;
		}

	}
	cout << "�ڵ�" << num+1 << "�в�ѯ" << endl;

	for (int i = 0; i < m; i++)
	{
		if (matrix[i][num] == target)	return true;
	}
	return false;
}

/// <summary>
/// �����������
/// </summary>
/// �����Ͻǿ�ʼ�����������С�����±������ܹؼ�
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int x = 0, y = n - 1;
	while (x < m && y >= 0) {
		if (matrix[x][y] == target) {
			return true;
		}
		if (matrix[x][y] > target) {
			--y;
		}
		else {
			++x;
		}
	}
	return false;
}

//int main() {
//	vector<vector<int>> matrix = { {1,3,5} };
//	bool ans = searchMatrix(matrix, 4);
//	cout << ans;
//	return 0;
//
//}


/// <summary>
/// ʯ����Ϸ1
/// </summary>
bool stoneGame(vector<int>& piles) {
	int sumAlice = 0;
	int sumBob = 0;
	int count = 0;
	while (!piles.empty())
	{
		int n = piles.size();
		
		if (piles[0] >= piles[n - 1]) {
			if (count % 2 == 0)
				sumAlice += piles[0];
			else
				sumBob += piles[0];
			
			piles.erase(piles.begin());
			count++;

		}
		else
		{
			if (count % 2 == 0)
				sumAlice += piles[n - 1];
			else
				sumBob += piles[n - 1];
			piles.pop_back();
			count++;
		}
		


	}
	cout << "sum1:" << sumAlice << endl;
	cout << "sum2:" << sumBob << endl;
	return sumAlice>sumBob;
}

//int main() {
//	vector<int>nums = { 1,5,233,7 };
//	bool ans = stoneGame(nums);
//	cout << ans;
//	return 0;
//}


int returnToBoundaryCount(vector<int>& nums) {
	int n = nums.size();
	int sum = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		sum += nums[i];
		if (sum == 0)
			num++;
	}
	return num;
}


int minimumTimeToInitialState(string word, int k) {
	int n = word.size();
	bool isconnect = false;
	int num = n / k;
	int yu = n % k;
	int ans1 = num;
	if (k == 1)
	{
		if(word[0]==word[n-1])
		isconnect = true;
	}
	if(yu!=0)
		if (word.substr(0, yu) == word.substr(n - yu, yu)) isconnect = true;
	cout << "isconnect:" << isconnect<<endl;
	if (isconnect) {
		for (int i = num; i > 0; i--)
		{
			if (k == 1) {
				if (word[0] == word[i]) {
					ans1--;
					cout << "����+1" << endl;
				}
				else
				{
					break;
				}
			}
			else {
				if (word.substr(0, k) == word.substr(k * i, k)) {
					ans1--;
					cout << "����+1" << endl;
				}
				else break;
			}
		}
		return max(ans1, 0);
	}
	else {
		if (yu == 0) return num;
		else return num + 1;
	}


}


//int main() {
//	string word = "aa";
//	int ans = minimumTimeToInitialState(word, 1);
//	cout << ans;
//	return 0;
//}

//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//	int m = matrix.size();
//	int n = matrix[0].size();
//	int x = 0; int y = n - 1;
//	while (x<m&&y>=0)
//	{
//		if (matrix[x][y] == target) return true;
//		else if (matrix[x][y] > target) y--;
//		else x++;
//	}
//	return false;
//}

/// <summary>
/// ħ����Ϸ
/// </summary>
/// �ҵ�˼·�ǣ�ÿ��sumС�ڵ���0��ʱ�򣬲���֮ǰ�������ĸ���������С�ĸ����ƶ���β������Ӧ������һ��̰�Ĳ���
/// �����Ļ����ҿ�����Ҫʹ��һ�������ݼ�ջ��ʵ��,
/// ���˰��죬����ջ����ʵ�֣���Ϊ�����ǻᵯ��֮ǰ��С��Ԫ�أ������������ݲ���������Ҫһ�����������ݽṹ��ʵ��������ܣ�
/// û���������ȶ��У�
int magicTower(vector<int>& nums) {

	int sum = 1;
	int  count = 0;
	int delay = 0;
	priority_queue<int, vector<int>, greater<int>> q;  //���ȶ���̫�����ˣ�
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (nums[i] < 0) {
			q.push(nums[i]);
		}
		if (sum<=0)
		{
			delay += q.top(); //�ȼ��� �����㿸��ס ����ٴ���
			sum -= q.top();
			q.pop();
			count++;
		}

	}
	sum += delay;

	return sum>0?count:-1;
}