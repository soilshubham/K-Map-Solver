#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

int main (){
    int flag = 0;
    int x[4][4] = {{1,1,1,1}, {1,1,1,1}, {0,0,0,0},{0,0,0,0}};
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (x[i][j]==1) {
                if (x[i%4][(j+1)%4]==1 and x[(i+1)%4][j%4]==1 and x[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
            }
            if (flag == 3){
                cout<< 8 ;
            }
        }
    }
}
