/*
	Problem: Ural1175
	Algorithm: Hash
	Time: O()
	Memory: O()
	Detail: 
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
int table[100000][2];
int a1,a2,a3,a4,b1,b2,c;

int f(int x,int y)
{
    int z;
    z=a1*x*y+a2*x+a3*y+a4;
    if (z>b1)
    {
        z-=c;
        if (z>b2)
        {
            z-=(z-b2-1)/c*c+c;
        }
    }
    return z;
}

inline int hash(int x,int y)
{
    return (x*1577+y)%100000;
}

bool add(int x,int y)
{
    int s;
    
    for(s=hash(x,y);;(s?s--:s=99999))
    {
        if (table[s][0]==-1)
        {
            table[s][0]=x;
            table[s][1]=y;
            return true;
        }
        if (table[s][0]==x&&table[s][1]==y) return false;
    }
}

int main()
{
    int x,y,z;
    int x0,y0,t,s;
    
    scanf("%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&b1,&b2,&c);
    scanf("%d%d",&x0,&y0);
    x=x0;
    y=y0;
    t=1;
    memset(table,-1,sizeof(table));
    for(;;)
    {
        if (!add(x,y))
        {
            break;
        }
        z=f(x,y);
        x=y;
        y=z;
        t++;
    }
    s=1;
    while (x!=x0||y!=y0)
    {
        z=f(x0,y0);
        x0=y0;
        y0=z;
        s++;
    }
    printf("%d %d\n",s,t-s);
	return 0;
}
