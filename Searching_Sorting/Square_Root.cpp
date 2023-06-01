#include <bits/stdc++.h>
using namespace std;

double binarySearchSqrt(double x, double epsilon) {
    double low = 0, high = x;

    while (high - low > epsilon) {
        double mid = (low + high) / 2.0;
        if (mid * mid > x)high = mid;
        else low = mid;
    }
    return (low + high) / 2.0;
}
int main() {
    double x;
    cin >> x;
    double epsilon = 0.00001;
    double sqrtX = binarySearchSqrt(x, epsilon);
    cout <<  sqrtX << endl;
    return 0;
}
