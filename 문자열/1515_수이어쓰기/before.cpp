#include <iostream>
using namespace std;

int main() {

    string num;
    int check = 1;
    cin >> num;
    int pos = 0;
    int target = num[pos];


   while(pos!=num.length()){
    string tmp = to_string(check);
    for(int k = 0 ; k < tmp.length() ; k++){ 
        if(tmp[k] == target){ // target 변수 굳이?  
            target = num[++pos]; // out of boundary 발생 가능성...
        }
    }
    check++;     
   }

    cout << check-1;


    return 0;
}
