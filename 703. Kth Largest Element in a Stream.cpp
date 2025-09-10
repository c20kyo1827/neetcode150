class KthLargest {
    int _k;
    std::multiset<int> _ms;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto num : nums){
            _ms.insert(num);
            if(_ms.size() > _k)
                _ms.erase(_ms.begin());
        }
        // show();
    }
    
    int add(int val) {
        _ms.insert(val);
        if(_ms.size() > _k) {
            _ms.erase(_ms.begin());
        }
        // show();
        return *_ms.begin();
    }

    void show() {
        cout << "[ K : " << _k << " ]\n";
        for(auto num : _ms) {
            cout << num << "\n";
        }
    }
};

// class KthLargest {
// public:
    
//     int kth;
//     vector <int> numbers;
    
//     KthLargest(int k, vector<int>& nums) {
//         kth = k - 1;
//         numbers = nums;
//         sort(numbers.begin(), numbers.end(), greater<int>());
//     }
    
//     int add(int val) {
//         numbers.insert(lower_bound(numbers.begin(), numbers.end(), val, greater<int>()), val);
//         return numbers[kth];
//     }
// };

// class KthLargest {
// public:
//     KthLargest(int k, vector<int> nums) {
//         for (int num : nums) {
//             q.push(num);
//             if (q.size() > k) q.pop();
//         }
//         K = k;
//     }
    
//     int add(int val) {
//         q.push(val);
//         if (q.size() > K) q.pop();
//         return q.top();
//     }

// private:
//     priority_queue<int, vector<int>, greater<int>> q;
//     int K;
// };
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
