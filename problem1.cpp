//https://leetcode.com/problems/generate-parentheses/submissions/869397376/
class Solution {
public:
    int dp[10][10];
    map<int, map<int, string > > mp;
    vector<string > ans;
    void runDp(int sum, int idx, int n, string ss) {
        if (idx == 2*n) {
            if(sum == 0) {
                ans.push_back(ss);
            }
            return;
        }
        if (sum>0) {
            runDp(sum-1,idx+1,n,ss+")");
        }
        runDp(sum+1, idx+1,n,ss+"(");
        return;
    }
    vector<string> generateParenthesis(int n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = -1;
            }
        }
        runDp(0,0,n,"");
        return ans;
    }
};
