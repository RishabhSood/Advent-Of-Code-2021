#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;

    int curr;

    while(cin >> curr)
    {
        nums.push_back(curr);
    }

    int inc = 0;

    for(int i = 0; i < nums.size() - 3; i++)
    {
        if(nums[i+3] > nums[i])
            inc++;
    }

    cout << inc;
}
