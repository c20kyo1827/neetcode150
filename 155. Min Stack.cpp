// class MinStack {
//     int _min;
//     std::stack<int> _s;
// public:
//     MinStack() {
//         _min = INT_MAX;
//     }
    
//     void push(int val) {
//         if(_min >= val){
//             _s.push(_min);
//             _min = val;
//         }
//         _s.push(val);
//     }
    
//     void pop() {
//         if(_min == _s.top()){
//             _s.pop();
//             _min = _s.top();
//             _s.pop();
//         }
//         else{
//             _s.pop();
//         }
//     }
    
//     int top() {
//         return _s.top();
//     }
    
//     int getMin() {
//         return _min;
//     }
// };

class MinStack {
    std::stack<int> _s;
    std::stack<int> _sMin;
public:
    MinStack() {}
    
    void push(int val) {
        _s.push(val);
        if(_sMin.empty() || _sMin.top() >= val) _sMin.push(val);
    }
    
    void pop() {
        if(_s.top() == _sMin.top()) _sMin.pop();
        _s.pop();
    }
    
    int top() {
        return _s.top();
    }
    
    int getMin() {
        return _sMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
