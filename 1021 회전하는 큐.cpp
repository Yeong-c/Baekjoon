#include <iostream>
#include <deque> //deque를 사용하기 위해 include

using namespace std;

int main() {

    deque <int> deck; //c++ 에서 deque를 선언하는 방법 
    int size, testcase,temp,ans=0;

    cin >> size >> testcase;
    for(int i = 1 ; i <= size ; i++){deck.push_back(i);}


    while(testcase--){
        int val;
        cin >> val;
        int i;
        
        for(i = 0 ; i < deck.size() ; i++){ //입력받는 값의 위치는 지금 덱 자료구조에서는 다르게 진행되고 있기 때문에 반복마다 찾아주기.
            if(deck[i] == val) {
                break;
            }
        }
        
        if (i > deck.size()-1-i ){ //오른쪽이랑 가까워서 이동
            while(deck.front()!=val){
                deck.push_front(deck.back());
                deck.pop_back();
                ans++;
            }
        }

        else{//왼쪽으로 이동
            while(deck.front()!=val){
                deck.push_back(deck.front());
                deck.pop_front();
                ans++;
            }
        }
        deck.pop_front();
    }
    cout << ans;
    return 0;
}
