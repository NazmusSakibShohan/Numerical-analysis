#include<bits/stdc++.h>
using namespace std;

float p_cal(float p, int n) {
    float result = p;
    for (int i = 1; i < n; i++) {
        result *= (p - i);
    }
    return result;
}

int fact(int n) {
    int a = 1;
    for (int i = 2; i <= n; i++) {
        a *= i;
    }
    return a;
}

int main() {
    int n;
    cout << "Enter number of inputs: ";
    cin >> n;
    float x[n][n];
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i][0];
    }

    float y[n][n];
    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i][0];
    }

    // Calculation for forward differences
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Displaying the forward difference table
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i][0] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << y[i][j] << "\t";
        }
        cout << endl;
    }

    float value;
    cout << "Enter the value to interpolate: ";
    cin >> value;
    float p = (value - x[0][0]) / (x[1][0] - x[0][0]);
    float sum = y[0][0];

    for (int i = 1; i < n; i++) {
        sum += (p_cal(p, i) * y[0][i]) / fact(i);
    }

    cout << "The interpolated value at " << value << " is " << sum << endl;
    return 0;
}
