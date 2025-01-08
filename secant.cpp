#include<bits/stdc++.h>
using namespace std;
#define ep 0.0001

int co_A,co_B,co_C,co_D;

double f(double x)
{
    return co_A*pow(x,3)+co_B*pow(x,2)+co_C*x+co_D;
}
void secant(double x0,double x1)
{
    if( (x0>x1) || (f(x0)*f(x1)>=0))
    {
        cout<<"not right x0 and x1"<<endl;
    }

    else
   {
    double x2;
    int iteration=0;
    while(true)
    {
        iteration++;
        x2=x1-(f(x1)*((x1-x0)/(f(x1)-f(x0))));
        if(fabs(f(x2))<=ep)
        {
            break;
        }

        else
        {
            x0=x1;
            x1=x2;
        }

    }
   cout<<"root= "<<x2<<endl;
   cout<<"iteration= "<<iteration<<endl;
  }
}

int main() {
   cout<<"enter ther Coefficient (A,B,C,D)For equation Ax^3+Bx^2+Cx+D=0 : ";
    cin>>co_A>>co_B>>co_C>>co_D;
    double x0,x1;
    cout<<"enter x0 and x1=";
    cin>>x0>>x1;
    secant(x0,x1);
    return 0;
}
