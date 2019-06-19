Assignment name  : options<br />
Expected files   : *.c *.h<br />
Allowed functions: write<br />
--------------------------------------------------------------------------------<br />

Write a program that takes an undefined number of arguments which could be <br />
considered as options and writes on standard output a representation of those<br />
options as groups of bytes followed by a newline.<br />

An option is an argument that begins by a '-' and have multiple characters <br />
which could be : abcdefghijklmnopqrstuvwxyz<br />

All options are stocked in a single int and each options represents a bit of that<br />
int, and should be stocked like this : <br />

00000000 00000000 00000000 00000000<br />
******zy xwvutsrq ponmlkji hgfedcba<br />

Launch the program without arguments or with the '-h' flag activated must print<br />
an usage on the standard output, as shown in the following examples.<br />

A wrong option must print "Invalid Option" followd by a newline.<br />

Examples :<br />
$>./options<br />
options: abcdefghijklmnopqrstuvwxyz<br />
$>./options -abc -ijk<br />
00000000 00000000 00000111 00000111<br />
$>./options -z<br />
00000010 00000000 00000000 00000000<br />
$>./options -abc -hijk<br />
options: abcdefghijklmnopqrstuvwxyz<br />
$>./options -%<br />
Invalid Option<br />
