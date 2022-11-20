class Solution {
public:
    int calculate(string s) {
        int i = 0, N = s.size();
        return dfs(s, i, N);
    }
    
    int dfs(const string& s, int& i, const int& N){
        int res = 0, sign = 1, num = 0;
        while(i < N && s[i] != ')'){
            if(isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else{
                res += sign * num;
                num = 0;
                if(s[i] == '+') sign = 1;
                else if(s[i] == '-') sign = -1;
                else if(s[i] == '('){
                    i++;
                    res = res + sign * dfs(s, i, N);
                }
            }
            i++;
        }
        return res + sign * num;
    }
};