#ifndef DURATION_H
#define DURATION_H

#include <utility>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;
//silence is defined as negative 100

/*
Functions for operations on music
*/

/*enum freq_t{
    A, B, C, D, E, F, G
};*/

typedef int freq_t;

//Any duration can be written as K/2^n
typedef pair<int, int> duration_t;


long long int gcd(long long int u, long long int v);


const duration_t operator+(const duration_t& dur_x, const duration_t& dur_y);
const duration_t operator-(const duration_t& dur_x, const duration_t& dur_y);
const duration_t operator-(const duration_t& dur_in);
const duration_t operator*(const duration_t& dur_x, const duration_t& dur_y);
duration_t& operator+=(duration_t& dest, const duration_t& rhs);
duration_t& operator-=(duration_t& dest, const duration_t& rhs);
duration_t& operator*=(duration_t& dest, const duration_t& rhs);
duration_t simplify_duration(duration_t& dur);
#endif