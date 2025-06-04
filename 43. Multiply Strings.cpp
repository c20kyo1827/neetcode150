class Solution {
public:
    string multiply(string num1, string num2) {
        // multiplicand * multiplier
        string multiplicand = num1.size() > num2.size() ? num1 : num2;
        string multiplier = num1.size() > num2.size() ? num2 : num1;
        // string result = multiplicand;
        std::vector<int> digits(num1.size() + num2.size(), 0); // # of digits of digits would be range from n + m − 1 ~ n + m
        for(int i=multiplier.size()-1 ; i>=0 ; i--){
            for(int j=multiplicand.size()-1 ; j>=0 ; j--){
                int sum = atoi(multiplicand[j]) * atoi(multiplier[i]) + digits[i+j+1];
                digits[i+j+1] = sum%10;
                digits[i+j] += sum/10;
                // cout << j << " -> " << atoi(multiplicand[j]) << "\n";
                // cout << i << " -> " << atoi(multiplier[i]) << "\n";
                // cout << "Sum : " << sum << "\n";
            }
        }
        string result;
        for(auto digit : digits){
            if(!result.empty() || digit != 0)
                result.push_back(itoa(digit));
        }
        return result.empty() ? "0" : result;
    }

    int atoi(char a){
        return (a - '0');
    }

    char itoa(int a){
        return a + '0';
    }
};
