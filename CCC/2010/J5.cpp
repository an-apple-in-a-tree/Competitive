#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int,int>> points;
vector<pair<int,int>> visited;

bool visit(pair<int,int> cur){
    for(auto vi: visited){
        if(vi == cur){
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int grid [9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            grid[i][j] = 0;
            
        }
    }
    int x,y;
    cin >> x >> y;
    pair<int,int> cur (x,y);
    grid[x][y] = 0;
    cin >> x >> y;
    pair<int,int> end (x,y);
    points.push(cur);
    
    
    
    while(points.size() > 0){
        cur = points.front();
        if(cur == end){
            cout << grid[end.first][end.second] << endl;
            break;
        }
        visited.push_back(cur);
        points.pop();
        pair<int,int> move;
        //-2,+1
        move.first = cur.first-2;
        move.second = cur.second+1;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
       
        //-1+2
        move.first = cur.first-1;
        move.second = cur.second+2;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        //+2+1
        move.first = cur.first+2;
        move.second = cur.second+1;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
           // cout << cur.first << cur.second << endl;
        }
        //+1+2
        move.first = cur.first+1;
        move.second = cur.second+2;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        //+2-1
        move.first = cur.first+2;
        move.second = cur.second-1;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        //+1-2
        move.first = cur.first+1;
        move.second = cur.second-2;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        //-2-1
        move.first = cur.first-2;
        move.second = cur.second-1;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        //-1-2
        move.first = cur.first-1;
        move.second = cur.second-2;
        if(visit(move) == false && move.first < 9 && move.second < 9 && move.first > 0 && move.second > 0){
            points.push(move);
            grid[move.first][move.second] = grid[cur.first][cur.second] + 1;
        }
        
    }
    
    return 0;
}

