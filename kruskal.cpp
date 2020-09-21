#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<char,char>check;
class edges{
  public:
    int weight;
    char name;
    char parent;
    edges(){
      weight =0;
    }
    edges(int w,char n,char pn){
        weight = w;
        name = n;
        parent = pn;
    }
    int weight_get();
    int get_name();
    void display();
    };
    int edges:: weight_get(){
        return weight;
        }
    int edges:: get_name(){
        return name;}
    void edges:: display(){
            cout<<" ("<<parent<<","<<name<<","<<weight<<")";
        }
class vertices{
    public:
    char name;
    vector <edges> ar;
    vertices(char n){
            name = n;
        }
    };
class graph{
    protected:
    vector<vertices> nodes;
    public:
    void insert();
    vector<edges> clean();
    friend vector<edges> finalt(vector<edges>* ar);
    friend int find(char c1,char c2);
    friend void uni(char c1,char c2);
    };
void graph::insert(){
    char ch,ans='y';
    cout<<"Enter the vertex\n";
    cin>>ch;
    vertices v(ch);
    nodes.push_back(v);
    check[ch]=ch;
    cout<<"please enter it's edges along with weight\n";
    while(ans == 'y'){
        char che;
        int weight;
        cin>>che;
        cin>> weight;
        edges e(weight,che,ch);
        nodes[nodes.size()-1].ar.push_back(e);
        cout<<"do you want to add another edge\n";
        cin>>ans;
        }
    }
vector<edges> graph :: clean(){
        vector<edges>tmp;
        vector<edges> arr;
        for(int i =0;i<nodes.size();i++){
            for(int j =0;j<nodes[i].ar.size();j++){
                int alr = 0;
                    if(arr.empty()){
                        arr.push_back(nodes[i].ar[j]);}
                    else{
                        for(int k =0;k<arr.size()&&alr==0;k++){
                                if(arr[k].parent == nodes[i].ar[j].name&&arr[k].name==nodes[i].ar[j].parent){
                                        alr = 1;
                                    }        
                            }
                            if(alr==1){continue;}
                            else{
                                arr.push_back(nodes[i].ar[j]);}
                            }
                }
            }
    return arr;
}
int find(char c1,char c2){
    int ret = 0;
    int temp_c1 = check[c1];
    int temp_c2 = check[c2];
    if(temp_c1==temp_c2){
                    return 1;
                    }
    return ret;
    }
void uni(char c1,char c2){
    check[c2] = c1;
    }
void mergesort(vector<edges>*ar,int beg,int end){
if(beg>=end){
  return;
}
int mid = (end+beg)/2;
mergesort(ar,beg,mid);
mergesort(ar,mid+1,end);
vector<edges>left;
vector<edges> right;
  for(int i =0;i<(mid-beg)+1;i++){
    left.push_back((*ar)[i+beg]);
  }
  for(int j=0;j<(end-mid);j++){
    right.push_back((*ar)[j+mid+1]);
  }
  int i =0;int j =0; int k=beg;
  while(i<(mid-beg)+1&&j<end-mid){
    if(left[i].weight<=right[j].weight){
      (*ar)[k] = left[i];
      i++;
    }
    else{
      (*ar)[k] = right[j];
      j++;
    }
    k++;
  }
  if(i<mid-beg+1){
    while(i<(mid-beg)+1)
    {(*ar)[k] = left[i];
    i++;
    k++;}
  }
  else{
    while(j<end-mid)
    {(*ar)[k] = right[j];
    k++;
    j++;}
  }
}
vector<edges> finalt(vector<edges>* ar){
	vector<edges> fnal;
    int w =0;
        for(int i =0;fnal.size()<check.size()-1;i++){
                char c1 = (*ar)[i].parent;
                char c2 = (*ar)[i].name;
                int inst = find(c1,c2);
                if(inst==1){
                    continue;}
                else{
                     uni(c1,c2);
                     w+=(*ar)[i].weight;
                     fnal.push_back((*ar)[i]);   
                        }
            }
            cout<<"The total weight of the minimum spanning tree is: "<<w<<"\n";
           return fnal;
}

int main(){
  graph ar;
    char a ='y';
    while(a=='y'){
        ar.insert();
        cout<<"do you want to add another vertex\n";
        cin>>a; 
        }
    vector<edges> e = ar.clean();
    for(int i =0;i<e.size();i++){
            e[i].display();
}
cout<<"\n";
     mergesort(&e,0,e.size()-1);
     vector<edges>fnal = finalt(&e);
    for(int i =0;i<fnal.size();i++){
            fnal[i].display();
        }
        cout<<"\n";
    map<char,char> :: iterator p = check.begin();
    while(p!=check.end()){
            cout<<" "<<p->first<<","<<p->second;
            p++;
        }

    cout<<"\n";
    return 0;
    } 
