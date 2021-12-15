#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> v(n);

    do
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                v[n - i - 1]++;
            else
                v[n - i - 1]--;
        }
    } while(cin >> s);

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[i] > 0)
            sum += pow(2, i);
    }

    cout << sum * (pow(2, n) - 1 - sum);
}
