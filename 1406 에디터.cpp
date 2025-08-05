#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int testcase;
    char cmd;
    
    list<char> edit; // 연결리스트 선언 c++ 에서는 이중연결리스트 
    list<char>::iterator cursor; 
    cin >> str >> testcase;
    for(int i = 0 ; i < str.length() ; i++) edit.push_back(str[i]);
    cursor=edit.end();

    while(testcase--){ 
        cin>>cmd;
        switch (cmd) { //컴파일러 최적화 & 하나의 변수값에 따른 분기를 위해 
            case 'L':
            if(edit.begin() != cursor) cursor--; 
            break;
                
            case 'D':
            if(edit.end() != cursor) cursor++; 
            break;
            
            case 'B':
            if(edit.begin() != cursor) cursor = edit.erase(--cursor); // 삭제한 원소 자리의 다음을 가리키는 iterator 반환 
            break;

            case 'P':
            cin >> cmd;
            edit.insert(cursor, cmd); // 1번째 파라미터가 가르키는 곳에서 2번째 파라미터를 삽입한다 
            break;   
        }
    }

for(list<char>::iterator iter = edit.begin(); iter != edit.end(); iter++) { //iterator에서 전형적인 순회문 구조 조건, 증감 부분 주의 !
    cout << *iter;
}
    
    
    return 0;
}
