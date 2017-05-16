#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "duration.h"

using namespace std;




//A note is defind by frequency and duration
struct note_t{
    freq_t freq;
    duration_t duration;
};

//A melody is a vector of notes
typedef vector<note_t> melody_t;

//A piece node is a melody with a starting point
struct piece_node_t{
    melody_t melody;
    duration_t starting;
};

//A piece is a sequence of piece nodes
typedef vector<piece_node_t> piece_t;

//Function to do diatonic transposition
melody_t transpose(melody_t in_melody, int k, int excute);

//Function to reverse a melody
melody_t invert(melody_t in_melody, int excute);

//Function to apply retrogression on a melody
melody_t retro(melody_t in_melody, int excute);

//Function to scale note
melody_t scale(melody_t in_melody, duration_t dur, int excute);


/**
 * Function to generate a random melody given some constraints
 * For all notes, we have
 * min_duration <= note_duration <= max_duration
 * and
 * sum(note_duration) == total_duration
 * 
 * */
melody_t generate_random_motif(int motif_notes_num = 20);


void extend_main_melody(melody_t& subject_melody,melody_t motif);

melody_t generate_new_melody(melody_t motif);

#endif