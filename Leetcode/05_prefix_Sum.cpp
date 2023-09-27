#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;





///һάǰ׺��
/// 
/// 
/// 
/// ����ģ��
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
/// �������Ĵ����
/// </summary>



/// �Լ������Ľⷨ�������ˣ�����
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
/// �����Ľⷨ��ǰ׺��+λ���� ,�����������벻����
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



//int main() {
//    string s = "abcda";
//    vector<vector<int>> queries = {{0,3,2},{0,4,1}};
//    vector<bool> answer = canMakePaliQueries1(s, queries);
//    std::cout << "�������";
//    for (bool result : answer) {
//        std::cout << (result ? "true " : "false ");
//    }
//
//    return 0;
//}


/// <summary>
/// ��������������ĳ˻�
/// </summary>
/// �ȱ��������ֳ�ʱ�ˣ�֮����취ʹ��O(n)ʱ����⣬Ҳ����˵������ans��numsֻ��ʹ��һ��forѭ�������������˼·������ǰ׺�˻���⡣
/// ͬʱҪ����ռ临�Ӷ�O(1),��ͨ���ı��������ans������⣡
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // �������˻����洢��result��
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] *= leftProduct;
        leftProduct *= nums[i];
    }

    // �����Ҳ�˻�������result�ж�Ӧλ�õ�ֵ
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
}


//int main() {
//    vector<int> nums = { 1, 2, 3, 4 };
//    vector<int> result = productExceptSelf(nums);
//
//    cout << "��������������ĳ˻���";
//    for (int num : result) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


/// <summary>
/// ����ȡ�����Ժ�
/// </summary>
/// ֱ�ӱ����⣬��������O(n2)��ʱ�ˣ�ʱ�临�Ӷ�ֻ��ΪO(n),˼·ת�����������ÿһ�ԵĽ������ӣ�����ֱ�����ĳ����������˶��ٴΣ����֮�������,,�����벻�����ˡ���
int sumOfFlooredPairs(vector<int>& nums) {
    vector<long long> arr(200010, 0);
    vector<long long> sum(200010, 0);
    int maxV = 0;
    long long ret = 0;
    for (auto it : nums) {
        maxV = max(maxV, it);
        arr[it]++;
    }
    for (int i = 1; i <= maxV * 2; ++i) {
        sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = 1; i <= maxV; ++i) {
        if (arr[i] > 0) {
            for (long long j = 1; j * i <= maxV; ++j) {
                // �����ǲ��������ǣ�����i�ĳ��ִ��� ���� ��������j ���� �������г���i������������j�����ֵ�������
                ret = (ret + (sum[(j + 1) * i - 1] - sum[j * i - 1]) * j * arr[i]) % 1000000007;
            }
        }

    }
    return ret;
}


//int main() {
//    vector<int> nums = {7,7,7,7,7,7,7 };
//    int result = sumOfFlooredPairs(nums);
//
//    cout << "�����Ժ͵���ȡ������" << result << endl;
//
//    return 0;
//}


/// <summary>
/// ��άǰ׺��
/// </summary>
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

    }
};