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



void g4(int* a[], vector<int>* b, vector<int>* c){

    int flag = 0;
    

    //grp square
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 1){
                b->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }
    
    //grp vertical line
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 or a[(i+1)%4][j%4]==1 ) {
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
    
    
    //grp horizontal line
    for (int j=0; j<4 ; j++){
        for (int i=0; i<4; i++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 or a[(i+1)%4][j%4]==1 ) {
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
    
}

// for 4s
    // if they r in square shape, the code is same as 8s but flag ==1 and we can use either grp_i or grp_j
    // if they r in vertical line, the code is same as 2s but flag == 3 and i for loop is followed by j for loop
    // if they r in vertical line, the code is same as 2s but flag == 3 and j for loop is followed by i for loop










void g2(int a[][4], std::vector<std::vector<int>>* grp2){

    int flag = 0;
    std::vector<int> grp;

    //grp i
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1) {
                    grp.push_back(10*(i%4) + abs(j - 2)%4);
                    grp.push_back(10*(i%4) + abs((j+1) - 2)%4);
                    
                }
                if (a[(i+1)%4][j%4]==1 ) {
                    grp.push_back(10*((i- 2)%4) + abs(j)%4);
                    grp.push_back(10*((i+1- 2)%4) + abs(j)%4);
                    
                }
                else {
                    break;
                }
            }
        }
    }
}










int main (){
    vector<int> grp8_i, grp8_j;
    int x[4][4] = {{1,1,1,1}, {1,1,1,1}, {0,0,0,0},{0,0,0,0}};
}





