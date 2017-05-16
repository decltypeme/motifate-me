./motifate 0music.abc
#sed -ie "s/([a-z]),/\\U\\1/" 0music.abc
#sed -ie "s/([A-Z])'/\\L\\1/" 0music.abc
../tools/jcabc2ps/jcabc2ps 0music.abc > 0music.ps 
convert 0music.ps 0music.png
../tools/abcmidi/abc2midi.exe  0music.abc -o 0music.mid