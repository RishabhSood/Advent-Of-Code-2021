#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    int score = 0;

    while(getline(cin, s))
    {
        stack<char> st;
        for(auto c : s)
        {   
            if(c == '<' || c == '[' || c == '{' || c == '(')
            {
                st.push(c);
            }
            else if(c == '>')
            {
                if(st.empty() || st.top() != '<')
                {
                    score += 25137;
                    break;
                }
                st.pop();
            }
            else if(c == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    score += 57;
                    break;
                }
                st.pop();
            }
            else if(c == '}')
            {
                if(st.empty() || st.top() != '{')
                {
                    score += 1197;
                    break;
                }
                st.pop();
            }
            else if(c == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    score += 3;
                    break;
                }
                st.pop();
            }
        }
    }

    cout << score;
  
    return 0;
}
