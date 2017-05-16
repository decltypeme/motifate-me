#include "operations.h"


melody_t transpose(melody_t in_melody, int k, int excute){
    if (excute == 0){
    melody_t to_return;
    for(note_t note:in_melody){
        note_t new_note = note;
        new_note.freq += k;
        to_return.push_back(new_note);
    }
    return to_return;
    }
    return in_melody;
}


melody_t invert(melody_t in_melody, int excute){
    if (excute == 0){
        if(in_melody.size() == 0)
            return in_melody;
        melody_t to_return;
        freq_t first_freq = in_melody[0].freq;
        for(note_t note:in_melody){
            note_t new_note = note;
            new_note.freq = 2*first_freq - new_note.freq;
        }
        return to_return;
    }
    return in_melody;
}


melody_t retro(melody_t in_melody, int excute){
    if (excute == 0)
        reverse(in_melody.begin(), in_melody.end());
    return in_melody;
}

melody_t scale(melody_t in_melody, duration_t dur, int excute){
    if (excute == 0){
    melody_t to_return;
       for(note_t note:in_melody){
        note_t new_note = note;
        new_note.duration *= dur;
        to_return.push_back(new_note);
    }
    
    return to_return;
    }
    return in_melody;
}


//frequencies in one octave ... BASE { -8, 8 }  ... INTERVALS {} S=[0 12 7 5 9 4 3 8 2 10 1 11 6]
melody_t generate_random_motif(int motif_notes_num){
    melody_t motif;
    
    note_t base;
    base.freq = 7 - rand() % 15;
    int dur_2 = rand() % 4;
    base.duration = make_pair(1 + rand() % (1<<dur_2), dur_2);
    simplify_duration(base.duration);
    
    //succession for notes both frequency & duration ... frequency -8 to 8  ... interval rand between 0:8 with probablity ...  max total duration
    do {
        note_t new_note;
        new_note.freq = base.freq + (14 - rand() % 29);
        int dur_2 = rand() % 4;
        new_note.duration = make_pair(1 + rand() % (1<<dur_2), dur_2);
        simplify_duration(new_note.duration);
        motif.push_back(new_note);
        
    } while(motif_notes_num--);

    
    return motif;
}

melody_t generate_new_melody(melody_t motif){
    
    int k = 14 - rand() % 29;
    int dur_2 = rand() % 4;
    duration_t dur = make_pair(1 + rand() % (1<<dur_2), dur_2);
    simplify_duration(dur);

    int trans_excute = rand() % 2;
    int inv_excute = rand() % 2;
    int retro_execute = rand() % 2;
    int scale_excute = rand() % 2;
    
    int order = rand() %2;
    
    if (order == 0)
    return scale (transpose(retro(invert(motif, inv_excute), retro_execute),k ,trans_excute),dur ,scale_excute);
    else
    return scale (transpose(invert(retro(motif, retro_execute), inv_excute),k ,trans_excute),dur ,scale_excute);
    
}


void extend_main_melody(melody_t& subject_melody,melody_t motif){
    
    for(note_t note:motif){
        subject_melody.push_back(note);
    }
    
    for (int i =1; i<=300; i++){
    melody_t new_melody = generate_new_melody(motif);
    
    
        for(note_t note:new_melody){
        subject_melody.push_back(note);
    }
    }
    
}