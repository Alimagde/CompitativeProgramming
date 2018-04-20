#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int n,m;

pair<int,pair<int,int> >g[N];
pair<int,int> t[N];
int memo[N][N];
vector<pair<int,int> >vec;

int solve(int i,int j){
  if(i>=n || j>=m) return 0;
  int &r=memo[i][j];
  if(~r) return r;
  r=0;
  if(g[i].first>t[j].first){
    return r=solve(i,j+1);
  }

  r=max(r,solve(i+1,j));
  r=max(r,solve(i,j+1));
  r=max(r,solve(i+1,j+1)+g[i].second.first);
  return r;
}

void getans(int i,int j){
  if(i>=n || j>=m) return;
  int r=memo[i][j];
  if(g[i].first>t[j].first){
    getans(i,j+1);
    return;
  }

  if(solve(i+1,j)==r){
    getans(i+1,j);
  }
  else if(solve(i,j+1)==r){
    getans(i,j+1);
  }
  else{
    vec.push_back(make_pair(g[i].second.second,t[j].second));
    getans(i+1,j+1);
  }

}


int main() {

  scanf("%d",&n);
  int c,v;
  for(int i=0;i<n;++i){
    scanf("%d %d",&c,&v);
    g[i]=make_pair(c,make_pair(v,i+1));
  }
  scanf("%d",&m);
  for(int i=0;i<m;++i){
    scanf("%d",&c);
    t[i]=make_pair(c,i+1);
  }
  sort(g,g+n);
  sort(t,t+m);
  memset(memo,-1,sizeof memo);

  int ans=solve(0,0);
  getans(0,0);
  printf("%d %d\n",(int)vec.size(),ans);
  for(auto x:vec){
    printf("%d %d\n",x.first,x.second);
  }
}
