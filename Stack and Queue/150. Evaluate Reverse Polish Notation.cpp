class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                int a = (int)s.top();
                s.pop();
                int b = (int)s.top();
                s.pop();
                int newRes = a + b;
                s.push(newRes);
            }
            else if(tokens[i] == "-")
            {
                int a = (int)s.top();
                s.pop();
                int b = (int)s.top();
                s.pop();
                int newRes = b - a;
                s.push(newRes);
            }
            else if(tokens[i] == "*")
            {
                int a = (int)s.top();
                s.pop();
                int b = (int)s.top();
                s.pop();
                int newRes = a * b;
                s.push(newRes);
            }
            else if(tokens[i] == "/")
            {
                int a = (int)s.top();
                s.pop();
                int b = (int)s.top();
                s.pop();
                int newRes = b / a;
                s.push(newRes);
            }
            else
            {
                int a = stoi(tokens[i]);
                s.push(a);
            }
        }
        return s.top();
    }
};