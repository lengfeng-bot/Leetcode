#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//可以使用「贪心算法」的问题需要满足的条件
//最优子结构：规模较大的问题的解由规模较小的子问题的解组成，区别于「动态规划」,可以使用「贪心算法」的问题「规模较大的问题的解」只由其中一个「规模较小的子问题的解」决定
//无后效性：后面阶段的求解不会修改前面阶段已经计算好的结果
//贪心选择性质：从局部最优解可以得到全局最优解。
//总结:贪心无套路！




//从最经典的贪心例题来！
//分发饼干
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
/// 柠檬水找零
/// </summary>
/// 这尼玛，不就是把所有情况列出来吗。。。
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


//区域选择问题
//有一类使用「贪心算法」解决的问题称为「活动选择问题」，解决这一类问题的直觉是「优先选择活动最早的活动」。

/// <summary>
/// 无重叠区间
/// </summary>
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    // 按结束时间升序排序
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 0; // 记录需要移除的区间数量
    int end = intervals[0][1]; // 当前所选区间的结束时间

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < end) {
            // 当前区间与前一个区间重叠，需要移除一个区间
            ++count;
        }
        else {
            // 当前区间与前一个区间不重叠，更新结束时间
            end = intervals[i][1];
        }
    }

    return count;
}



//用最少数量的箭引爆气球



//合并区间