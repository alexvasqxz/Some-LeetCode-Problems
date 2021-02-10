class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1);
        dp[0] = true;
        
        for (int i = 0; i < size; i++){
            if (!dp[i]){ continue; }
            for (int j = 0; j < wordDict.size(); j++){
                int k = i + wordDict[j].size();
                if (k <= size && s.substr(i, k - i) == wordDict[j]){
                    dp[k] = true;
                }
            }
        }
        
        return dp[size];
    }
};
