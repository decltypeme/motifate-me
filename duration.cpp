#include "duration.h"

long long int gcd(long long int u, long long int v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

const duration_t operator+(const duration_t& dur_x, const duration_t& dur_y){
    long long k = (1<<dur_y.second) * dur_x.first + (1<<dur_x.second) * dur_y.first;
    long long n = (dur_x.first + dur_x.second);
    duration_t temp = make_pair(k,n);
    return simplify_duration(temp);
}
const duration_t operator-(const duration_t& dur_x, const duration_t& dur_y){
    return dur_x + (-dur_y);
}
const duration_t operator-(const duration_t& dur_in){
    return make_pair(-dur_in.first, dur_in.second);
}
const duration_t operator*(const duration_t& dur_x, const duration_t& dur_y){
    return make_pair(dur_x.first * dur_x.first, dur_x.second + dur_y.second);
}
duration_t& operator+=(duration_t& dest, const duration_t& rhs){
    dest = dest + rhs;
    return dest;
}
duration_t& operator-=(duration_t& dest, const duration_t& rhs){
    return operator-=(dest, -rhs);
}
duration_t& operator*=(duration_t& dest, const duration_t& rhs){
    dest = dest * rhs;
    return dest;
}

duration_t simplify_duration(duration_t& dur){
    long long int num   = dur.first;
    long long int denom = (long long int)(1) << dur.second;
    long long int d     = gcd(num, denom);
    num                 /= d;
    denom               /= d;
    dur = make_pair(num, log2(denom));
    return dur;
}