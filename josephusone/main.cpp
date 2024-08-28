#include <iostream>
#include<queue>
using namespace std;

int main() {
    int n; cin>>n;
    queue<int>nums;
    bool rem = false;
    for (int i = 1; i <= n; i++) {
        nums.push(i);
    }
    while (!nums.empty()) {
        int tmp = nums.front();
        nums.pop();
        if (rem) {
            rem =  false;
            cout<<tmp<<' ';
        }
        else {
            rem = true;
            nums.push(tmp);
        }
    }
    return 0;
}
