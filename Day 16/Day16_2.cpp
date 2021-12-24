#include <bits/stdc++.h>
using namespace std;

int versionDump = 0;

void show(stack<int> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int parsePacket(string packet, int idx, stack<int> &st)
{
    if(idx >= packet.size())
        return -1;

    // cout << idx << endl;

    string s;
    // get version
    s = packet.substr(idx, 3);
    int ver = stoi(s, 0, 2);
    idx += 3;
    // cout << "version (" << s << ") : " << ver << endl;
    versionDump += ver;

    // get type
    s = packet.substr(idx, 3);
    int type = stoi(s, 0, 2);
    idx += 3;
    cout << "type (" << s << ") : " << type << endl;

    if(type == 4) {
        string num;
        int iter = 0;

        if(packet[idx] == '0')
        {
            num.append(packet.substr(idx + 1, 4));
            idx += 5;
        }
        else
        {
            while(packet[idx] != '0'){
                num.append(packet.substr(idx + 1, 4));
                idx += 5;
            }

            num.append(packet.substr(idx + 1, 4));
            idx += 5;
        }

        st.push(stoi(num, 0, 2));
        // cout << "val (" << num << ") : " << stoi(num, 0, 2) << endl;
    } else {
        // length type ID
        char ltID = packet[idx];
        // cout << "ltID : " << ltID << endl;
        idx++;
        stack<int> stNew;
        if(ltID == '0') {
            string tlen = packet.substr(idx, 15);
            idx += 15;
            int len = stoi(tlen, 0, 2);
            // cout << "tlen (" << tlen << ") : " << len << endl;
            int range = idx + len - 1;
            while(idx < range)
                idx = parsePacket(packet, idx, stNew);
        } else {
            string subPacks = packet.substr(idx, 11);
            idx += 11;
            int numPacks = stoi(subPacks, 0, 2);
            // cout << "Num Sub Packs (" << subPacks << ") : " << numPacks << endl;
            for(int i = 0; i < numPacks; i++)
                idx = parsePacket(packet, idx, stNew);
        }

        if(type == 0) {
            // sum
            int sum = 0;
            while(!stNew.empty())
            {
                sum += stNew.top();
                stNew.pop();
            }
            st.push(sum);
        } else if(type == 1) {
            // product
            int prod = 1;
            while(!stNew.empty())
            {
                prod *= stNew.top();
                stNew.pop();
            }
            st.push(prod);
        } else if(type == 2) {
            // minimum
            int mn = INT_MAX;
            while(!stNew.empty())
            {
                mn *= min(mn, stNew.top());
                stNew.pop();
            }
            st.push(mn);
        } else if(type == 3) {
            // maximum
            int mx = INT_MIN;
            while(!stNew.empty())
            {
                mx *= max(mx, stNew.top());
                stNew.pop();
            }
            st.push(mx);
        } else if(type == 5) {
            // greater than
            int first = stNew.top();
            stNew.pop();
            int second = stNew.top();
            stNew.pop();
            if(first > second)
                st.push(1);
            else
                st.push(0);
        } else if(type == 6) {
            // less than
            int first = stNew.top();
            stNew.pop();
            int second = stNew.top();
            stNew.pop();
            if(first < second)
                st.push(1);
            else
                st.push(0);
        } else {
            // equal to
            int first = stNew.top();
            stNew.pop();
            int second = stNew.top();
            stNew.pop();
            if(first == second)
                st.push(1);
            else
                st.push(0);
        }

        show(stNew);
    }

    return idx;
}

int main() {
    string packet;
    cin >> packet;

    map<char, string> hexParser;
    char res[4];

    for(int i = 0; i < 10; i++)
    {
        hexParser['0' + i] = bitset<4>(i).to_string();
    }
    char c = 'A';
    for(int i = 0; i < 6; i++)
    {
        char k = c + i;
        hexParser[k] = bitset<4>(10 + i).to_string();
    }

    string binPacket;

    for(char c : packet)
    {
        binPacket.append(hexParser[c]);
    }
    // cout << binPacket << endl;
    stack<int> st;
    parsePacket(binPacket, 0, st);
}
