#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    multiset<int>towers;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // for (auto x: towers){cout<<x<<' ';}cout<<endl;
        auto it = towers.upper_bound(arr[i]);
        if (it == towers.end()) {
            // cout<<"not found"<<endl;
            towers.insert(arr[i]);
            ans++;
        }
        else {
            // cout<<"upper bound: "<<*it<<endl;
            towers.erase(it);
            towers.insert(arr[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
