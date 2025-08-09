#include <bits/stdc++.h>
using namespace std;

int arr[2000005];
int head = 0, tail = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testcase, n;
    string str;
    cin >> testcase;

    while (testcase--) {
        cin >> str;

        if (str == "push") {
            cin >> n;
            arr[tail++] = n; // push
        }
        else if (str == "pop") {
            if (head == tail) { // empty
                cout << -1 << "\n";
            }
            else {
                cout << arr[head++] << "\n"; // pop
            }
        }
        else if (str == "size") {
            cout << (tail - head) << "\n"; // size
        }
        else if (str == "empty") {
            cout << (head == tail ? 1 : 0) << "\n"; // empty
        }
        else if (str == "front") {
            if (head == tail) { // empty
                cout << -1 << "\n";
            }
            else {
                cout << arr[head] << "\n"; // front
            }
        }
        else if (str == "back") {
            if (head == tail) { // empty
                cout << -1 << "\n";
            }
            else {
                cout << arr[tail - 1] << "\n"; // back
            }
        }
    }
    return 0;
}
