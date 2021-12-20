#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    vector<long long> score;

    while(getline(cin, s))
    {
        stack<char> st;
        bool flag = true;
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
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(c == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(c == '}')
            {
                if(st.empty() || st.top() != '{')
                {   
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if(c == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }

        if(flag)
        {
            long long autoComplete = 0;
            while (st.size() > 0)
            {
                autoComplete *= 5;
                autoComplete += (st.top() == '<' ? 4 : st.top() == '[' ? 2 : st.top() == '{' ? 3 : 1);
                st.pop();
            }
            score.push_back(autoComplete);
        }
    }

    sort(score.begin(), score.end());
    for(auto elem : score)
        cout << elem << " ";
    cout << endl;
    cout << score[score.size() / 2];
  
    return 0;
}
