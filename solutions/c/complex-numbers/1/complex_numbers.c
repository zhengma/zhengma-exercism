#include <math.h>
#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t result = {a.real + b.real, a.imag + b.imag};
    return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t result = {a.real - b.real, a.imag - b.imag};
    return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t result = {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
    return result;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t result = c_mul(a, c_conjugate(b));
    double modsquare = b.real * b.real + b.imag * b.imag;
    result.real /= modsquare;
    result.imag /= modsquare;
    return result;
}

double c_abs(complex_t x)
{
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
    complex_t result = {x.real, -x.imag};
    return result;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    double real = exp(x.real);
    complex_t result = {real * cos(x.imag), real * sin(x.imag)};
    return result;
}
