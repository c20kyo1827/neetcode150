class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        std::map<int, int> numToCount;
        for(auto& num : hand) {
            numToCount[num] += 1;
        }
        while(!numToCount.empty()) {
            int start = numToCount.begin()->first;
            for(int i=0 ; i<groupSize ; i++) {
                if(!numToCount.count(start+i))
                    return false;
                if(--numToCount[start+i] == 0)
                    numToCount.erase(start+i);
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        map<int, int> m;
        for (int i : hand) ++m[i];
        for (auto a : m) {
            if (a.second == 0) continue;
            for (int i = a.first; i < a.first + groupSize; ++i) {
                if (m[i] < a.second) return false;
                m[i] = m[i] - a.second;
            }
        }
        return true;
    }
};
