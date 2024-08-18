#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    long long ans = 1;
    // cout<< 1e9<<endl;
    for (int i = 0; i < n; i++) {ans = 2 * ans % (1000000000 + 7);}
    cout<<ans<<endl;
    return 0;
}
