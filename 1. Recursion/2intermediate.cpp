#include <bits/stdc++.h>
using namespace std;

template <class T>
void printVector(vector<T> vec)
{
    cout << "[ ";
    for (auto ele : vec)
    {
        cout << ele << " ";
    }
    cout << "]\n";
}

// Subsequence --> Non-Contiguous and ordered
// for string/array of length n, no. of subsequences possible = 2^n
// Example: arr [] = [1, 2, 3]
// Subsequences = [], [1], [2], [3], [1, 2], [1,3], [2, 3], [1, 2 , 3]

// Substring/Subarray --> Contiguous and ordered (and non-empty)
// for string/array of length n, no. of substring/subarray possible = n (n + 1) / 2
// Example: arr [] = [1, 2, 3]
// Subarrays = [1], [1, 2], [1, 2, 3], [2], [2, 3], [3]

// Example -> s = "abc"
// Expectation f(abc) -> [---, --c, -b-, -bc, a--, a-c, ab-, abc]
// Faith f(bc) -> [--, -c, b-, bc]

// 1.
vector<string> getSubSequence(string s)
{

    if (s.size() == 0)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }

    char c = s[0];
    string restOfString = s.substr(1);
    vector<string> restOfResult = getSubSequence(restOfString);

    vector<string> ans;

    for (auto str : restOfResult)
    {
        ans.push_back(c + str);
        ans.push_back("" + str);
    }
    return ans;
}

// Use Souce-Destination Diagram - One Expectation, multiple faiths, Use Recursion Tree for easier understanding

// 2. climbStairs -> How many ways to climbStairs from 0 to n (or n to 0), by taking either 1 or 2 steps
int climbStairs(int n)
{
    // base case
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    // recursive case
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// 3. get Stair Paths -> We can go to 1, 2 and 3 stair down at a moment, find all paths
vector<string> getStairPaths(int n)
{

    if (n == 0)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    if (n < 0)
    {
        vector<string> res;
        return res;
    }

    vector<string> paths1 = getStairPaths(n - 1);
    vector<string> paths2 = getStairPaths(n - 2);
    vector<string> paths3 = getStairPaths(n - 3);

    vector<string> paths;

    for (auto path : paths1)
        paths.push_back("1" + path);

    for (auto path : paths2)
        paths.push_back("2" + path);

    for (auto path : paths3)
        paths.push_back("3" + path);

    return paths;
}

// Think in terms of path-destination diagram
// 4. getMazePaths -> find all paths starting from (1, 1) to (n, m) using two steps -> either go horizontal (right) or vertical (down)
vector<string> getMazePaths(int x, int y, int n, int m)
{
    // Base case
    if (x == n && y == m)
    {
        vector<string> res{""};
        return res;
    }

    // Recursive case
    vector<string> hpaths;
    vector<string> vpaths;

    if (x < n)
        hpaths = getMazePaths(x + 1, y, n, m);

    if (y < m)
        vpaths = getMazePaths(x, y + 1, n, m);

    vector<string> totalPaths;

    for (auto hpath : hpaths)
        totalPaths.push_back("H" + hpath);

    for (auto vpath : vpaths)
        totalPaths.push_back("V" + vpath);

    return totalPaths;
}

// 5. getMazePathsWithJumps --> Steps possible: Horizontal (H1, H2, H3), Vertical (V1, V2, V3), Diagonal (D1, D2, D3)
// Go from (1, 1) -> (n, m)
vector<string> getMazePathsWithJumps(int srow, int scol, int drow, int dcol)
{

    if (srow == drow && scol == dcol)
    {
        vector<string> res{""};
        return res;
    }

    vector<string> paths;
    // horizontal moves
    for (int jump = 1; jump <= dcol - scol; jump++)
    {
        vector<string> hpaths = getMazePathsWithJumps(srow, scol + jump, drow, dcol);
        for (auto hpath : hpaths)
        {
            paths.push_back("H" + to_string(jump) + hpath);
        }
    }

    // vertical moves
    for (int jump = 1; jump <= drow - srow; jump++)
    {
        vector<string> vpaths = getMazePathsWithJumps(srow + jump, scol, drow, dcol);
        for (auto vpath : vpaths)
        {
            paths.push_back("V" + to_string(jump) + vpath);
        }
    }

    // diagonal moves
    for (int jump = 1; jump <= drow - srow && jump <= dcol - srow; jump++)
    {
        vector<string> dpaths = getMazePathsWithJumps(srow + jump, scol + jump, drow, dcol);
        for (auto dpath : dpaths)
        {
            paths.push_back("D" + to_string(jump) + dpath);
        }
    }

    return paths;
}

// Level and options -> Solve this question option wise
// 6. printSubSequence -> now instead of storing that strings in a vector we will try to print all the strings, that way we don't have to consume so much memory
// Pick/no pick
void printSubSequence(string s, string &ans)
{

    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    ans.push_back(s[0]);
    printSubSequence(s.substr(1), ans);
    ans.pop_back();
    printSubSequence(s.substr(1), ans);
}

vector<string> codes = {".,", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "xyz"};

// 7. printKeypadCombination
void printKeypadCombination(string s, string &ans)
{

    if (!s.size())
    {
        cout << ans << " ";
        return;
    }

    int num = s[0] - '0';
    string code = codes[num];

    for (auto c : code)
    {
        ans.push_back(c);
        printKeypadCombination(s.substr(1), ans);
        ans.pop_back();
    }
}

// 8. printStairPaths -> we can take 1,2 or 3 steps
void printStairPaths(int n, string &ans)
{
    if (n == 0)
    {
        cout << ans << " ";
        return;
    }

    for (int step = 1; step <= 3; step++)
    {
        if (step <= n)
        {
            ans.push_back(step + '0');
            printStairPaths(n - step, ans);
            ans.pop_back();
        }
    }
}

// 9. printMazePaths -> move possible = vertical (down) or horizontal (right)
void printMazePaths(int srow, int scol, int drow, int dcol, string &ans)
{
    if (srow == drow && scol == dcol)
    {
        cout << ans << endl;
        return;
    }

    if (srow < drow)
    {
        ans.push_back('V');
        printMazePaths(srow + 1, scol, drow, dcol, ans);
        ans.pop_back();
    }

    if (scol < dcol)
    {
        ans.push_back('H');
        printMazePaths(srow, scol + 1, drow, dcol, ans);
        ans.pop_back();
    }
}

// 10. printMazePathsWithJumps -> move possible = vertical, horizontal or diagonal, step size can be any
// *********      SOMETHING WRONG WITH CODE      *************
void printMazePathsWithJumps(int srow, int scol, int drow, int dcol, string &ans)
{
    if (srow == drow && scol == dcol)
    {
        cout << ans << endl;
        return;
    }

    // Vertical Steps
    for (int step = 1; step <= drow - srow; step++)
    {
        ans += ("V" + to_string(step));
        printMazePaths(srow + step, scol, drow, dcol, ans);
        ans.pop_back();
        ans.pop_back();
        cout << "ans =  " << ans;
    }

    // Horizontal Steps
    for (int step = 1; step <= dcol - scol; step++)
    {
        ans += "H" + to_string(step);
        printMazePaths(srow, scol + step, drow, dcol, ans);
        ans.pop_back();
        ans.pop_back();
        cout << "ans =  " << ans;
    }

    // Diagonal Steps
    for (int step = 1; (step <= drow - srow) && (step <= dcol - scol); step++)
    {
        ans += "D" + to_string(step);
        printMazePaths(srow + step, scol + step, drow, dcol, ans);
        ans.pop_back();
        ans.pop_back();
        cout << "ans =  " << ans;
    }
}

// 11. printPermutations -> a  different problem than the before problems
void printPermutations(string s, string &ans)
{
    if (s.size() == 0)
    {
        cout << ans << " ";
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        ans.push_back(c);
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string rest = left + right;
        printPermutations(rest, ans);
        ans.pop_back();
    }
}

// 12. print Encodings: 1 -> a, 2 -> b, 3 -> c, 4 -> d, ... , 10 -> j, 11 -> k, ... , 26 -> z
void printEncodings(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << " ";
        return;
    }

    if (s[0] == '0')
        return;

    if (s.size() == 1)
    {
        char c = s[0];
        int cValue = c - '0';
        ans += char(cValue + 'a' - 1);
        cout << ans << " ";
        return;
    }

    char c = s[0];
    int cValue = c - '0';
    ans += char(cValue + 'a' - 1);
    printEncodings(s.substr(1), ans);
    ans.pop_back();

    string ch12 = s.substr(0, 2);
    string restOfString = s.substr(2);

    int ch12Value = stoi(ch12);

    if (ch12Value <= 26)
    {
        ans += char(ch12Value + 'a' - 1);
        printEncodings(restOfString, ans);
    }
}

// 13. Target Sum Subset
void printTargetSumSubset(vector<int> nums, int idx, int target, vector<int> &ans)
{
    if (idx == nums.size())
    {
        if (target == 0)
            printVector(ans);
        return;
    }

    printTargetSumSubset(nums, idx + 1, target, ans);

    ans.push_back(nums[idx]);
    printTargetSumSubset(nums, idx + 1, target - nums[idx], ans);
    ans.pop_back();
}

int main()
{
    string s = "abc";
    string helper = "";
    string number = "123";
    vector<int> nums{10, 20, 30, 40, 50};
    vector<int> helperVector;

    // vector<string> res = getSubSequence(s);

    // printVector(res);

    // printSubSequence(s, helper);

    // printKeypadCombination("12", helper);

    // printStairPaths(5, helper);

    // printMazePaths(1, 1, 3, 3, helper);

    // printMazePathsWithJumps(1, 1, 2, 2, helper);

    // printPermutations(s, helper);

    // printEncodings(number, helper);

    // printTargetSumSubset(nums, 0, 80, helperVector);

    return 0;
}