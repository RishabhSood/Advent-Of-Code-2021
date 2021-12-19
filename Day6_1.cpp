#include <bits/stdc++.h>
using namespace std;

void processFish(vector<int> &fish)
{
    string s;
    cin >> s;

    stringstream stream(s);
    while(getline(stream, s, ','))
    {
        fish[stoi(s, 0, 10)]++;
    }
}

void manipulate(vector<int> &fish)
{
    int spawn = fish[0];
    for(int i = 0; i < fish.size() - 1; i++)
    {
        fish[i] = fish[i+1];
    }
    fish[8] = spawn;
    fish[6] += spawn;
}

int main() {
    vector<int> fish(9);
    processFish(fish);

    for(int i = 0; i < 80; i++)
    {
        manipulate(fish);
    }

    int sum = 0;
    for(auto elem : fish)
        sum += elem;
    cout << sum;
}
