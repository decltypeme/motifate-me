#include "operations.h"


//k limited to 24
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
    first_freq = in_melody[0].freq;
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


//frequencies in one octave ... BASE { -12, 12 }  ... INTERVALS {} S=[0 12 7 5 9 4 3 8 2 10 1 11 6]
melody_t generate_random_motif(duration_t min_duration, duration_t max_duration, duration_t maximum_duration){
    melody_t motif;
    
    note_t base;
    
    base.frequency = 12 - rand() % 25;
    while (! ((base.duration >= min_duration) && (base.duration  <= max_duration)  ) {
        base.duration = make_pair(1 + rand() % 5 , 1 + rand() % 5);
    }
    
    
    //succession for notes both frequency & duration ... frequency -12 to 12  ... interval rand between 0:12 with probablity ...  max total duration
    do {
        
        
        
    } while();

    
    return motif;
}

melody_t generate_new_melody(melody_t motif){
    int k = 12 - rand() % 25;
    int dur_2 = 2 - rand() % 5;
    duration_t dur = <1 + rand() % pow (2, dur_2),dur_2>;
    
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
        int empty = rand() %10;
        if (empty==0){
        note_t new_note;
        new_note.freq = -100;
        int dur_2 = 0 - rand() % 3;
        new_note.duration = <1 + rand() % pow (2, dur_2),dur_2>;
        subject_melody.push_back(new_note); 
        }
        subject_melody.push_back(note);
    }
    
    for (int i =1; i<=4; i++){
    melody_t new_melody = generate_new_melody(motif);
    
    
        for(note_t note:new_melody){
        int empty = rand() %10;
        if (empty==0){
        note_t new_note;
        new_note.freq = -100;
        int dur_2 = 0 - rand() % 3;
        new_note.duration = <1 + rand() % pow (2, dur_2),dur_2>;
        subject_melody.push_back(new_note); 
        }
        subject_melody.push_back(note);
    }
    
    }
    
}