//
//  main.cpp
//  StrategicBombing
//solved
//  Created by Gloria L on 2022-06-26.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool bfs(map<string, vector<string>> adjList, string removed){
    vector<string> visited;
    queue <string> que;
    que.push("A");
    while(que.size() != 0){
        //cout << que.size() << endl;
        string cur = que.front();
        if(cur == "B"){
            return true;
        }
        visited.push_back(cur);
        que.pop();
        //ietrate throughe ach adjcant node
        //all roads are from cur to j
        for(auto elem: adjList[cur]){
            //cout << elem << " " << cur << endl;
            
            if(count(visited.begin(), visited.end(), elem)){
                
            }else{
                if(cur+elem != removed && elem+cur != removed){
                    que.push(elem);
                }
            }
        }
        
        
    }
    return false;
}


int main() {
    map<string, vector<string>> adjList;
    vector<string> roads;
    string in;
    string s,e;
    while(true){
        cin >> in;
        if(in == "**"){
            break;
        }
        s = in.substr(0,1);
        e = in.substr(1,1);
        string se = s+e;
        roads.push_back(se);
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }
    
    int count = 0;
    //iterate thriugh all roads and remov dthem
    for(int i = 0; i < (int) roads.size(); i++){
        string remove = roads.at(i);
                //BFS TIME!
        if(bfs(adjList, remove) == false){
            //  we found a disconnectig road
            cout << remove << endl;
            count++;
        }
    }
    cout <<"There are "<< count  << " disconnecting roads."<< endl;
    return 0;
}
