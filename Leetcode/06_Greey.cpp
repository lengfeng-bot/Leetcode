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



//�ϲ�����