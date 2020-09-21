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
    public:
    Character(){
        root = NULL;
        temp = NULL;
        newc = NULL ;
        }
    Character(const char ch[]){
        root = NULL;
        temp=NULL;
        newc=NULL;
        int i =0;
        printf("hi");
        while(ch[i]!='\0'){
            printf("i");
            insert(ch[i]);
            i++;
            }
            }
    void insert(char c);
    void display();
    int  length();
    Char* substring(int beg,int end);
    bool compare(Character second); 
    };
void Character::insert(char c){
        newc = new Char;
        newc->ch = c;
        newc->next =NULL;
        if(root==NULL){
            root = newc;
            }
        else{
                temp = root;
                while(temp->next!=NULL){
                        temp = temp->next;
                    }
                temp->next = newc;
            }

    }

void Character::display(){

        temp = root;
        printf("\n");
        while(temp!=NULL)
        {
            printf("%c",temp->ch);
            temp = temp->next;
            }
    }
int Character :: length(){
        int len;
        printf("len");
        temp = root;
        while(temp!=NULL){
            len++;
            }
            return len;
    }
bool Character :: compare(Character second){
    cout<<"hi\n";
        int len = length();
        int length2 = second.length();
        if(len == length2){
            return true;}
        return false;
    }
//main
        int main(){
            char ch;
            Character input;
            while((ch=getchar())!='\n'){
                    input.insert(ch);
                }
                input.display();
            return 0;
            }

