#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows=0,cols=0;
    cin>>rows>>cols;
    int matrix[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    int c=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=-1){
                c++;
            }
        }
    }
    int points[c][3];
    int i1=0;int j1=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=-1){
                points[i1][j1]=matrix[i][j];
                points[i1][j1+1]=i;
                points[i1][j1+2]=j;
                i1++;j1=0;
            }
        }
    }
    cout<<"The nodes alongwith coordinates are"<<endl;
    for(int i=0;i<c;i++){
        for(int j=0;j<3;j++){
            cout<<points[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The distances between points are"<<endl;
    int graph[c][c];
    int distance=0;
    int distance_matrix[1][3];
    int i2=0,j2=0;
    int x1=0,x2=0,y1=0,y2=0;
    int x_diff=0,y_diff=0;
    for(int i=0;i<c;i++){
        for(int j=i+1;j<c;j++){
               x1=points[i][1];
               x2=points[j][1];
               y1=points[i][2];
               y2=points[j][2];
               y_diff=(y2-y1)*(y2-y1);
               x_diff=(x2-x1)*(x2-x1);
               distance=ceil(sqrt(x_diff+y_diff));
               distance_matrix[i2][j2]=points[i][0];
               distance_matrix[i2][j2+1]=points[j][0];
               distance_matrix[i2][j2+2]=distance;
               i2++;j2=0;
        }
    }
    for(int i=0;i<1;i++){
        for(int j=0;j<3;j++){
            cout<<distance_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}

