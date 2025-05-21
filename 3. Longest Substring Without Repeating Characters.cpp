class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Brute Force
        if(s.size() == 0) return 0;
        string ans;
        int max_len=0;
        for(int i=0 ; i<s.size() ; i++){
            ans.push_back(s[i]);
            max_len = max_len > 1 ? max_len : 1;
            for(int j=i+1 ; j<s.size() ; j++){
                if(ans.find(s[j]) == ans.npos){
                    ans.push_back(s[j]);
                    //printf("ANS %d %d : %s\n",i ,j , ans.c_str());
                }
                else{
                    max_len = max_len > ans.size() ? max_len : ans.size();
                    //printf("%s %d\n", ans.c_str(), max_len);
                    ans.clear();
                    break;
                }
                if(j == s.size()-1){
                    max_len = max_len > ans.size() ? max_len : ans.size();
                    //printf("%s %d\n", ans.c_str(), max_len);
                    ans.clear();
                    break;
                }
            }
        }
        return max_len;
        
        /*
        // Bidirection queue(deque)
        // This is slide window
        int max_len = 0;
        deque<char> sub_str = {};
        
        for (int i=0; i<s.size(); i++) {
            
            
            while (find(sub_str.begin(), sub_str.end(), s[i]) != sub_str.end()) {
                sub_str.pop_front();
            }
            
            // insert char into queue
            sub_str.push_back(s[i]); 
            if (sub_str.size() > max_len) {
                max_len = sub_str.size();
            }
        }
        
        return max_len;
        */
    }
};
