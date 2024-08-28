#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int x, n; cin>>x>>n;
    vector<int>lights(n);
    for (int i = 0; i < n; i++) {
        cin>>lights[i];
    }
    set<int>intervals = {0,x};
    multiset<int> lengths = {x};

    for (int i = 0; i < n; i++) {
        auto it = intervals.upper_bound(lights[i]);
        int right = * it;
        int left = *(--it);
        // cout<<left<<' '<<right<<endl;
        auto len_it = lengths.find(right - left);
        lengths.erase(len_it);
        lengths.insert(right - lights[i]);
        lengths.insert(lights[i] - left);

        // for (auto _: lengths){cout<<_<<' ';}cout<<endl<<endl;

        intervals.insert(lights[i]);
        cout<<*lengths.rbegin()<<endl;
    }

    return 0;
}


// [0, 8]               8, [0, 8]
// [0,3], [3, 8]        5, [3, 8] | 3, [0, 3]