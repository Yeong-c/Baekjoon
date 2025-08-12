#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long a,b;
    long long ans=0;
    cin >> a >> b;
     int flag = sqrt(b);
    vector <bool> isprime(flag+5); 
    vector <int> prime;
      
    fill(isprime.begin(),isprime.end(),true);

    for(int i = 2 ; i <= sqrt(flag) ; i++){ 
       if(isprime[i]){           
           for(int j = i*i ; j <= flag ; j+=i){
               isprime[j] = false;            
           }
       }       
    }

    for(int i = 2 ; i <= flag+1 ; i++){
        if(isprime[i]){
            prime.push_back(i);  
        }
    }
  
    for(vector <int> :: iterator iter = prime.begin() ; iter != prime.end() ; iter++){
        long long val = (*iter); 
        long long square = val;
        for(int i = 1 ;  ; i++ ){ 
            square *=val; 
            if(square >= a && square <= b){
                ans++;
            }
            if(square > b/val ) break; 
        }
    }
    cout << ans;  
    return 0;
}
