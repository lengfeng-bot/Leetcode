#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

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

//int main() {
//    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
//    vector<vector<int>> merged = mergeIntervals(intervals);
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

    if (nums.size() == 1) return true;
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (ans >= i)
            ans = max(i + nums[i], ans);
        if (ans >= nums.size() - 1)
            return true;
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