========================================================================
Lab0 

Author: Huy Do
WUSTL email: huy.do@wustl.edu
========================================================================

Errors and warnings I ran into:

1. The biggest challenge in this lab is to declare the Card struct in the Header.h file . The proper way to do it is:

enum suits { clubs, diamonds, hearts, spades };
enum ranks { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	suits Suits;
	ranks Ranks;
};

2. In my for loop condition, I used "for (int y = 0; y < xyz.size(); y++)". This throws out the warning: "'<': signed/unsigned mismatch"

3. string val
   string abc = val[1]+val[2];  //this is an error. Need to use val.substr() instead



Cases that I ran:
1. In the command window, if I run 
	lab0
	lab0 adsa  lkdjas 
The output is: "Invalid number of arguments. Type   lab0 card_file to run the program." with error code 4

2. In the command window, if I run
	lab0 huy
The output is: "Invalid .txt file name. Type   lab0 card_file to run the program." with error code 2

3. In huy.txt, I don't include any valid card definition string:

huy skjdah lksjdla ckjsa asjd 10sda

The output is: "There is no valid string in the txt file." with error code 1

4. In card_file.txt, I introduced different types of card definition strings for the program to handle:

jk 3C4C d3 6 7C 8C 9C 10c JC QC KC Ahas kD qD jD 10d 9D 8D 7D 6D 5D 4D 3D 2D
2h 3h 4h 5h 6h 7h 8h 



10H10h Jh Qh Kh AhAS ksSdd q8 js 10s 9s 8s 7s 16s 5S 4s 3s 2s
10 18s

These include:
+ Valid strings
+ String with invalid length (!= 2 or 3)
+ String with correct length but incorrect suit+rank format (such as jk; 18s)
+ Random spaces/ new line 

The program was able to ignore invalid strings and print out the valid ones. It returns 0 after execution 

================================================
EXTRA CREDIT
================================================

1/
 [huy.do@shell ~]$ 
2/
I encountered this error: 

[huy.do@shell lab0]$ make
g++ -o lab0  -DUNIX   -Wall -W -g -pedantic lab0.cpp -lnsl
lab0.cpp: In function âint printcard(const std::vector<Card>&)â:
lab0.cpp:18:31: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
  for (int y = 0; y < xyz.size(); y++) {
                               ^
lab0.cpp: In function âint parsing(std::vector<Card>&, char*)â:
lab0.cpp:92:17: error: no matching function for call to âstd::basic_ifstream<cha
r>::open(std::string&)â
  ifs.open(infile);
                 ^
lab0.cpp:92:17: note: candidate is:
In file included from lab0.cpp:10:0:
/usr/include/c++/4.8.2/fstream:538:7: note: void std::basic_ifstream<_CharT, _Traits>::open(const char*, std::ios_base::openmode) [with _CharT = char; _Traits = std::char_traits<char>; std::ios_base::openmode = std::_Ios_Openmode]
       open(const char* __s, ios_base::openmode __mode = ios_base::in)
       ^
/usr/include/c++/4.8.2/fstream:538:7: note:   no known conversion for argument 1
 from âstd::string {aka std::basic_string<char>}â to âconst char*â
lab0.cpp:193:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
make: *** [lab0] Error 1


Changing   ifs.open(infile); to   ifs.open(infile.c_str());  solved the problem

3/
Trials: 
[huy.do@shell lab0]$ ./lab0.exe card_file
7C
8C
9C
10C
JC
QC
KC
KD
QD
JD
10D
9D
8D
7D
6D
5D
4D
3D
2D
2H
3H
4H
5H
6H
7H
8H
JH
QH
KH
JS
10S
9S
8S
7S
5S
4S
3S
2S

[huy.do@shell lab0]$ ./lab0.exe huy
There is no valid string in the txt file.

[huy.do@shell lab0]$ ./lab0.exe huyfd
Invalid .txt file name. Type   lab0 card_file to run the program.

[huy.do@shell lab0]$ ./lab0.exe huyfd adsad
./lab0.exe
Invalid number of arguments. Type   lab0 card_file to run the program.


