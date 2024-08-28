#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n;
int main() {
    cin>>n;
    vector<int>song(n);
    for (int i = 0; i < n; i++) {
        cin>>song[i];
    }
    // for (auto _: song){cout<<_<<' ';}cout<<endl;
    int l = 0, r = 0;
    int maxlen = 1;
    set<int>used;
    while (l < n && r < n) {
        // cout<<l<<' '<<r<<endl;
        if (used.find(song[r]) == used.end()) { // not found
            used.insert(song[r]);
            r++;
        }
        else {
            used.erase(song[l]);
            l++;
        }
        maxlen = max(maxlen, r - l);
    }
    cout<<maxlen<<endl;
    return 0;
}
