#include <iostream>
#include <queue>
#include <tuple> //tuple을 사용하기 위해 

// 본 유형은 토마토 bfs에서 시작점이 여러개 일 경우
using namespace std;
int dz[6] = {0,0,0,0,1,-1};
int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int board[105][105][105];
int depth[105][105][105];

int main() {
    queue<tuple<int,int,int>> queue;
    int n, m ,h,day;
    cin >> m >> n >> h; // n = 세로 m = 가로 h = 높이

    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                cin >> board[i][j][k];
                depth[i][j][k] = -1; // 방문 안한 곳 depth -1로 초기화 -> 방문 여부와 길이를 동시에 파악하기 위함.
                if(board[i][j][k]==1){ //토마토가 있다면 push 하자 if문 조건문 값이 0이 아니면 true처리 
                    queue.push({i,j,k});
                    depth[i][j][k]=0;                    
                }
            }
        }
    }  // 동시다발적으로 토마토가 익는다 -> 시작점이 여러개인 bfs -> bfs 시작 지점들을 다 넣어주면 되는거 

   while(!queue.empty()){ //큐가 빌 때 까지 
        auto cur = queue.front(); //front() 추출하기 + Pop 하기 
        queue.pop();
        for(int dir = 0 ; dir < 6 ; dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m)continue; 
            if(board[nz][nx][ny] == 1 || board[nz][nx][ny] == -1 || depth[nz][nx][ny] >= 0)continue; // 조건문에서 실수 그만 하기 !
            queue.push({nz,nx,ny});
            board[nz][nx][ny] = 1; // 토마토 익은 사실 갱신 해주기 !
            depth[nz][nx][ny] = depth[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;   // depth 갱신 
            day = depth[nz][nx][ny];
        }
        
    };
 
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < m ; k++){
                if(board[i][j][k] == 0){
                    cout << -1;
                    return 0;
                };
            }
        }
    }
    cout << day;    
    return 0;
}
