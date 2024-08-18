#include <iostream>
// #include <vector>
#include<set>
#include <algorithm>
using namespace std;
int n, m;
// int min_binary_search(vector<int> tickets, int price) {
//     // find index of largest value such that its less than the customers
//     // desired price
//     int l = 0; int r = n;
//     while (l < r) {
//         int m = (l + r) / 2;
//         if (price > tickets[m]) {
//             l = m;
//         }
//         else {
//             r = m - 1;
//         }
//     }
//     return r;
// }

int main() {
    cin>>n>>m;
    multiset<int>ticket;
    // vector<int>customer;
    // customer.resize(m);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        ticket.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        // for(int tmp: ticket) {
        //     cout<<tmp<<' ';
        // }
        // cout<<endl;
        int customer;
        cin>>customer;
        auto it = ticket.upper_bound(customer);
        if (it == ticket.begin()) {
            cout<<-1<<endl;
        }
        else {
            --it;
            cout<<*it<<endl;
            ticket.erase(it);
        }
    }
    return 0;
}
