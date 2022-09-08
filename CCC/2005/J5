//
//  main.cpp
//  Bananas
//
//  Created by Gloria L on 2022-06-22.
//

#include <iostream>
#include <string>
using namespace std;

bool rec(string cur){
    string newStr;
    if(cur.length() == 1){
        if(cur == "A"){
            return true;
        }else{
            return false;
        }
    }
    if(cur[0] == 'A'){
        if(cur[1] == 'N'){
            newStr = cur.erase(0,2);
            return rec(newStr);
        }else{
            return false;
        }
       
    }else if(cur[0] == 'B'){
        //find next S
        int xp = 1;
        int bNb = 1;
        bool foundS = false;
        for(int i = 1; i <= (int) cur.length();i++){
            if(cur[i] == 'S'){
                bNb--;
                if(bNb == 0){
                    foundS = true;
                    xp = i;
                    i = (int) cur.length();
                }
            }else if(cur[i] == 'B'){
                bNb++;
            }
        }
        if(foundS == true){
            newStr = cur;
            //cout << xp << endl;
            newStr.erase(xp);
            newStr.erase(0,1);
          //  cout << newStr  << "." << endl;
            if(rec(newStr) == true){
                if(cur[xp+1] == 'N'){
                    cur = cur.substr(xp+2);
                }else{
                    if(cur.length() > xp+1){
                        return false;
                    }
                    //cout << newStr << endl;
                    cur = cur.substr(xp+1);
                }
                if(cur.length() >= 1){
                    return rec(cur);
                }else{
                    return true;
                }
            }else{
            return false;
            }
        }else{
            return false;
        }
    }
    return false;
}
// BBS

int main(int argc, const char * argv[]) {
    string cur;
    while (true){
        cin >> cur;
        if(cur == "X"){
            break;
        }else{
            if(rec(cur) == true){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
