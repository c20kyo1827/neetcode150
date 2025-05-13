// Priority queue
class Solution {
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first)
                return a.first < b.first; // 小的 first 優先
            return a.second > b.second;   // 若 first 相等，小的 second 優先
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> ans(nums.size()-k+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // {value, index}
        for(int i=0 ; i<ans.size() ; i++){
            if(i==0){
                for(int j=0 ; j<k ; j++){
                    pq.push({nums[j], j});
                }
                ans[0] = pq.top().first;
            }
            else{
                pq.push({nums[i+k-1], i+k-1});
                while(pq.top().second < i){
                    pq.pop();
                }
                ans[i] = pq.top().first;
            }
        }
        return ans;
    }
};

// Dequeue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q; // store index
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k)
                q.pop_front();

            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
