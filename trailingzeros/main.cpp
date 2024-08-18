#include <iostream>
using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin>>n;
    int power = 5;
    int ans = 0;
    while (power <= n) {
        int add = n / power;
        power *= 5;
        ans += add;
    }
    cout << ans << endl;
    return 0;
}