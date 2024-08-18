#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin>>n;
    vector<long long>nums; nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    long long missing = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] <= missing) {
            missing += nums[i];
        }
        else {
            break;
        }
    }
    cout<<missing<<endl;
    return 0;
}

// consider 1+2 = 3