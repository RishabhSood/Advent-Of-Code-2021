#include <bits/stdc++.h>
using namespace std;

int versionDump = 0;

int parsePacket(string packet, int idx)
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
    // cout << "type (" << s << ") : " << type << endl;

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

        // cout << "val (" << num << ") : " << stoi(num, 0, 2) << endl;
    } else {
        // length type ID
        char ltID = packet[idx];
        // cout << "ltID : " << ltID << endl;
        idx++;

        if(ltID == '0') {
            string tlen = packet.substr(idx, 15);
            idx += 15;
            int len = stoi(tlen, 0, 2);
            // cout << "tlen (" << tlen << ") : " << len << endl;
            int range = idx + len - 1;
            while(idx < range)
                idx = parsePacket(packet, idx);
        } else {
            string subPacks = packet.substr(idx, 11);
            idx += 11;
            int numPacks = stoi(subPacks, 0, 2);
            // cout << "Num Sub Packs (" << subPacks << ") : " << numPacks << endl;
            for(int i = 0; i < numPacks; i++)
                idx = parsePacket(packet, idx);
        }
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
    parsePacket(binPacket, 0);
    cout << versionDump;
}
