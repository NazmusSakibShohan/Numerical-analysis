#include<bits/stdc++.h>
using namespace std;

int n;
float x[20][20];
float y[20][20];

float p_cal_serise(float p, int n) {
        float result = p;
        for (int i = 1; i < n; i++)
        {
            result *= (p - i);
        }
        return result;
}

float q_cal_serise(float q, int n) {
        float result = q;
        for (int i = 1; i < n; i++)
        {
            result *= (q + i);
        }
        return result;
}

int fact(int n) {
        int a = 1;
        for (int i = 2; i <= n; i++)
        {
            a *= i;
        }
        return a;
}

void Forward()
{
    // Calculation for forward differences
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Displaying the forward difference table

    cout <<endl<< "Forward Difference Table:"<<endl;
    for (int i = 0; i < n; i++)
        {
        cout << x[i][0] << "\t";
        for (int j = 0; j < n - i; j++)
        {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    float value;
    cout<< endl;
    cout << "Enter the value to interpolate: ";
    cin >> value;
    float p = (value - x[0][0]) / (x[1][0] - x[0][0]);
    float sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        sum += (p_cal_serise(p, i) * y[0][i]) / fact(i);
    }

    cout << "The interpolated value at " << value << " is " << sum << endl;
}
void Backward()
{
   // Calculation for backward differences
    for (int i = 1; i < n; i++)
        {
        for (int j = n - 1; j >= i; j--)
        {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    // Displaying the backward difference table
    cout<<endl<< "Backward Difference Table:"<<endl;
    for (int i = 0; i < n; i++)
        {
        cout << x[i][0] << "\t";
        for (int j = 0; j <= i; j++)
        {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    float value;
    cout<< endl;
    cout << "Enter the value to interpolate: ";
    cin >> value;
    float q = (value - x[n - 1][0]) / (x[1][0] - x[0][0]);
    float sum = y[n - 1][0];

    for (int i = 1; i < n; i++)
    {
        sum += (q_cal_serise(q, i) * y[n - 1][i]) / fact(i);
    }

    cout << "The interpolated value at " << value << " is " << sum << endl;

}

int main() {
    cout << "Enter number of Inputs: ";
    cin >> n;
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i][0];
    }
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i][0];
    }
    Forward();
    Backward();
    return 0;
}
