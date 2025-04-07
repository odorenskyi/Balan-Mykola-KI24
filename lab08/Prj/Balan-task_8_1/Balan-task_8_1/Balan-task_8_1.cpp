#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calculateS(double x, double y, double z) {
    double numerator = abs(z * z * exp(x));
    double denominator = 12 * x + (y * y - M_PI * sqrt(z));

    double result = x * x - pow(y, 3) + sqrt(numerator / denominator);
    return result;
}