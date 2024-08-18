#include <iostream>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<long long>nums; nums.resize(n);
    for (int i = 0; i < n; i ++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    if (n%2 == 1) {
        long long median = nums[int(n/2)];
        long long totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += abs(nums[i] - median);
        }
        cout<<totsum;
    }
    else {
        long long median1 = nums[int(n / 2)];
        long long median2 = nums[int(n/2)-1];
        long long totsum1 = 0;
        long long totsum2 = 0;
        for (int i = 0; i < n; i++) {
            totsum1 += abs(nums[i] - median1);
        }
        for (int i = 0; i < n; i++) {
            totsum2 += abs(nums[i] - median2);
        }
        cout<<min(totsum1, totsum2)<<endl;
    }
    return 0;
}
