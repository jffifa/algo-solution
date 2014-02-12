/*
	Problem: Ural1050
	Algorithm: String
	Time: O()
	Memory: O()
	Detail: Orz
	Coded by [BUPT]AkemiHomura
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

string ans,tmp;
char s[300];
char t[]="\\endinput";

int main()
{
	int i;
	bool end=false;int left=0;
	while(gets(s))
	{
		if(s[0]=='\\')
		{
			for(i=0;i<strlen(s)&&i<strlen(t);i++)
			{
				if(s[i]!=t[i])break;
			}
			if(i>=strlen(t))
			{
				printf("%s%s\n",ans.c_str(),tmp.c_str());
				printf("%s\n",s);
				ans="";tmp="";left=0;end=true;
				break;
			}
		}
		if(strcmp(s,"")==0)
		{
			if(ans!=""||tmp!="")
				printf("%s%s\n\n",ans.c_str(),tmp.c_str());
			else
				printf("\n");
			ans="";tmp="";left=0;end=true;
		}
		else
		{
			if(!end)
				tmp+='\n';
			end=false;
			int n=strlen(s);
			for(i=0;i<n;i++)
			{
				if(s[i]=='\\')
				{
					if(i<n&&s[i+1]==34)
					{
						tmp+=s[i++];
						tmp+=s[i];
					}
					else
					{
						if(i+3<n&&s[i+1]=='p'&&s[i+2]=='a'&&s[i+3]=='r')
						{
							tmp+="\\par";
							ans+=tmp;tmp="";i+=3;left=0;end=true;
						}
						else
							tmp+=s[i];
					}
				}
				else if(s[i]==34)
				{
					if(left)
					{
						ans+="``"+tmp+"''";tmp="";
						left--;
					}
					else
					{
						ans+=tmp;tmp="";
						left++;
					}
				}
				else
				{
					tmp+=s[i];
				}
			}
		}
	}
	return 0;
}