#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(i=0;i<n;++i)
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()

int i, j;
struct R{
  int bonus;
  string name,type;
  R(){}
  R(int b,string n,string t):bonus(b),name(n),type(t){}
  bool operator<(const R &r)const{
    return bonus>r.bonus;
  }
};
struct I{
  int atk,def,res,size;
  string name,cls;
  I(){}
  I(int a,int d,int r,int s,string n,string c):
    atk(a),def(d),res(r),size(s),name(n),cls(c){}
  vector<R> rs;
};
I item[100];
R resi[1000];
vector<R> gs,ss,ps;
int n,k;
void pv(int p){
  cout<<item[p].name<<" "<<item[p].rs.size();
  rep(i,item[p].rs.size())cout<<" "<<item[p].rs[i].name;
  cout<<endl;
}
void run(){
  cin>>n;
  int sum=0;
  rep(i,n){
    int a,d,r,s;
    string n,c;
    cin>>n>>c>>a>>d>>r>>s;
    item[i]=I(a,d,r,s,n,c);
    sum+=s;
  }
  cin>>k;
  rep(i,k){
    int b;
    string nm,t,h;
    cin>>nm>>t>>b>>h;
    resi[i]=R(b,nm,t);
    rep(j,n)if(item[j].name==h)item[j].rs.pb(resi[i]);
    if(t[0]=='g')gs.pb(resi[i]);
    else if(t[0]=='s')ss.pb(resi[i]);
    else ps.pb(resi[i]);
  }
  if(sum==k){
    int mxw,mxa,mxo;
    int w=-1,a=-1,o=-1;
    rep(i,n)if(item[i].cls[0]=='w'){
      int s=item[i].atk;
      rep(j,item[i].rs.size())if(item[i].rs[j].type[0]=='g')
        s+=item[i].rs[j].bonus;
      if(s>w)w=s, mxw=i;
    }
    else if(item[i].cls[0]=='a'){
      int s=item[i].def;
      rep(j,item[i].rs.size())if(item[i].rs[j].type[0]=='s')
        s+=item[i].rs[j].bonus;
      if(s>a)a=s, mxa=i;
    }
    else if(item[i].cls[0]=='o'){
      int s=item[i].res;
      rep(j,item[i].rs.size())if(item[i].rs[j].type[0]=='p')
        s+=item[i].rs[j].bonus;
      if(s>o)o=s, mxo=i;
    }
    pv(mxw); pv(mxa); pv(mxo);
    return;
  }
  sort(all(gs)); sort(all(ss)); sort(all(ps));
  //cerr<<gs.size()<<" "<<ss.size()<<" "<<ps.size()<<endl;
  rep(i,n)item[i].rs.clear();
  int mxw,mxa,mxo,w=-1,a=-1,o=-1;
  rep(i,n)if(item[i].cls[0]=='w'){
    int s=item[i].atk;
    rep(j,min(item[i].size,(int)gs.size()))s+=gs[j].bonus;
    if(s>w)w=s, mxw=i;
  }
  else if(item[i].cls[0]=='a'){
    int s=item[i].def;
    rep(j,min(item[i].size,(int)ss.size()))s+=ss[j].bonus;
    if(s>a)a=s, mxa=i;
  }
  else if(item[i].cls[0]=='o'){
    int s=item[i].res;
    rep(j,min(item[i].size,(int)ps.size()))s+=ps[j].bonus;
    if(s>o)o=s, mxo=i;
  }
  rep(i,min(item[mxw].size,(int)gs.size()))item[mxw].rs.pb(gs[i]);
  rep(i,min(item[mxa].size,(int)ss.size()))item[mxa].rs.pb(ss[i]);
  rep(i,min(item[mxo].size,(int)ps.size()))item[mxo].rs.pb(ps[i]);
  vector<R> v;
  for(int i=min(item[mxw].size,(int)gs.size());i<gs.size();i++)v.pb(gs[i]);
  for(int i=min(item[mxa].size,(int)ss.size());i<ss.size();i++)v.pb(ss[i]);
  for(int i=min(item[mxo].size,(int)ps.size());i<ps.size();i++)v.pb(ps[i]);
  int k=0;
  while(k<v.size()&&item[mxw].rs.size()<item[mxw].size)item[mxw].rs.pb(v[k++]);
  while(k<v.size()&&item[mxa].rs.size()<item[mxa].size)item[mxa].rs.pb(v[k++]);
  while(k<v.size()&&item[mxo].rs.size()<item[mxo].size)item[mxo].rs.pb(v[k++]);
  pv(mxw); pv(mxa); pv(mxo);
}

int main()
{
	run();
	return 0;
}
