// #include <iostream>
// #include <vector>
// using namespace std;
//
// // Function to find the digit at position k
// char findDigitAtPosition(long long k) {
//     long long len = 1;  // Length of the numbers we're currently considering
//     long long count = 9;  // Number of integers with the current length
//     long long start = 1;  // Starting integer with the current length
//
//     while (k > len * count) {
//         k -= len * count;
//         len++;
//         count *= 10;
//         start *= 10;
//     }
//
//     start += (k - 1) / len;
//     string number = to_string(start);
//     return number[(k - 1) % len];
// }
//
// int main() {
//     int q;
//     cin >> q;
//     vector<long long> queries(q);
//
//     for (int i = 0; i < q; i++) {
//         cin >> queries[i];
//     }
//
//     for (int i = 0; i < q; i++) {
//         cout << findDigitAtPosition(queries[i]) << endl;
//     }
//
//     return 0;
// }

#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
vector<char>sols;
long long q, k;
int main() {
    cin>>q;
    while(q--) {
        cin>>k;
        long long subtract = 9;
        long long length = 1;
        long long num = 1;
        while (k - length * subtract >= 0) {
            k -= length * subtract;
            length++;
            subtract *= 10;
            num *= 10;
            // cout<<k<<endl;
        }
        num += (k-1) /length;

        string numstring = to_string(num);
        sols.push_back(numstring[(k - 1) % length]);
        // cout<<numstring[(k - 1) % length]<<endl;

    }
    for (int i = 0; i < sols.size(); i++) {
        cout<<sols[i]<<endl;
    }
    return 0;
}
