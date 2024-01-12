#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;

//����ʹ�á�̰���㷨����������Ҫ���������
//�����ӽṹ����ģ�ϴ������Ľ��ɹ�ģ��С��������Ľ���ɣ������ڡ���̬�滮��,����ʹ�á�̰���㷨�������⡸��ģ�ϴ������Ľ⡹ֻ������һ������ģ��С��������Ľ⡹����
//�޺�Ч�ԣ�����׶ε���ⲻ���޸�ǰ��׶��Ѿ�����õĽ��
//̰��ѡ�����ʣ��Ӿֲ����Ž���Եõ�ȫ�����Ž⡣
//�ܽ�:̰������·��




//������̰����������
//�ַ�����
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int i = 0;
	int j = 0;
	int num = 0;
	while (i < g.size() && j < s.size())
	{
		if (s[j] >= g[i])
		{
			i++;
			j++;
			num++;
		}
		else
			j++;
	}
	return num;
}


/// <summary>
/// ������Ҳ��
/// </summary>
int findContentChildren2(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end()); 
    int count = 0;
    int i = g.size() - 1;
    int j = s.size()-1;
    while (i>=0&&j>=0)
    {
        if (g[i] > s[j]) i--;
        else
        {
            count++;
            i--;
            j--;
        }
    }
    return count;
}


//int main() {
//    // ʾ������
//    vector<int> g = { 1, 2, 3 };
//    vector<int> s = { 1, 1 };
//
//    // ���ú�����������
//    int result = wtf(g, s);
//    cout << "�������������С��������: " << result << endl;
//
//    return 0;
//}


/// <summary>
/// �ڶ�����
/// </summary>
/// ֱ���Ȱ������������Ĳ�ֵ��������������������ͬ�����ӣ��ȳ��ַ��Ų�ͬ��ʱ���ټ�
/// �����Ŀ����Ҫ����Ҫע����ڵ�������ֺü����������
int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();  // ���鳤��С��2��ֱ�ӷ������鳤��
    }

    int result = 1;  // ��ڶ����еĳ�ʼ����Ϊ1
    int prevDiff = 0;  // ǰһ��Ԫ���뵱ǰԪ�صĲ�ֵ

    for (int i = 1; i < nums.size(); ++i) {
        int currDiff = nums[i] - nums[i - 1];
        // �����ǰ��ֵ��ǰһ����ֵ��ͬ�ţ���ʾ�ڶ�����
        if ((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)) {
            result++;  // ���Ӱڶ����еĳ���
            prevDiff = currDiff;  // ����ǰһ����ֵ
        }
    }

    return result;
}

//int main() {
//    vector<int> nums1 = { 1, 7, 4, 9, 2, 5 };
//    vector<int> nums2 = { 1, 4, 7, 2, 5 };
//    vector<int> nums3 = { 1, 7, 4, 5, 5 };
//
//    cout << "��ڶ����еĳ��ȣ�" << wiggleMaxLength(nums1) << endl;  // �����6
//    cout << "��ڶ����еĳ��ȣ�" << wiggleMaxLength(nums2) << endl;  // �����4
//    cout << "��ڶ����еĳ��ȣ�" << wiggleMaxLength(nums3) << endl;  // �����4
//
//    return 0;
//}



/// <summary>
/// ����������
/// </summary>
/// ����е����밡��˼·�����ۼӺ�Ϊ������ʱ��ֱ������������һ�������¼��㡣�����Ϳ���һֱȡ���ֲ�����
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int result = INT32_MIN;
    for (int i = 0; i < n; i++)
    {  
        sum += nums[i];
        if (sum > result) { // ȡ�����ۼƵ����ֵ���൱�ڲ���ȷ�����������ֹλ�ã�
            //result = count;
        }
        if (sum <= 0) sum = 0; // �൱���������������ʼλ�ã���Ϊ��������һ���������ܺ�
    }
    return result;
}

/// <summary>
/// ����ˮ����
/// </summary>
/// �����꣬�����ǰ���������г����𡣡���
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (auto& bill : bills) {
        if (bill == 5) {
            five++;
        }
        else if (bill == 10) {
            if (five == 0) {
                return false;
            }
            five--;
            ten++;
        }
        else {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            }
            else if (five >= 3) {
                five -= 3;
            }
            else {
                return false;
            }
        }
    }
    return true;
}


//����ѡ������
//��һ��ʹ�á�̰���㷨������������Ϊ���ѡ�����⡹�������һ�������ֱ���ǡ�����ѡ������Ļ����
//�Ҿ��������·�����������ڼ����ʼλ�ã�֮��һ��forѭ��������⣡

/// <summary>
/// ���ص�����
/// </summary>
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    // ������ʱ����������
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 0; // ��¼��Ҫ�Ƴ�����������
    int end = intervals[0][1]; // ��ǰ��ѡ����Ľ���ʱ��

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) {
            // ��ǰ������ǰһ�������ص�����Ҫ�Ƴ�һ������
            ++count;
        }
        else {
            // ��ǰ������ǰһ�����䲻�ص������½���ʱ��
            end = intervals[i][1];
        }
    }

    return count;
}

/// <summary>
/// ��������ǰ��ս���λ�ôӴ�С����ģ���дһ��������ʼλ�ôӴ�С�Ĵ���
/// </summary>
int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    // ������ʱ����������
    sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
        });
    int count = 0; // ��¼��Ҫ�Ƴ�����������
    int end = intervals[0][1]; // ��ǰ��ѡ����Ľ���ʱ��

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) {
            // ��ǰ������ǰһ�������ص�����Ҫ�Ƴ�һ������
            count++;
            //ѡȡ��С�Ľ���ʱ��
            end = min(end, intervals[i][1]);
        }
        else {
            // ��ǰ������ǰһ�����䲻�ص������½���ʱ��
            end = intervals[i][1];
        }
    }

    return count;
}



//�����������ļ���������
//ÿһ֧�������λ�ö���ĳ��������ұ߽磬�������ŵ��䷨��֮���ж��䵽��С���ұ߽�ʱ������ұ߽���ұ��Ƿ񻹴���û�б��䵽������
// ����У���Ҫ��һ����������֮ǰ�Ĳ�����
//��̫�����˰ɣ�����~
int findMinArrowShots(vector<vector<int>>& points) {

    if (points.empty()) {
        return 0;
    }

    // ��������Ľ���λ�ý�������
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
        });

    int arrows = 1;
    int endPos = points[0][1];

    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > endPos) {
            // ��Ҫһ֧�¼���������һ������
            arrows++;
            endPos = points[i][1];
        }
    }

    return arrows;
}

///�ڶ��������ò�����д�����ˣ���Ȼ˵�ҳ�ʱ�������һ��ѭ��������������û��
//��ʱ�ٵĴ𰸼�209��
int findMinArrowShots2(vector<vector<int>>& points) {

    sort(points.begin(), points.end(), [](vector<int>a, vector<int>b) {if (a[0] == b[0])return a[1] < b[1]; return a[0] < b[0]; });
    int n = points.size();
    int start = points[0][0];
    int end = points[0][1];
    int count = 1;
    for (int i = 1; i < n; i++)
    {

        if (points[i][0] <= end) {
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
        }

        else
        {
            count++;
            start = points[i][0];
            end = points[i][1];
        }

    }
    return count;

}



/// <summary>
/// ������ĸ����
/// </summary>
/// �ҵ��뷨�������ġ�����һ�����ϻ��߹�ϣ���ҳ�ÿ����ĸ���ֵ���ʼλ�ã�Ȼ����ڲ�ͬ��ĸ��ͬ��������л���
/// ��������С�����������ϲ�
/// �н���������ϲ�
/// ������õľ���û�н���������Ƿָ�Ĵ�����Ϊ�˱�֤�����ܻ����������䣬ÿ��������ʼ����ȣ�������ͬ���䡣
/// 
/// ����˼·̫�����ˣ������ٷ����˼·̫�����ˣ������д��룬��ϣ��ͳ��ÿ���ַ����ֵ����λ�á�
/// Ȼ����һ��������жϣ���������!
vector<int> partitionLabels(string s) {
    vector<int>ans;
    int hash[27] = { 0 }; // iΪ�ַ���hash[i]Ϊ�ַ����ֵ����λ��
    for (int i = 0; i < s.size(); i++) { // ͳ��ÿһ���ַ������ֵ�λ��
        hash[s[i] - 'a'] = i;
    }
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        right = max(right, hash[s[i] - 'a']);
        if (right = i) {
            ans.push_back(right - left + 1);
            left = i + 1;
        }

    }
    return ans;
}


//�ϲ�����
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {


    sort(intervals.begin(), intervals.end());
    vector<vector<int>>result;
    result.push_back(intervals[0]);
    int j = 0;
    for (int i = j + 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= result[j][1])
            result[j][1] = max(result[j][1], intervals[i][1]);
        else
        {
            result.push_back(intervals[i]);
            j++;
        }

    }
    return result;

}

/// <summary>
/// �ڶ����Լ����ģ��൱��һ��������ģ��
/// </summary>
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);
    int right = intervals[0][1];
    int j = 0;
    for (int i =1 ; i < intervals.size(); i++)
    {
        if (intervals[i][0] > right) { ans.push_back(intervals[i]); right = intervals[i][1];  j++; }
        else { right = max(right, intervals[i][1]); ans[j][1] = right; }

    }
    return ans;
}
//int main() {
//    vector<vector<int>> intervals = { {2,3},{1,3},{5,7},{4,6} };
//    vector<vector<int>> merged = merge2(intervals);
//
//    cout << "�ϲ�������䣺" << endl;
//    for (const vector<int>& interval : merged) {
//        cout << "[" << interval[0] << ", " << interval[1] << "] ";
//    }
//    cout << endl;
//
//    return 0;
//}



/// <summary>
/// ��Ծ��Ϸ
/// </summary>
bool canJump(vector<int>& nums) {

    int cover = 0;
    if (nums.size() == 1) return true; // ֻ��һ��Ԫ�أ������ܴﵽ
    for (int i = 0; i <= cover; i++) { // ע��������С�ڵ���cover
        cover = max(i + nums[i], cover);
        if (cover >= nums.size() - 1) return true; // ˵�����Ը��ǵ��յ���
    }
    return false;


}

/// <summary>
/// ��Ծ��Ϸ2
/// </summary>
int jump(vector<int>& nums) {
    int ans = 0;
    int start = 0;
    int end = 1;
    while (end <nums.size())
    {
        int maxlen = 0;
        for (int  i = start; i < end; i++)
        {
            maxlen = max(maxlen, i + nums[i]);

        }
            start = end;
            end = maxlen + 1;
            ans++;
    }
    return ans;
}





//int main() {
//    vector<int> nums = { 3,2,1,0,4 };
//    bool result = canJump(nums);
//
//    if (result) {
//        cout << "���Ե������һ��λ��" << endl;
//    }
//    else {
//        cout << "�޷��������һ��λ��" << endl;
//    }
//
//    return 0;
//}


/// <summary>
/// �����
/// </summary>
/// ���ˣ�ͳ����������ż���ĸ�������С
int minCostToMoveChips(vector<int>& position) {
    int even = 0, odd = 0;
    for (int pos : position) {
        if (pos % 2) {
            odd++;
        }
        else {
            even++;
        }
    }
    return min(odd, even);
}


/// <summary>
/// ��С�ָ��
/// </summary>
/// ��ֻ֪��num1��num2������һ��������Ӧ�÷�����һ���ؼ�:num1,num2�е����ֶ��ǵ��������ģ����κ�һ�����֣������ܴ����κ�һ�����б���λ����С������
/// �����Ļ�ֱ������Ȼ����������ּ���
int splitNum(int num) {
    string stnum = to_string(num);
    sort(stnum.begin(), stnum.end());
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < stnum.size(); i++) {
        if (i % 2 == 0)
            num1 = num1 * 10 + (stnum[i] - '0');
        else
            num2 = num2 * 10 + (stnum[i] - '0');
    }
    return num1 + num2;
}


/// <summary>
/// ����վ
/// </summary>
/// �ؼ���������һ����ǰ�ͺ��ۼӺͣ��������飬����ǰ��С��0����˵������㲻������Ϊ��㣬ֱ����һ����
/// ����һȦҪ��֤ÿ������ʣ������Ҫ���ڵ���0
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int curcost = 0;
    int sumcost = 0;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
            curcost += gas[i]-cost[i];
            sumcost += gas[i]-cost[i];
            if (curcost < 0)
            {
                a = (i + 1) % n;
                curcost = 0;
            }
   }
    if (sumcost >= 0) return a;
    else return -1;
}

/// <summary>
/// �ַ��ǹ�
/// </summary>
/// ���ã�������������Ҳ������Ҿ�������һ�£�û�뵽һ�������ˣ�
/// �ؼ�����Ҫ�������ߣ������Һʹ��ҵ���
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int>ans(n, 1);
    for (int i = 0; i < n-1; i++)
    {
        if (ratings[i + 1] > ratings[i]) ans[i + 1] = ans[i] + 1;
        else if (ratings[i + 1] < ratings[i]) 
            if(ans[i]==ans[i+1])ans[i]++;
    }

    for (int i = n - 1; i > 0; i--)
    {
       if (ratings[i - 1] > ratings[i]) ans[i - 1] = max(ans[i - 1], ans[i] + 1);
       else if (ratings[i - 1] < ratings[i]) 
            if (ans[i] == ans[i - 1])  ans[i]++;
            
     }

    int sum = 0;
    for (auto a : ans) sum += a;

    return sum;
}


/// <summary>
/// ��������ؽ�����
/// </summary>
vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
    vector<vector<int>>ans(people.size(), std::vector<int>(2, -1));
    sort(people.begin(), people.end(), [](vector<int>a, vector<int>b) {return a[0] < b[0]; });
    unordered_set<int> seenNumbers;
    int n = people.size();
    for (int i = 0; i < n; i++)
    {
        int num = people[i][1];
        if (seenNumbers.count(num) > 0) {
            ans[num] = people[i];
            int j = i;
            while (j>=0) {        
                ans[j + 1] = ans[j];
                j--;
            }
        }
        else {
            seenNumbers.insert(people[i][1]);
            ans[num] = people[i];
        }
    }
    return ans;
}

/// <summary>
/// ������ȷ�𰸣�����ô��д�������أ���
/// </summary>
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> que;
    for (int i = 0; i < people.size(); i++) {
        int position = people[i][1];
        que.insert(que.begin() + position, people[i]);
    }
    return que;
}

//int main() {
//    vector<vector<int>> people = { {2,3},{1,5},{6,7} };
//    vector<vector<int>>a = reconstructQueue(people);
//    return 0;
//}

/// <summary>
/// ��������������
/// </summary>
/// �ҵ�˼·�ǣ����Ƚ����жϣ���������ֵ��������ڵ��ڣ������ر�������Ӳ����������ֿ�ʼ��ǰ�治�䣬��ǰ����һ�����油9
/// 487 -> 479 �����������λ���䣬ֻ��ʮλ
/// ʵ��������ķ����ܽ�� 296/308��ʾ����û���������668841
/// Ӧ�ôӺ���ǰ���������Ҳ�Ҫbreak
int monotoneIncreasingDigits(int n) {
    string s = to_string(n);
    int fig = s.size();
    bool isincrease = true;
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i - 1] > s[i]) {
            fig = i;
            s[i - 1]--;
        }
    }

    for (int i = fig; i < s.size(); i++)
    {
        s[i] = '9';
    }
    return stoi(s);

}