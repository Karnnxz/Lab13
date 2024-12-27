#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]) {
    double Sum = 0, SumSQ = 0, Total = 1, Harmonic = 0;
    double Max = numeric_limits<double>::lowest();
    double Min = numeric_limits<double>::max();

    for (int i = 0; i < N; i++) {
        Sum += A[i];
        SumSQ += A[i] * A[i];
        Total *= A[i];
        Harmonic += 1.0 / A[i];
        if (A[i] > Max) Max = A[i];
        if (A[i] < Min) Min = A[i];
    }
    
    B[0] = Sum / N;
    
    double Mean = B[0];
    B[1] = sqrt((SumSQ / N) - pow(Mean, 2));

    if (N > 0 && Total > 0)
        B[2] = pow(Total, 1.0 / N);
    else
        B[2] = 0;

    if (Harmonic > 0)
        B[3] = N / Harmonic;
    else
        B[3] = 0;

    B[4] = Max;
    B[5] = Min;
}