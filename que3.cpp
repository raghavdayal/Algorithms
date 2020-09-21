#include<iostream>
#include<stdio.h>
int main(){
        int n;
        int que =0;
        int sum = 0;
        scanf("%d",&n);
        int ar[n][3];
        for(int i =0;i<n;i++){
                for(int j =0;j<3;j++){
                        scanf("%d",&ar[i][j]);
                    }
            }
        for(int i =0;i<n;i++){
            sum =0;
            for(int j=0;j<3;j++){
                    sum+=ar[i][j];
                }
                if(sum>=2){
                    que++;
                    }
            }
            printf("%d",que);
            return 0;
    }
