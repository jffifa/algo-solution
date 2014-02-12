/*
	Problem: Ural1046
	Algorithm: Geometry, Complex Field Equation
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 100;
const double PI = acos((double)-1);

inline double Deg2Rad(double d)
{return PI*d/180;}

int N;
double Mx[MaxN], My[MaxN], Ax[MaxN], Ay[MaxN], Theta[MaxN], ThSum[MaxN], Re, Im, Homura, Madoka, Mami, Kyouko, Sayaka;

int main()
{
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lf%lf", &Mx[i], &My[i]);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &Theta[i]);
		Theta[i] = Deg2Rad(Theta[i]);
	}
	ThSum[N] = 0;
	for (int i = N-1; i >= 0; --i)
		ThSum[i] = ThSum[i+1]+Theta[i];
	for (int i = 0; i < N; ++i)
	{
		Re += cos(ThSum[i+1])*Mx[i]-sin(ThSum[i+1])*My[i];
		Re -= cos(ThSum[i])*Mx[i]-sin(ThSum[i])*My[i];
		Im += cos(ThSum[i+1])*My[i]+sin(ThSum[i+1])*Mx[i];
		Im -= cos(ThSum[i])*My[i]+sin(ThSum[i])*Mx[i];
	}
	
	Madoka = 1-cos(ThSum[0]);
	Homura = sin(ThSum[0]);
	//printf("%lf %lf %lf %lf\n", Re, Im, Madoka, Homura);
	Mami = Madoka*Madoka+Homura*Homura;
	Ax[0] = (Re*Madoka-Im*Homura)/Mami;
	Ay[0] = (Im*Madoka+Re*Homura)/Mami;
	//printf("%.2lf %.2lf\n", Ax[0], Ay[0]);
	for (int i = 1; i < N; ++i)
	{
		Kyouko = Ax[i-1]-Mx[i-1];
		Sayaka = Ay[i-1]-My[i-1];
		Madoka = cos(Theta[i-1]); Homura = sin(Theta[i-1]);
		Ax[i] = Kyouko*Madoka-Sayaka*Homura+Mx[i-1];
		Ay[i] = Kyouko*Homura+Sayaka*Madoka+My[i-1];
	}
	for (int i = 0; i < N; ++i)
		printf("%.2lf %.2lf\n", Ax[i], Ay[i]);
	return 0;
}
