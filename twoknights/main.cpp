#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i==1)cout<<0<<endl;
        else if (i==2)cout<<6<<endl;
        // else if (i==3)cout<<28<<endl;
        else {
            long long total = i * i * (i + 1) * (i - 1) / 2;
            // cout<<"total is: "<<total<<endl;
            // cout<<"test: "<< (10 + 4 * (i-2))<<endl;
            long long attacking = 4 * (i - 1) * (i - 2);
            long long ans = total - attacking;
            //(-4i+6)(i-4)
            cout<<ans<<endl;
        }
    }
    return 0;
}