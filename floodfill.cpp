#include<iostream>
#include<string>
#include<queue>
#include<climits>

using namespace std;

struct floodfill
{
    int value;
    bool northwall;
    bool southwall;
    bool eastwall;
    bool westwall;
};

// make array 16x16
floodfill maze[16][16];

// make a queue
queue<pair<int, int>> q;

// make a function to check if the cell is valid
bool isvalid(int x, int y){
    if(x>=0 && x<16 && y>=0 && y<16){
        return true;
    }
    return false;
}

int main(){
    
    return 0;
}