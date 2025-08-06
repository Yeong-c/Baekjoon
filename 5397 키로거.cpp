#include <iostream>
#include <list>//이중연결리스트 stl을 위해 include를 합니다.

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    string str;
    list<char> password; //이중연결리스트 stl을 사용하기 위해 선언하는 부분.
    list<char>::iterator iter; //iterator 사용

    cin >> testcase;

    while(testcase--){
        cin >> str;
        password.clear();     //여러개의 테스트케이스에 변수들을 재활용할 때는 초기값으로 초기화를 해주어야함 !! 
        iter = password.begin(); 

        for(char cmd : str){ // 범위기반 for문 for (cmd : str)처럼 쓰는 건 불가능, 이 cmd는 for문 안에서 새로 선언해야만 함.

        switch (cmd) { //분기마다 break를 해줘야함 !!
            case '<':
            if(password.begin() != iter) iter--;
            break;

            case '>':
            if(password.end() != iter) iter++;
            break;

            case '-':
            if(password.begin() != iter) iter = password.erase(--iter); //지운 node의 다음 node를 가르키는 iterator를 return
            break;
            
            default : //switch 문에서의 예외처리 default 구문 사용
            password.insert(iter,cmd);  
            break;
        }
      }
        for (list<char>::iterator iter = password.begin() ; iter != password.end() ; iter++ ) cout << *iter;
        cout<< "\n";
    }


    
    return 0;
}
