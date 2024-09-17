#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
     vector<vector<int>>matrix(5, vector<int>(5, 0));
     int one_row=0, one_col=0;
     for(int i=0; i<5; i++){
          for(int j=0; j<5; j++){
               cin>>matrix[i][j];
               if(matrix[i][j]==1){
                    one_row=i+1;
                    one_col=j+1;
               }
        }
    }
    //calculate the manhatten distance
    int distance=abs(one_row-3)+abs(one_col-3);      
    cout<<distance<<endl;
}