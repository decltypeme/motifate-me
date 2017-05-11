#include "operations.h"


void write_abc_headers(ostream& outs){
    outs << "T: Some Awesome Random Music!" << endl;
    outs << "C: Some Awesome Turing Machine" << endl;
    outs << "M: 6/8" << endl;
    outs << "L: 1/8" << endl;
    outs << "K: C" << endl;
}


int main(int argc, char** argv){
    string output_file_name = "generated-music.abc";
    if(argc > 1)
        output_file_name = argv[1];
    ofstream outs(output_file_name);
    if(outs.fail() || !outs.open()){
        cerr << "Couldnot open file stream" << endl;
        exit(EXIT_FAILURE);
    }
    write_abc_headers(outs);
    write_abc_random_music(outs);
    outs.close();
    exit(EXIT_SUCCESS);
}