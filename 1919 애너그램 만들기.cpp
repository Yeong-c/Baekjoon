#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str_a, str_b;
    int arr_a[26], arr_b[26], sum = 0;
    fill(arr_a,arr_a+26,0);
    fill(arr_b,arr_b+26,0);
    cin >> str_a >> str_b; //1,2번째 문자열을 받는다. 
    
    for(int i = 0 ; i < str_a.length() ; i++) arr_a[str_a[i]-97]++;  
    for(int j = 0 ; j < str_b.length() ; j++) arr_b[str_b[j]-97]++;
    // 문자열, 각각의 요소 즉 char의 아스키코드 값을 활용하여 arr에 등장한 빈도수를 기록한다.

    for(int k = 0 ; k < 26 ; k++) sum += abs(arr_a[k]-arr_b[k]); // 두 빈도수의 차의 합을 절대값으로 쌓아간다.
    

    cout << sum;
    
    return 0;
}
