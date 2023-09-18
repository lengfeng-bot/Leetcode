#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;





///一维前缀和
/// 
/// 
/// 
/// 经典模板
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};



/// <summary>
/// 构建回文串检测
/// </summary>

vector<bool> canMakePaliQueries1(string s, vector<vector<int>>& queries) {
    unordered_map<char, int>map;
    int count = 0;
    int num = 0;
    vector<bool>ans ;
    for (int i = 0; i < 25; i++)
    {
        map['a' + i] = 0;
    }
    for (int i = 0; i < queries.size(); i++)
    {
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            map[s[j]]++;
            if (map[s[j]] % 2 != 0)
                count++;

        }
        num = queries[i][1] - queries[i][0]+1;
        if (num %2 ==0)
        {
            if (queries[i][2] >= count/2)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        else
        {
            if ( queries[i][2] >=(count-1)/2)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

    }
    return ans;


}
/// <summary>
/// 完美的解法，前缀和+位运算
/// </summary>
vector<bool> canMakePaliQueries2(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++) {
        count[i + 1] = count[i] ^ (1 << (s[i] - 'a'));
    }
    vector<bool> res;
    for (auto& query : queries) {
        int l = query[0], r = query[1], k = query[2];
        int bits = 0, x = count[r + 1] ^ count[l];
        while (x > 0) {
            x &= x - 1;
            bits++;
        }
        res.push_back(bits <= k * 2 + 1);
    }
    return res;
}



int main() {
    string s = "abcda";
    vector<vector<int>> queries = {{0,3,2},{0,4,1}};
    vector<bool> answer = canMakePaliQueries1(s, queries);
    std::cout << "检测结果：";
    for (bool result : answer) {
        std::cout << (result ? "true " : "false ");
    }

    return 0;
}