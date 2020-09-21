#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{char c;
int j =1;
int ind=0;
string arr("g++ ");
char str[100];
system("ls *.cpp | cat > c++programs.txt");
FILE *fp = fopen("./c++programs.txt","r"); 
if(fp==NULL){cout<<"bye";}
while(fscanf(fp, "%s", str)!=EOF)
{ 
ind++;
string st = string(arr + str+" -o output"+to_string(ind));
cout<<st<<"\n";
system(st.c_str());
}
fclose(fp);
}
