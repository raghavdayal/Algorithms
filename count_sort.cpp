#include<iostream>
using namespace std;
int main(){
        int test;
        cin>>test;
        int count[10000];
        for(int k=0;k<test;k++){
        int N=0,B=0;
        int house =0;
        cin>>N>>B;
        int ar[N];
        int sort[N+1];
        for(int i =0;i<10000;i++){
            count[i]=0;}
        for(int i =0;i<N;i++){
                cin>>ar[i];
                count[ar[i]]++;
            }
        for(int i =0;i<9999;i++){
                count[i+1]+=count[i];
            }
        for(int i=0;i<N;i++){
                sort[count[ar[i]]] = ar[i];
                count[ar[i]]--;
            }
            cout<<"\n";
        for(int i =1;i<N+1;i++){
                cout<<sort[i]<<" ";
            }
            cout<<"\n";
        for(int i=1;i<N+1;i++){
            if(B-sort[i]<0){
                    break;
                }
            else{
                    B-=sort[i];
                    house++;
                }
            }
            cout<<"case# "<<k+1<<": "<<house;
        }

            return 0;
    }
