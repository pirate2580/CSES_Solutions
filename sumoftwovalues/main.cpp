#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, x;
int binary_search(vector<pair<int,int>>& nums, int x) {
    int l = 0; int r = n;

    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m].first < x) {
            l = m + 1;
        }
        else if (nums[m].first == x) {
            return m;
        }
        else {
            r = m;
        }
    }
    return - 1;
}


int main() {
    cin>>n>>x;
    vector<pair<int,int>>nums;
    for (int i = 0; i < n; i++) {
        int tmp; cin>>tmp;
        nums.push_back({tmp, i});
    }
    sort(nums.begin(), nums.end());
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int idx = binary_search(nums, x - nums[i].first);
        // cout<<idx<<endl;
        if (idx != -1 && i != idx) {
            cout<<nums[i].second + 1<<' '<<nums[idx].second + 1<<endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
