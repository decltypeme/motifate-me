#include "abc.h"


void write_abc_headers(ostream& outs){
    outs << "X: 1" << endl;
    outs << "T: Some Awesome Random Music!" << endl;
    outs << "C: Some Awesome Turing Machine" << endl;
    outs << "M: 6/8" << endl;
    outs << "L: 1/4" << endl;
    outs << "K: C" << endl;
    outs << "Q: 120" << endl;
}

void write_abc_random_music(ostream& outs, int melodies_count){
    melody_t motif = generate_random_motif();
    melody_t main_melody;
    extend_main_melody(main_melody, motif);
    outs << to_string(main_melody);
}

int main(int argc, char** argv){
    srand(time(NULL));
    string output_file_name = "generated-music.abc";
    int melodies_count = 10;
    if(argc > 1)
        output_file_name = argv[1];
    ofstream outs(output_file_name);
    if(outs.fail() || !outs.is_open()){
        cerr << "Couldnot open file stream" << endl;
        exit(EXIT_FAILURE);
    }
    if(argc > 2){
        melodies_count = stoi(argv[2]);
    }
    write_abc_headers(outs);
    write_abc_random_music(outs, melodies_count);
    outs.close();
    exit(EXIT_SUCCESS);
}