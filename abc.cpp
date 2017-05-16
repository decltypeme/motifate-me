#include "abc.h"

inline int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}
string to_string(note_t note, char key_note){
    string to_return     = "";
    char key_char = (char(key_note + positive_modulo(note.freq, 7)));
    char key_char_old = key_char;
    if(key_char == 'h')
        key_char = 'a';
    else if(key_char == 'i')
        key_char = 'b';
    else if(key_char == 'j')
        key_char = 'c';
    int octaves = note.freq / 7;
    int increment = abs(octaves);
    if(note.freq < 7)
        to_return  += toupper(key_char);
    else
        to_return  += tolower(key_char);

    if(note.freq < 0)
        to_return += string(increment + 1, ',');
    else if(note.freq >= 14)
        to_return += string(increment - 1, '\'');
    
    /*if(key_char_old == 'j')
        increment+=1;
    if(octaves < 0)
        to_return += string(increment, ',');
    else
        to_return += string(increment, '\'');
        */
    to_return += to_string(note.duration.first) + '/' + to_string((1<<note.duration.second));
    /*if(to_return.find(string{tolower(key_char) , '\''}) != string::npos){
        string::iterator ind = to_return.find(string{tolower(key_char) , '\''});
        to_return.replace(ind, ind+2, string(toupper(key_char)));
    }
    if(to_return.find(string{toupper(key_char), ','}) != string::npos){
        string::iterator ind = to_return.find(string{toupper(key_char), ','});
    to_return.replace(ind, ind+2, string(tolower(key_char)));
    }*/
    return to_return;
}

string to_string(melody_t melody, char key_note){
    int counter = 0;
    string to_return = "";
    for(note_t note:melody){
        to_return += to_string(note);
        to_return += ' ';
    }
    return to_return;
}