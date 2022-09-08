#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;


void print(map <int,vector<int>> book, int target){
    for(auto it: book[target]){
        cout << "Node" << target << " is connected to node:" << it << endl;
    }
}

int bfs2(map <int,vector<int>> book, int pages, vector<int> ends){
    bool visited [pages+1];
    int dis [pages+1];
    dis[1] = 1;
    for(int i = 0; i < pages+1; i++){
        visited[i] = false;
    }
    queue <int> que;
    que.push(1);
    visited[1] = true;
    while(que.size() > 0){
        int cur = que.front();
        if(cur == 3){
           // cout << "3" << visited[3] << " " << cur << endl;
        }
        
        que.pop();
        if(find(ends.begin(), ends.end(), cur) != ends.end()) {
            return dis[cur];
        }else{
            for(auto it: book[cur]){
                if(visited[it] != true && it != cur){
                    que.push(it);
                    dis[it] = dis[cur]+1;
                    visited[it] = true;
                    //cout << cur << " dis: " << dis[cur] << " new node: " << it << " new dis: " << dis[it] << endl;
                }
            }
        }
    }
    return 0;
}

bool bfs(map <int,vector<int>> book, int pages){
    bool visited [pages+1];
    for(int i = 0; i < pages; i++){
        visited[i] = false;
    }
    queue <int> que;
    que.push(1);
    while(que.size() > 0){
        int cur = que.front();
        visited[cur] = true;
        que.pop();
        bool allreached = true;
        for(int i = 1; i < pages; i++){
            if(visited[i] != true){
                allreached = false;
            }
        }
        if(allreached == true){
            return true;
        }
        
        // goes through all the adj nodes to the current node
        for(auto it: book[cur]){
            if(visited[it] != true){
                que.push(it);
                //cout << it << endl;
            }else{
              //  print(book, cur);
            }
        }
    }
    return false;
}

bool connected (vector<bool> reachable){
    for(auto i: reachable){
        if(i != true){
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    int pages, x, y;
    cin >> pages;
    map <int,vector<int>> book;
    vector<int> endp;
    vector<bool> reachable;
    //lines
    for(int i = 0; i < pages; i++){
        cin >> x;
        //each line
        for(int j = 0; j < x; j++){
            cin >> y;
            book[i+1].push_back(y);
        }
        if(x == 0){
            endp.push_back(i+1);
        }
    }
    
    if(bfs(book, pages) == true){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    cout << bfs2(book, pages, endp) << endl;
    return 0;
}
