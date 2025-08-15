#include <iostream>
#include <vector>


using namespace std;



int main() {
    int coin;
    cin >> coin;
    vector <pair<int,bool>> dp; 

    for(int i = 0 ; i <= coin ; i++){
        dp.push_back({1000000,false});
    }

    dp[2].first = 1;
    dp[2].second = true;
    dp[5].first = 1;
    dp[5].second = true;
    
    for(int i = 2 ; i <= coin ; i++){ //pair를 사용하긴 했는데... 메모리 낭비.. -> 로직 더 간결하게 쓰는 법 연습 && 직접 생각하면서 손코딩하기 
       
        if(i >= 2 && dp[i].first > dp[i-2].first + 1 && dp[i-2].second == true){
            dp[i].first = dp[i-2].first + 1;
            dp[i].second = true;
        }
        if(i >= 5 && dp[i].first > dp[i-5].first + 1 && dp[i-5].second == true){
            dp[i].first = dp[i-5].first + 1;
            dp[i].second = true;
        }
}
    
    if(dp[coin].first!=1000000){
        cout << dp[coin].first;
    }

    else{
        cout << -1;
    }
    
    return 0;
}
