// Gloria Li, 2022
//CCC 2008 Maze
include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int t, r, c;
    //make the map
    char map[20][20];
    //count the distance
    int dist [20][20];
    cin >> t;
    //amount of test cases
    for(int i = 0; i < t; i++){
        cin >> r >> c;
        //original vertice is visited and distance is 1
        //get all map elements
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> map[i][j];
                dist[i][j] = 0;
            }
        }
        //search
        bool wayOut = false;
        queue <pair<int,int>> que;
        que.push(make_pair(0,0));
        dist[0][0] = 1;
        //start the loop
        pair<int,int> cur;
        while(que.size() > 0){
            cur = que.front();
            int cc = dist[cur.first][cur.second];
            que.pop();
            //did we reach the end?
            if(cur.first == r-1 and cur.second == c-1){
                cout << cc << endl;
                wayOut = true;
                break;
            }
            //what are the adj vertices of cur that can be visited?
            if(map[cur.first][cur.second] == '+'){
                //any direction
                //bottom one
                if(map[cur.first+1][cur.second] != '*' and cur.first+1 < r){
                        que.push(make_pair(cur.first+1, cur.second));
                        dist[cur.first+1][cur.second] = cc+1;
                }
                //top one
                if(map[cur.first-1][cur.second] != '*' and cur.first > 0){
                        que.push(make_pair(cur.first-1, cur.second));
                        dist[cur.first-1][cur.second] = cc+1;
                }
                //left one
                if(map[cur.first][cur.second-1] != '*' and cur.second > 0){
                        que.push(make_pair(cur.first, cur.second-1));
                        dist[cur.first][cur.second-1] = cc+1;
                }
                //right one
                if(map[cur.first][cur.second+1] != '*' and cur.second+1 < c){
                        que.push(make_pair(cur.first, cur.second+1));
                        dist[cur.first][cur.second+1] = cc+1;
                }
                
            }else if(map[cur.first][cur.second] == '-'){
               
               //left right
                
                //left one
                if(map[cur.first][cur.second-1] != '*' and cur.second > 0){
                        que.push(make_pair(cur.first, cur.second-1));
                        dist[cur.first][cur.second-1] = cc+1;
                }
                //right one
                if(map[cur.first][cur.second+1] != '*' and cur.second+1 < c){
                        que.push(make_pair(cur.first, cur.second+1));
                        dist[cur.first][cur.second+1] = cc+1;
                }
                
            }else if(map[cur.first][cur.second] == '|'){
                //top bottom
                
                //bottom one
                if(map[cur.first+1][cur.second] != '*' and cur.first+1 < r){
                        que.push(make_pair(cur.first+1, cur.second));
                        dist[cur.first+1][cur.second] = cc+1;
                }
                //top one
                if(map[cur.first-1][cur.second] != '*' and cur.first > 0){
                        que.push(make_pair(cur.first-1, cur.second));
                        dist[cur.first-1][cur.second] = cc+1;
                }
            }
            //cur is now visited and should not be visited again
            map[cur.first][cur.second] = '*';
            //loop will now run again for the new vertcies
        }
        //if there is no way to exit
        if(wayOut == false){
            cout << -1 << endl;
        }
        while(!que.empty()) que.pop();
     //next text case beings afte rthis bracket
    }
    return 0;
}
