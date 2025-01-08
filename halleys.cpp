#include<bits/stdc++.h>
using namespace std;
#define ep 0.00001

int co_A,co_B,co_C,co_D;

double f(double x)
{
    return co_A*pow(x,3)+co_B*pow(x,2)+co_C*x+co_D;
}
double df(double x)
{
    return 3* co_A*pow(x,2)+2*co_B*x+co_C;
}
double ddf(double x)
{
    return 3*2* co_A*x+2*co_B;
}

void halleys(double a,double b)
{

    if((a>b) || (f(a)*f(b)>=0))
    {
        cout<<"not right a and b";
    }
    else{
        double x0,x1;
        x0=(a+b)/2;
        int  iteration=0;

        while(true)
        {
            iteration++;
            x1=x0-((2*f(x0)*df(x0))/((2*pow(df(x0),2))-(f(x0)*ddf(x0))));

            if(fabs(f(x1))<=ep)
            {
                break;
            }
            else{
                x0=x1;
            }
        }
        cout<<"root="<<x1<<endl;
        cout<<"iteration="<<iteration<<endl;
    }
}

int main()
{
    cout<<"enter ther Coefficient (A,B,C,D)For equation Ax^3+Bx^2+Cx+D=0 : ";
    cin>>co_A>>co_B>>co_C>>co_D;
    double a,b;
    cout<<"enter a and b=";
    cin>>a>>b;
    halleys(a,b);
    return 0;
}
