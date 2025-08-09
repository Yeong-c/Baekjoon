#include <bits/stdc++.h>
using namespace std;

#define ll long long
//최악의 경우 integer overflow 발생할 수 있음. 발생하면 디버깅이 오래걸리기 때문에 유심히 체크해봐야겠음 범위 체크 ...

stack<int> s;
int n;
ll ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll h;
  while (n--) {
    cin >> h;
    while(!s.empty() && s.top() <= h)
      s.pop();
    ans += s.size();
    s.push(h);
  }
  cout << ans;
  return 0;
}
