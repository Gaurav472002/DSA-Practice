#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank,parent,size;

    // public:

        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int ele){

            if(ele==parent[ele]){
                return ele;
            }
            return parent[ele]= findParent(parent[ele]); // path compression technique
        }

        void unionByRank(int u, int v){

            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u==ulp_v){
                return;
            }
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                // ranks are same
                // we will attach u to v
                 parent[ulp_u]=ulp_v;
                 rank[ulp_v]++;// increase the rank
            }
        }



        void unionBySize(int u, int v){

            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u==ulp_v){
                return;
            }
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+= size[ulp_u];
            }
           
            else{
                
                 parent[ulp_v]=ulp_u;
                size[ulp_u]+= size[ulp_v];
            }
        }

};

int main(){

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    
    ds.unionBySize(3,7);
    if(ds.findParent(1)==ds.findParent(7)){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }

    cout<<ds.size[4];


    return 0;
}