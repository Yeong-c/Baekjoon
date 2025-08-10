#include <iostream>


using namespace std;

const int MX = 10005;
int arr[2*MX];
int head = MX, tail = MX; //빠른 접근을 위해 전역 변수로 선언.

//덱을 배열에서 구현할때 head, tail이 같은 지점에서 시작하고 여의봉처럼 양 옆으로 증가하는 느낌. 
//head == tail -> empty 상태 
//head는 맨 앞의 요소 가르키기. tail은 맨 뒤의 요소의 한칸뒤를 가르킨다. 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase,num;
    string str;
    cin >> testcase;

    while(testcase--){
        cin >> str;
        
        if(str == "push_front"){
            cin >> num;
            arr[--head] = num;
        } 
        else if(str == "push_back"){
            cin >> num;
            arr[tail++] = num;           
        }
        else if(str == "pop_front"){
            tail == head ? cout << -1 << "\n" : cout << arr[head++] <<"\n";
        }
        else if(str == "pop_back"){
            tail == head ? cout << -1 << "\n" : cout << arr[--tail] << "\n"; 
        }
        else if(str == "size"){
            cout << tail - head << "\n";
        }
        else if(str == "empty"){
            tail == head ? cout << 1 << "\n" : cout << 0 << "\n";
        }
        else if(str == "front"){
            tail == head ? cout << -1 << "\n" : cout << arr[head] << "\n"; 
        }
        else if(str == "back"){
            tail == head ? cout << -1 << "\n" : cout << arr[tail-1] << "\n";            
        }
    }  
    return 0;
}
