#include <bits/stdc++.h>
using namespace std;

float slope(int x1,int y1,int x2,int y2)
{
    return static_cast<float>(y2-y1)/(x2-x1);
}
int main() {
    int x1,x2,y1,y2;
    cout<<"Enter the first point (x1,y1) = ";
    cin>>x1>>y1;
    cout<<"Enter the Second point (x2,y2) = ";
    cin>>x2>>y2;
    float x,y;
    cout<<"Enter the interpolation point 'x' = ";
    cin>>x;
    y=y1+(x-x1)*slope(x1,y1,x2,y2);
    cout<<"The Interpolated value at "<< x <<" is = "<<y<<endl;
    return 0;//SHOHAN
}

