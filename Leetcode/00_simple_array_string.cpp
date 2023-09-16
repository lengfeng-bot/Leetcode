#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int t = 0;
    int len = nums.size();
    int sum = 0;
    for (int t = 0; t < len; t++)
    {
        sum += nums[t];
    }
    int sumLeft = 0;
    for (int i = 0; i < len; i++)
    {
        sum -= nums[i];

    if (sum == sumLeft)
    {
        return i;
    }
    sumLeft += nums[i];
    }
    return -1;
}

int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            right = mid+1;
        }
        else
        {
            left = mid+1;
        }
        return left;

    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{   
    int length = intervals.size();
    vector<vector<int>> result; 
    result.push_back(intervals[0]);
    int j = 0;
    for (int  i = j+1; i < length; i++)
    {
        
        if (result[j][1]>=intervals[i][0])
        {  
            result[i][1] = max(intervals[i][1], result[j][1]);                
        }
        else
        {
            result.push_back(intervals[i]);
            j++;
            
        }
    }
    return result;

}

void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int>a;
    vector<int>b;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0) 
                {
                    a.push_back(i);
                    b.push_back(j);
                }
            }
        //for (int  i = 0; i < b.size(); i++)
        //{
        //    cout << b[i] << " " ;

        //}
        //cout << endl;
        for (int q = 0; q < a.size(); q++)
            for (int i = 0; i < n; i++)
            {
                 matrix[a[q]][i] = 0;
            }
   

        for (int j = 0; j < b.size(); j++)
            for (int i = 0; i < m; i++)
            {
                matrix[i][b[j]] = 0;
            }
 
}

//int main(){

    //vector<int>nums;
    //nums.push_back(1);
    //nums.push_back(7);
    //nums.push_back(3);
    //nums.push_back(6);
    //nums.push_back(5);
    //nums.push_back(9);
    //std::sort(nums.begin(), nums.end());
    //for (int num : nums) {
    //    std::cout << num << " ";
    //}
    //std::cout << std::endl;

    //int tar = 4;
    //int result = searchInsert(nums, tar);
    //cout << result << endl;
   /* int result = pivotIndex(nums);
    if (result != -1) {
        cout << "支点索引是: " << result << endl;
    }
    else {
        cout <<result<<"没有支点索引" << endl;
    }*/

 //   return 0;

//}

void print(vector<vector<int>> matrix,int m,int n)
{
    for (int i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "  ";

        }
        cout << endl;

    }
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    vector<int>arr;
    int m = mat.size();
    int n = mat[0].size();
    int k, l = 0;

    for (int i = 0; i < m + n - 1; i++)
    {
        if (i % 2)
        {
            l = (i < n) ? i : n - 1;
            k = i - l;
            while (k < m  && l>=0)
            {
                arr.push_back(mat[k++][l--]);
            }

        }
        else
        {
            k = (i < m) ? i : m - 1;
            l = i - k;
            while (l < n  && k>=0)
            {
                arr.push_back(mat[k--][l++]);
            }

        }
    }

    return arr;
}

//int main(){
//
//    int m = 4;
//    int n = 4;
//    vector<vector<int>> matrix(m, vector<int>(n, 0));
//
//    for (int i = 0; i < m; i++)
//        for (size_t j = 0; j < n; j++)
//        {
//            matrix[i][j] = i+j;
//        }
//    //matrix[2][2] = 0;
//    //matrix[3][2] = 0;
//    //matrix[1][3] = 0;
//
//    print(matrix, m, n);
//    //setZeroes(matrix);
//    vector<int>dui = findDiagonalOrder(matrix);
//    cout << "--------------"<<endl;
//    for (int i = 0; i < dui.size(); i++)
//    {
//        cout << dui[i] << " ";
//    }
//    //print(matrix, m, n);
//    return 0; 
//}

/// <summary>
/// 最长公共前缀
/// </summary>

string same(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    int t = min(m, n);
    string samestr = "";
    int i = 0;
    while (i < t)
    {
        if (str1[i] == str2[i])
        {
            samestr += str1[i];
            i++;
        }
        else
            return samestr;
    }
    return samestr;
}

string longestCommonPrefix(vector<string>& strs)
{
    int len = strs.size();
    string common = strs[0];
    for (int i = 1; i < len; i++)
    {
        common = same(common, strs[i]);
        if (common.size() == 0)
        {
            return common;
        }
    }
    return  common;
    
}


//int main() {
//    vector<string>str;
//    str = { "lkslks","lkssl","lksm" };
//    string m = longestCommonPrefix(str);
//
//    cout << m << endl;
//}


/// <summary>
/// 最长回文字符串
/// </summary>

string longestPalindrome(string s) {

    int n = s.size();
    if (n <= 1)return s;
    string str1;
    int m = 0;
    int q = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                m = i;
                q = j;
                maxLen = j - i + 1;
                str1.push_back(s[i]);
                cout << "the value of m:" <<m<< endl;
                cout << "the value of n:" << q << endl;
                
            }
           
        }
    int i = 0;
    while (i<=q-m)
    {
    if (s[m++] ==s[q--])
        {
        //str1.push_back(s[m]);
        }
    }
    return str1;

}


//int main() {
//
//    string s = "abcba";
//    string str1;
//    str1 = longestPalindrome(s);
//    cout << str1 << endl;
//    return 0;
//
//
//
//}


/// <summary>
/// 翻转字符串的单词
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string reverseWords(string s) {
    int n = s.size();
    vector<string>sub(n);
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            sub[t].push_back(s[i]);
        }
        else
        {
            if(s[i+1]!= ' ')
            {
                t++;
            }
            
        }
    }
    s.clear();
    //for (int i = 0; i < n; i++)
    //{
    //    cout << sub[i] << endl;
    //}
    
    for (int i = n-1; i >=0; i--)
    {
        s.append(sub[i]);
        s.append(" ");
    }
    int headspace = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            headspace++;
        }
        else {
            break;
        }
    }
    int tailspace = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            tailspace++;
        }
        else {
            break;
        }
    }
    s = s.substr(headspace, s.size() - headspace - tailspace);
    return s;

}


//int main() {
//
//    string s = "  I  hello world";
//    string s1 = reverseWords(s);
//    cout << s1 << endl;
//
//    return  0;
//
//}

/// <双指针>
/// 反转字符串
/// </summary>
/// <param name="s"></param>
void reverseString(vector<char>& s) {

    int len = s.size();
    int m = 0;
    int n = len-1;
    while (m <=  n)
    {
        char temp;
        
        temp = s[m];
        s[m] = s[n];
        s[n] = temp;

        m++;
        n--;
        
    }



}

//int main() {
//
//
//    vector<char>s = {'a','b','c','d'};
//    reverseString(s);
//    for (int i = 0; i < s.size(); i++)
//    {
//        cout << s[i] <<" ";
//    }
//
//}


/// <summary>
/// 数组拆分
/// </summary>
/// <returns></returns>
int arrayPairSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int  i = 0; i < nums.size();)
    {
        sum += nums[i];
        i += 2;
    }
    return sum;

}

//int main() {
//
//    vector<int>nums = { 3,7,6,5,4,8 };
//    int result = arrayPairSum(nums);
//    cout << result << endl;
//    return 0;
//
//}


/// <summary>
/// 两数之和--双指针情况1
/// </summary>
/// <param name="numbers"></param>
/// <param name="target"></param>
/// <returns></returns>
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int>arr= { };

    int len = numbers.size();
    int m= 0;
    int n = len - 1;
    int sum = 0;
    while (numbers[m] + numbers[n] != target)
    {
        if (numbers[m] + numbers[n] >= target)
        {
            n--;
        }
        else
        {
            m++;
        }
    }
    arr.push_back(m + 1);
    arr.push_back(n + 1);
    return arr;

}

//int main() {
//    vector<int> numbers = { 1,2,4,5,7 };
//    vector<int> arr = twoSum(numbers, 8);
//    for (int i = 0; i < arr.size(); i++)
//    {
//        cout<<arr[i]<<endl;
//    }
//
//}


/// <summary>
/// 移除元素---快慢指针
/// </summary>
/// <param name="nums"></param>
/// <param name="val"></param>
/// <returns></returns>
int removeElement(vector<int>& nums, int val) {

    int slow = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val) {
            nums[slow] = nums[i];
            slow++;
        }


    }
    return slow;

}

//int main() {
//
//    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
//    int size = removeElement(nums,2);
//    for (int i = 0; i < nums.size(); i++)
//    {
//        cout << nums[i] << " ";
//    }
//
//    cout << endl;
//    cout << size << endl;
//
//
//}


/// <summary>
/// 寻找最大连续1
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int findMaxConsecutiveOnes(vector<int>& nums) {
    int q = 0;
    int slow = 0;
    vector<int>arr;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1) {
            slow++;
            q = max(slow, q);
        }
        else
            slow = 0;
    }
    return q;

}

//int main() {
//    vector<int>nums = { 1,1,0,1,1,1 };
//    int result = findMaxConsecutiveOnes(nums);
//    cout << result << endl;
//
//}


/// <summary>
/// 长度最小的子数组--滑动窗口
/// </summary>
/// <param name="target"></param>
/// <param name="nums"></param>
/// <returns></returns>
int minSubArrayLen(int target, vector<int>& nums) {

    int len = nums.size();
    int  n = 0;
    int sum = 0;
    int ans = len + 1;
    for (int i = 0; i < len; ++i)
    {
        sum += nums[i];
        if (sum>=target)
        {
            while (1)
            {
                if (sum - nums[n] >= target)
                    sum -= nums[n++];
                else break;
            }
            if (i-n+1<ans)
            {
                ans = i - n + 1;
            }
        }
    }
    if (ans < nums.size() + 1) return ans;               //返回判断是否有达到目标
    else return 0;


}

//int main() {
//    vector<int>nums = { 2, 3, 1, 2, 4, 3 };
//    int ans = minSubArrayLen(7,nums);
//    cout << ans << endl;
//
//
//    return 0;
//}



/// <summary>
/// 杨辉三角1
/// </summary>
/// <param name="numRows"></param>
/// <returns></returns>
vector<int> generate(int numRows) {
    vector<vector<int>>tri;
    if (numRows == 0) return tri[0];
    tri.push_back(vector<int>(1, 1));
    for (int i = 1; i < numRows; i++) 
    {
        vector<int>a(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i) a[j] = 1;
            else a[j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
        tri.push_back(a);
    }

    return tri[numRows];

}


//int main() 
//{
//    int n = 4;
//    vector<int>tri = generate(n);
//    for (int i = 0; i < tri.size(); i++)
//    {
//
//            cout << tri[i] << " ";
//    }
//}

/// <summary>
/// 杨辉三角2
/// </summary>
/// <param name="rowIndex"></param>
/// <returns></returns>
//vector<int> getRow(int rowIndex) {
//
//}