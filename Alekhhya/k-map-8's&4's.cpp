#include<iostream>
#include<string.h>
#include<vector>
#include<map>

int main (){
    int x[4][4] = {{0,1,0,0}, {1,1,1,1}, {0,1,0,1},{0,1,1,0}};
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if x[i+1][j]==1 or x[i][j+1]==1 or (x[i+1][j]==1 and x[i][j+1]==1){
                
            }
        }
    }
}
