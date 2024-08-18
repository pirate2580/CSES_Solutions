#include <iostream>
#include <map>
#include<algorithm>
using namespace std;

int main() {
    string n;
    cin>>n;
    map<char, int> freq;
    for (auto ch: n) {
        freq[ch]++;
    }
    int oddfreq = 0;
    string oddchar;
    for (const auto& i: freq) {
        // cout<<i.first<<' '<<i.second<<endl;
        if(i.second%2==1) {
            oddfreq++;
            oddchar = i.first;
        }
    }
    if ((n.size()%2==0 and oddfreq > 0) || (n.size()%2==1 and oddfreq > 1)) {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    string tmp1, tmp2;
    for (const auto& i: freq) {
        tmp1 += string(i.second/2 , i.first);
        tmp2 += string(i.second/2 , i.first);
    }
    reverse(tmp2.begin(), tmp2.end());
    if (n.size()%2==0) {
        cout<<tmp1<<tmp2<<endl;
    }
    else {
        cout<<tmp1<<oddchar<<tmp2<<endl;
    }
    return 0;
}
