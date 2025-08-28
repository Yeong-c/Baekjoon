#include <iostream>
#include <queue>

using namespace std;

int dx [4] = {-1,0,1,0};
int dy [4] = {0,1,0,-1};
char board[1005][1005];
int time_j[1005][1005];
int time_f[1005][1005];

#define X first
#define Y second

int main() {
    int r,c;
    cin >> r >> c; 
    queue<pair<int,int>> jihun;
    queue<pair<int,int>> fire;
    for(int i = 0;  i < r ; i++){
        for(int j = 0; j < c ; j++){
            cin >> board[i][j];
            time_j[i][j] = -1; //-1로 설정하면 방문 체크와 level 체크가 둘 다 가능함
            time_f[i][j] = -1;
            if(board[i][j] == 'J'){
                jihun.push({i,j});
                time_j[i][j] = 0;
            }
            else if (board[i][j] == 'F'){
               fire.push({i,j}); 
                time_f[i][j] = 0;
            } 
        }
    }
    // 배열 초기화

    while(!fire.empty()){
            auto cur = fire.front();   fire.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nx = cur.X + dx[i];   int ny = cur.Y + dy[i];    //nx,ny update 
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; //범위 체크 
                if(board[nx][ny] == '#' || time_f[nx][ny] >= 0) continue;//벽을 만나거나 이미 불이 번졌거나
                fire.push({nx,ny}); //fire
                time_f[nx][ny] = time_f[cur.X][cur.Y] + 1;
            }
        } // 불 BFS

    while(!jihun.empty()){
            auto cur = jihun.front();   jihun.pop();
            if(cur.X == 0 || cur.X == r-1 || cur.Y == 0 || cur.Y == c-1 ){ //탈출 가능한 지 체크
                cout << time_j[cur.X][cur.Y]+1;
                return 0;
            }
            for(int i = 0 ; i < 4  ; i++){
                int nx = cur.X + dx[i];   int ny = cur.Y + dy[i];     // nx , ny update    
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 범위 체크 
                if(board[nx][ny] == '#' || time_j[nx][ny] >= 0) continue; // 벽을 만나거나 이미 탈출 경로거나 
                if(time_f[nx][ny]!=-1 && time_j[cur.X][cur.Y]+1 >= time_f[nx][ny]) continue; // 내가 접근하는 경로가 불이 방문 했으며, 이미 불이 번진 경로인지 
                jihun.push({nx,ny});
                time_j[nx][ny] = time_j[cur.X][cur.Y]+1;
            }
        } // 지훈 BFS

    cout << "IMPOSSIBLE";

    return 0;
}
