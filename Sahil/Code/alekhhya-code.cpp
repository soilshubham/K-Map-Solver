#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

void g8(int* a[], vector<int>* b, vector<int>* c){

    int flag = 0;
    

    //grp i
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 3){
                b->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }

    //grp8 j
    for (int j=0; j<4 ; j++){
        for (int i=0; i<4; i++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 3){
                c->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }
}

int main (){
    vector<int> grp8_i, grp8_j;
    int x[4][4] = {{1,1,1,1}, {1,1,1,1}, {0,0,0,0},{0,0,0,0}};
}
