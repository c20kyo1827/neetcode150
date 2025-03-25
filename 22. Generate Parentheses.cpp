class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::unordered_set<string>> dp(n);
        dp[0].insert("()");
        for(int i=1 ; i<n ; i++){
            for(auto& s : dp[i-1]){
                // dp[i].insert("("+s+")");
                // dp[i].insert("()"+s);
                // dp[i].insert(s+"()");
                std::string temp = s;
                for(int j=0 ; j<s.size() ; j++){
                    if(s[j] == '('){
                        temp.insert(temp.begin() + j + 1, '(');
                        temp.insert(temp.begin() + j + 2, ')');
                        dp[i].insert(temp);
                        temp = s;
                    }
                }
                dp[i].insert("()"+s);
            }
        }
        return std::vector<string>(dp[n-1].begin(), dp[n-1].end());
    }
};
