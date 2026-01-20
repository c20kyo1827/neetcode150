// Stack
class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> star, left;
        for(int i=0 ; i<s.size() ; i++){
            if (s[i] == '*') star.push(i);
            else if (s[i] == '(') left.push(i);
            else {
                if(left.empty() && star.empty()) return false;
                if(!left.empty()) left.pop();
                else star.pop();
            }
        }
        while(!left.empty() && !star.empty()){
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};

// Pointer
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for(int i=0 ; i<s.size() ; i++){
            if (s[i] == '(' || s[i] == '*') ++left;
            else --left;
            if (left < 0) return false;
        }
        if (left == 0) return true;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')' || s[i] == '*') ++right;
            else --right;
            if (right < 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        /*
            low indicates the number of left parentheses when a star is treated as a right parenthesis in the presence of a left parenthesis (this approach minimizes the increase in the number of right parentheses).

            high indicates the number of left parentheses when asterisks are treated as left parentheses.
        */ 
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                ++low; ++high;
            } else if (c == ')') {
                if (low > 0) --low;
                --high;
            } else {
                // *
                if (low > 0) --low;
                ++high;
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};

