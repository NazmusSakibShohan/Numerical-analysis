#include<bits/stdc++.h>
using namespace std;
#define ep 0.0001

int co_A,co_B,co_C,co_D;

double f(double x)
{
    return co_A*pow(x,3)+co_B*pow(x,2)+co_C*x+co_D;
}

void bisection(double a,double b)
{
    if( (a>b) || (f(a)*f(b)>=0))
    {
        cout<<"not right a and b"<<endl;
    }

    else
    {
    double c;
    int iteration=0;
    while(true)
    {
        iteration++;
        c=(a+b)/2;
        if(fabs(f(c))<=ep)
        {
            break;
        }
        else if(f(a)*f(c)<0)
        {
            b=c;
        }
        else
        a=c;

    }
   cout<<"root= "<<c<<endl;
   cout<<"iteration= "<<iteration<<endl;
 }
}
int main() {
    cout<<"enter ther Coefficient (A,B,C,D)For equation Ax^3+Bx^2+Cx+D=0 : ";
    cin>>co_A>>co_B>>co_C>>co_D;
    double a,b;
    cout<<"enter a and b=";
    cin>>a>>b;
    bisection(a,b);
    return 0;
}
