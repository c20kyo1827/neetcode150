class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;
        for(auto& token : tokens){
            if(token == "+"){
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a+b);
            }
            else if(token == "-"){
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b-a);
            }
            else if(token == "*"){
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a*b);
            }
            else if(token == "/"){
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b/a);
            }
            else{
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
