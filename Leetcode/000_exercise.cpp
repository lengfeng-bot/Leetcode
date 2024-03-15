#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include<unordered_map>
#include<unordered_set>
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


/// <summary>
/// ���ù�ϣ��ͳ����ĸ���ֵĴ�����֮��Ӵ���ĸ��ʼ����oush��ans,ÿ����ĸ������push Limit��������
/// ����������ƣ�������һ����С����ĸ��ӣ�����������Ƶ������һλ��ĸ����ֱ�Ӳ������
/// </summary>
string repeatLimitedString(string s, int repeatLimit) {
	int cnt[26]{};
	for (char& c : s) {
		++cnt[c - 'a'];
	}
	string ans;
	for (int i = 25, j = 24; ~i; --i) {
		j = min(j, i - 1);
		while (1) {
			for (int k = min(cnt[i], repeatLimit); k; --k) {
				ans += 'a' + i;
				--cnt[i];
			}
			if (cnt[i] == 0) {
				break;
			}
			while (j >= 0 && cnt[j] == 0) {
				--j;
			}
			if (j < 0) {
				break;
			}
			ans += 'a' + j;
			--cnt[j];
		}
	}
	return ans;
}

void setZeroes1(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> row(m), col(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!matrix[i][j]) {
				row[i] = col[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}

}

void printmatrix(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


//int main() {
//	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
//	printmatrix(matrix);
//	cout << endl;
//	setZeroes1(matrix);
//	printmatrix(matrix);
//	return 0;
//}

/// <summary>
/// �ó����ٵ�ħ����
/// </summary>
/// ��һ������һ��̰�Ļ��߶�̬�滮����Ŀ�����ö�̬�滮��һ�¡�dp[i]�Ķ����ǰѵ�i��������׼����Ҫ�ó�ħ������������Ŀ
/// ʱ�临�Ӷ���O(n2) ��Ȼ��ʱ�ˣ���
/// �����ܷ�������������𣬼���ʱ�䡣
int minimumRemoval(vector<int>& beans) {
	int n = beans.size();
	vector<int>dp(n, 0);
	sort(beans.begin(), beans.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i] += (beans[i] <= beans[j]) ? (beans[j] - beans[i]) : beans[j];

	}
	int ans = INT_MAX;
	for (auto d : dp) {
		ans = min(ans, d);
		cout << d;cout << endl;
	}
		
	return ans;

}
/// <summary>
/// �ðɣ���һ���Ƚϼ򵥵�ǰ׺�����⣬˼·��dp���
/// </summary>
//int minimumRemoval2(vector<int>& beans) {
//	int n = beans.size();
//	sort(beans.begin(), beans.end());
//	long long total = accumulate(beans.begin(), beans.end(), 0LL); // ��������
//	long long res = total; // ������Ҫ�Ƴ��Ķ�����
//	for (int i = 0; i < n; i++) {
//		res = min(res, total - (long long)beans[i] * (n - i));
//	}
//	return res;
//}

//int main() {
//	vector<int>beans = {2,10,3,2 };
//	int ans = minimumRemoval(beans);
//	cout << ans;
//}





/// <summary>
/// ʹ�����С�ڵ��ڡ�������ʱ��
/// </summary>
int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
	int sum2 = 0;
	int nummax = 0;
	for (auto num : nums2) {
	sum2 += num;
	nummax = max(nummax, num);
	}
	if (sum2 - nummax > x)  return -1;
	return 0;
}



//int removeElement(vector<int>& nums, int val) {
//	int k = 0;
//	while (k < nums.size())
//	{
//		if (nums[k] == val) {
//			int x = nums[nums.size() - 1];
//			nums[k] = x;
//			nums.pop_back();
//		}
//		else k++;
//	}
//	return nums.size();
//}

vector<int> sortedSquares(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	int k = r;
	vector<int>ans;
	while (l <= r)
	{
		if (nums[l] * nums[l] >= nums[r] * nums[r]) {
			ans[k--] = nums[l] * nums[l];
			l++;
		}
		else {
			ans[k--] = nums[r] * nums[r];
			r--;
		}
	}
	return ans;
}



//int minSubArrayLen(int target, vector<int>& nums) {
//
//	int n = nums.size();
//	int i = j = 0;
//	int sum = 0;
//	while (i<n)
//	{
//		sum += nums[j];
//		if (sum < target) j++;
//	}
//
//}

/// <summary>
/// 
/// </summary>
/// һ����̬�滮����Ŀ
bool validPartition(vector<int>& nums) {
	return  1;
}


/// <summary>
/// ȱʧ�ĵ�һ������
/// </summary>
int firstMissingPositive(vector<int>& nums) {
	unordered_map<int, int>map;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			map[nums[i]]++;
		}
	}
	int m = 1;
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second > 0) m++;
		else return m;
	}
	return m;
}

//int main() {
//	vector<int>nums = { 3,4,-1,1 };
//	int ans = firstMissingPositive(nums);
//	cout << ans;
//	return 0;
//}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int>set(nums1.begin(),nums1.end());
	vector<int>ans;

	for (auto num : nums2) {
		if (set.count(num) > 0) {
			ans.push_back(num);
			set.erase(num);
		}
	}
	return ans;
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int,int>hashset;
	vector<int>ans;
	for (auto num : nums1) {
		hashset[num]++;
	}

	for (auto num : nums2) {
		if (hashset[num] > 0) {
			ans.push_back(num);
			hashset[num]--;
		}
	}
	return ans;
}

//int main() {
//	std::vector<int> nums1 = {1,2,2,2,1 };
//	std::vector<int> nums2 = { 1,2,2};
//
//	std::vector<int> result = intersection(nums1, nums2);
//
//	std::cout << "Intersection: ";
//	for (int num : result) {
//		std::cout << num << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/// <summary>
/// �ҳ��ַ����Ŀ���������
/// </summary>
vector<int> divisibilityArray(string word, int m) {
	vector<int>ans;
	string s = "";
	for (auto w : word) {
		s.push_back(w);
		int a = stoi(s);
		if (a % m == 0) ans.push_back(1);
		else  ans.push_back(0);
	}
	return ans;
}



/// <summary>
///  �ҳ������������С��
/// </summary>
/// ��������ֱ�ӱ����Ļ���ʱ�临�Ӷ�̫�ߣ��Ҳ�Ӧ���ö�̬�滮����ҵ�˼·��������
/// dp[i][j]���������е�i���͵�j��Ԫ�صĺ��Ƿ�Ϊtarget��
/// ��ʼ������Ϊ��������Ȼ��1��2��3��4.�������dp[i][j]==1�Ļ����ٽ�������һ����Ȼ�������Ϊ0��������ֱ��ѭ����֮���ȫΪ0�����ʱ�����Ǿ͵õ�����Ҫ�����顣
/// ֮��ͳ�����ǵõ���������֮�͡�
/// 
/// 436 / 575 ��ͨ���Ĳ�������......�����´𰸣�����û��ô���ӣ��õ��ǵȲ�������͹�ʽ��������ֱ����Ѫ����
int minimumPossibleSum1(int n, int target) {
	vector<vector<int>> dp(2*n, vector<int>(2*n, 0));
	vector<int>nums;
	vector<int>wrong;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}
	int num = n;
	for (int i = 0; i < num; i++)
		for (int j = i+1; j < num; j++)
		{
			if (nums[i] + nums[j] == target) {
				dp[i][j] = 1;  num += 1; nums.push_back(num); wrong.push_back(j);
			}
			else dp[i][j] = 0;
		}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	for (auto w : wrong) sum -= nums[w];

	return  sum;

}

int minimumPossibleSum(int n, int target) {
	const int mod = 1e9 + 7;
	int m = target / 2;
	if (n <= m) {
		return (long long)(1 + n) * n / 2 % mod;
	}
	return ((long long)(1 + m) * m / 2 +
		((long long)target + target + (n - m) - 1) * (n - m) / 2) % mod;
}
//int main() {
//	int ans = minimumPossibleSum(1, 1);
//	cout << ans;
//	return 0;
//}

/// <summary>
/// �ϲ��������е����Ԫ��
/// </summary>
/// �ҵ�˼·�������ģ��ҵ�����������һ�Ե�������(�������)����������Ȼ��ִ�в�����ֱ��������û�е�������������������ʱ�õ����ֵ��
/// ����˵3��5��9���Ȳ���3��5�������Ȳ���5��9�������һ���ģ����������
/// 5��7��9 ��ô�Ȳ���5��7 ���12��9���Ͳ����ˣ�����ֻ���Ȳ���7��9����֤������
/// ������������м���ʾ��ͨ��������long long ��ԭ�򡣡���
int maxArrayValue(vector<int>& nums) {

	for (int i = nums.size()-1; i >0; i--)
	{
		if (nums[i] >= nums[i - 1]) {
			nums[i - 1] += nums[i];
			int m = 0;
			while (i+m<nums.size()-1)
			{
				nums[i+m] = nums[i + m + 1];
				m++;
			}
			nums.pop_back();
		}
	}
	return nums[0];
}


//int main() {
//	vector<int>nums = { 5,3,3 };
//	int ans = maxArrayValue(nums);
//	cout << ans;
//	return 0;
//}



