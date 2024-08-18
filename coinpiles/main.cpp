#include <iostream>
using namespace std;
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int numone, numtwo = 0;
    int t;
    cin>>t;
    while (t--) {
        long long a, b;
        cin>>a>>b;
        if ((2 * b - a)%3!=0 or (2 * a - b)%3!=0) {
            cout<<"NO"<<endl;
        }
        else if ((2 * b - a < 0) or (2 * a - b < 0)) {
            // cout << (2 * b - a < 0) << (a - 2 * b < 0)<<endl;
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
        // x = (2 * b - a) / 3;
        // y = (2 * a - b) / 3;
        // if (x!=int(x) or y!=int(y)) {
        //     cout<<"NO"<<endl;
        // }
    }

    // 1 * numone + 2 * numtwo      2 * numone + 1 * numtwo

    return 0;
}
