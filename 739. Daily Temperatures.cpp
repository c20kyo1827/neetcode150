class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> ans(temperatures.size(), 0);
        std::stack<std::pair<int, int>> sMaxAndIdx;
        for(int i=0 ; i<temperatures.size() ; i++){
            while(!sMaxAndIdx.empty() && sMaxAndIdx.top().first < temperatures[i]){
                auto val = sMaxAndIdx.top();
                sMaxAndIdx.pop();

                ans[val.second] = i - val.second;
            }
            sMaxAndIdx.push({temperatures[i], i});
        }
        return ans;
    }
};
