#ifndef ABC_H
#define ABC_H
#include "operations.h"

inline int positive_modulo(int i, int n);

string to_string(note_t note, char key_note = 'c');

string to_string(melody_t melody, char key_note = 'c');

//void write_piece_stream(ostream& outs, char key_note, piece_t piece);
#endif