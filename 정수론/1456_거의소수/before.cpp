#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a,b; // 범위 설정 오류, long long으로 선언해야함
    long long val,ans=0;
    cin >> a >> b;
    vector <bool> isprime(b); // 루트 b 까지의 소수를 수집해야하는데 틀림. 
    vector <int> prime;
    
    
    fill(isprime.begin(),isprime.end(),true);

    int flag = sqrt(b);

    for(int i = 2 ; i <= flag ; i++){  
       if(isprime[i]){           
           prime.push_back(i);
           sum++;
           
           for(int j = i*i ; j <= flag ; j+=i){
               isprime[j] = false;            
           }
       }       
    } // 소수 수집과, 소수 추출을 동시에 할 경우 안쪽 for 문의 int j = i*i  부분에서 overflow 발생


    

    
    for(vector <int> :: iterator iter = prime.begin() ; iter != prime.end() ; iter++){
        val = (*iter);
        for(int i = 1 ;  ; i++ ){             
            if(pow(val,i) >= a && pow(val,i) <= b){
                ans++;
            }
            if(log10(pow(val,i)) >= 18 || pow(val,i) > b ) break; 
        }
    }
  //pow, log는 굳이 ? 연산 속도가 너무 느려서 비효율적임.

    cout << ans;
  
    return 0;
}
