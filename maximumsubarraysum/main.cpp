#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums;
    nums.resize(n);
    vector<long long>psum;
    psum.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + nums[i-1];
    }
    // for (int i = 1; i <= n; i++) {cout<<psum[i]<<" ";} cout<<endl;
    long long minimum = 0;
    long long maximumsum = -1000000000;
    for (int i = 1; i <= n; i++) {
        minimum = min(minimum, psum[i - 1]);
        maximumsum = max(psum[i] - minimum, maximumsum);
    }
    cout<<maximumsum<<endl;
    return 0;
}
