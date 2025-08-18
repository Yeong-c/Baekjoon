#include <iostream>
#include <queue>

bool board[501][501];
bool visited[501][501];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second // 매크로 문법 잘 하기... 
using namespace std;
// 요기는 기본 세팅 ! 외워두자. board 배열, visited 배열 ,dx,dy를 활용한 좌표설정 

int main() {
    queue <pair<int,int>> que; //BFS는 queue을 사용해서 구현해봅시다. 
    int width,length,area=0,cnt=0,ans=0;
    cin >> length >> width;

    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < width ; j++){
            cin >> board[i][j];          
        }
    }

    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < width ; j++){
           if(!visited[i][j] && board[i][j]){ // for문 돌려서 visit X and board 1 이면 진입 
               cnt++;
               area++;
               que.push({i,j}); //처음 부분 push 하고 방문표시 해주기 !
               visited[i][j] = true;      
               
               while(!que.empty()){            
                   auto cur = que.front(); //front 확인하고 바로 pop 해버리자 
                   que.pop();
                   
                   for(int k = 0 ; k < 4 ; k++){
                       int nx = cur.X+dx[k];
                       int ny = cur.Y+dy[k];
                       if(nx >= 0 && nx < length && ny >= 0 && ny < width){ // 범위 체크 무조건 먼저 !                                           
                           if(board[nx][ny] && !visited[nx][ny]){
                           que.push({nx,ny});  
                           visited[nx][ny] = true; //push 하면서 방문표시를 해줍시다
                           area++;
                           }
                       }
                   }
               }    
                   ans = max(area,ans);
                   area = 0;
           }
        }
    }  
    cout << cnt << "\n" << ans;    
    return 0;
}
