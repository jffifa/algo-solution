/*
	Problem: Ural1075
	Algorithm: Geometry
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 100;
const double EPS = 1e-6;

inline int DBLCMP(double d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct SPoint
{
	double x, y, z;
	SPoint() {}
	SPoint(double X, double Y, double Z): x(X), y(Y), z(Z) {} 
};

double Dis(SPoint &P1, SPoint &P2)
{
	double dx = P1.x-P2.x;
	double dy = P1.y-P2.y;
	double dz = P1.z-P2.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}

SPoint A, B, O;
double R, OA, OB, AB;

double Calc()
{
	OA = Dis(A, O);
	OB = Dis(B, O);
	AB = Dis(A, B);
	double AS = sqrt(OA*OA-R*R);
	double BT = sqrt(OB*OB-R*R);
	if (DBLCMP(AS+BT-AB) >= 0) return AB;
	double angAOS = acos(R/OA);
	double angBOT = acos(R/OB);
	double angAOB = acos((OA*OA+OB*OB-AB*AB)/(2*OA*OB));
	double angSOT = angAOB-angAOS-angBOT;
	double arcSOT = R*angSOT;
	return AS+BT+arcSOT;
}

int main()
{
	scanf("%lf%lf%lf", &A.x, &A.y, &A.z);
	scanf("%lf%lf%lf", &B.x, &B.y, &B.z);
	scanf("%lf%lf%lf", &O.x, &O.y, &O.z);
	scanf("%lf", &R);
	printf("%.2f\n", Calc());
	return 0;
}
