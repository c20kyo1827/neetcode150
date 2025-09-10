class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue <int> _pq;
        for(auto stone : stones){
            _pq.push(stone);
        }
        while(_pq.size() > 1){
            int stone1 = _pq.top(); _pq.pop();
            int stone2 = _pq.top(); _pq.pop();
            if(stone1 != stone2)
                _pq.push(std::abs(stone1-stone2));
        }
        return _pq.size() ? _pq.top() : 0;
    }
};
