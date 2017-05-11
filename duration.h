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

const duration_t operator+(const duration_t& dur_x, const duration_t& dur_y);
const duration_t operator-(const duration_t& dur_x, const duration_t& dur_y);
const duration_t operator-(const duration_t& dur_in);
const duration_t operator*(const duration_t& dur_x, const duration_t& dur_y);
duration_t& operator+=(const duration_t& rhs);
duration_t& operator-=(const duration_t& rhs);
duration_t& operator*=(const duration_t& rhs);