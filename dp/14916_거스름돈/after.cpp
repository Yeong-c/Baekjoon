#include <iostream>
#include <vector>
using namespace std;

int main() {
    int coin;
    cin >> coin;
    vector <int> dp; 

    for(int i = 0 ; i <= coin ; i++){
        dp.push_back(1000000);
    }

    dp[0]=0; //for 문에서 i=2, i=5 일때 사용하기 위해서 

    for(int i = 2 ; i <= coin ; i++){ //dp의 bottom up 구조 점화식 형태 ! -> 타뷸레이션 기법  dp == 기억하며 풀기 
       
        if(i >= 2 && dp[i-2]!=1000000){ //절대 발생할 수 없는 값을 대입해서 그전 idx를 방문 하였는가? 안 하였는가? 체크
            if(dp[i] > dp[i-2]+1) // 값의 비교 
            dp[i]= dp[i-2]+1;
        }
        if(i >= 5 && dp[i-5]!=1000000){
            if(dp[i] > dp[i-5]+1)
            dp[i]= dp[i-5]+1;
        }
}
    
    if(dp[coin]!=1000000){
        cout << dp[coin];
    }
    else{
        cout << -1;
    }
  
    return 0;
}
