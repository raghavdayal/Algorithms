#include<iostream>
#include<stdio.h>
using namespace std;
class fibo{
    protected:
        int sum;
        int *ar;
    public:
        fibo(int a[]){
                ar = a;
                sum = 0;
            }
        int compute(int n){
                if(ar[n]!=0){
                    return ar[n];}
                if(n==1 || n==2){
                    ar[n]=1;
                    return 1;}    
                sum= compute(n-1)+compute(n-2);
                ar[n]=sum;
                return sum;
            }
    };
    int main(){
            int n;
            scanf("%d",&n);
            int a[n+1];
            for(int i =0;i<n+1;i++){
                a[i]=0;
                }
            fibo f(a);
            printf("The fibonacci number at %d is %d",n,f.compute(n));
            return 0;
        }
