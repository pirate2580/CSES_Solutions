#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n; cin>>n;
    vector<pair<int,int>>nums;
    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        nums.push_back({a, i});
    }
    sort(nums.begin(), nums.end());
    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i].second < nums[i-1].second) {
            rounds++;
        }
    }
    cout<<rounds<<endl;
    return 0;
}
