#include <iostream>
using namespace std;

int main() {
   
    int check = 1;
    int pos = 0;
    string num;
    cin >> num;

   while(pos!=num.length()){
    string tmp = to_string(check);
    for(char c : tmp){
        if(c == num[pos]){
            pos++;
        }   
        if(pos == num.length()){ 
            cout << check;
            return 0;
        }  
    }
     check++;
   }
    return 0;
}
