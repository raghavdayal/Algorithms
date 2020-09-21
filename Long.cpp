#include<iostream>
#include<stdio.h>
using namespace std;
class Char{
    public:
    char ch;
    Char* next;
    };
class Character{
    protected:
    Char *root;
    Char * temp;
    Char * newc;
    Char * last;
    public:
    Character(){
        root = NULL;
        temp = NULL;
        newc = NULL;
        last = NULL;
        }
    void insert(char c);
    void display();
    int  length();
    char first();
    char last_c();
    };

void Character::insert(char c){
        newc = new Char;
        newc->ch = c;
        newc->next =NULL;
        if(root==NULL){
            root = newc;
            last = root;
            }
        else{
                temp = root;
                while(temp->next!=NULL){
                        temp = temp->next;
                    }
                temp->next = newc;
                last = newc;
            }
    }

void Character::display(){
        temp = root;
        while(temp!=NULL)
        {   
            printf("%c",temp->ch);
            temp = temp->next;
            }
            cout<<"\n";
    }
int Character :: length(){
        int len=0;
        temp = root;
        while(temp!=NULL){
            len++;
            temp = temp->next;
            }
            return len;
    }
char Character :: first(){
    return root->ch;
    }
char Character :: last_c(){
    return last->ch;}
//main
        int main(){
            char ch;
            int t;
            scanf("%d\n",&t);
            Character input[t];
            for(int i =0;i<t;i++){
            while((ch = getchar())!='\n'){
                    input[i].insert(ch);}
            int len = input[i].length();
            if(len<=10){
                input[i].display();
                }
                else{
                    printf("%c%d%c\n",input[i].first(),len-2,input[i].last_c());
                    }
            }
            return 0;
            }
