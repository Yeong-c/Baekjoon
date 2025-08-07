#include <iostream>
#include <stack> //배열을 선택하게 되면 선형탐색을 하게돼서 N^2 이라 스택을 고민함.

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<pair<int, int> > s; //s.first = index , s.second = height // 출력값이 타워의 index이기 때문에 pair를 이용한 stack을 선언함.
    int tower, height;
    cin >> tower;

    for(int i = 1 ; i <= tower ; i++){

        cin >> height;

        while(!s.empty()){ //스택이 비어있을 때 까지 돌린다.
            
        if(s.top().second < height) s.pop(); //현재 push할려는 높이가 top의 높이보다 크다면 pop을 해서 수신탑을 쭉 찾는다  Why -> 어차피 중요한 포인트는 높이가 큰 녀석만 수신이 되기 때문임. 
        else break; // 현재 push할려는 높이가 top의 높이보다 작다면 top에 존재하는 element가 수신탑임. -> 수신탑을 찾았으면 나간다. 
            
        }
        if(s.empty()) cout << 0 <<" "; // 스택이 비어있을 경우-? 수신탑을 찾지 못한 경우. 
        
        else cout << s.top().first <<" "; // 스택이 비어있지 않다면 수신탑을 찾았다는 의미.
    
        s.push({i,height});
        
    }
    return 0;
}
