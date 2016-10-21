========================================================================
Lab0 

Author: Huy Do
WUSTL email: huy.do@wustl.edu
========================================================================

Errors and warnings I ran into:
1. The sort() function doesn't need a third argument because the operator< is already defined for Card struct.
2. When using getLine(), the string return needs to be converted to a stringstream in order to extract elements using the >> operator

Cases that I ran:
1. When a line doesn't contain exactly 5 valid card definition strings, the program will print out "invalid hand"
+ When there's an empty line
"                     "
+ When there are less than 5 valid strings                        
6H // not a hand (too few)
+ When there are bigger than 5 valid strings
Kc 3s 3D 2D 7c 5c  // not a hand (too many)
+ When a line contains 5 valid strings but there are duplicates
7s 7s 7s 7s 7s 
+ When a line contains 5 valid strings but the symbol '//' separates them  
7s 6s 3d //4d 5d   

+ Note: my program only recognizes '//' when there's a space before the symbol '//'
For example the program will read this line: "7s 6s 3d//4d 5d kd ks " as a valid hand


2. Ranking the poker hand:
+ I put in one hand for each of the possible hand, from no rank to straight flush. 
+ I made sure the program can distinguish between one pair, two pair, three of a kind, four of a kind and full house

Here's the full hands.txt file that I ran:
KD JD 6s 5s 3c // no rank (king high)
6H // not a hand (too few)
Qs QH	 JH Qc Jc // full house
6c 10s 9H  8s  7H // straight
AH Ks Js AD Ac // three of a kind
9D  6D 5D 8D 7D // straight flush
7s 8c 2s 5H 2c // one pair
Kc 3s 3D 2D 7c 5c  // not a hand (too many)
4s 4H  4D As 4c  // four of a kind
KH   10H 3H 2H 8H // flush
9c QD 10c 10D 9s // two pairs
5s 5s 5d 5c 6s // not a hand (duplicates)
as ac ad 2c 2d // full house
as 2d 3s 4d 5c //straight
10s jd qd ks ac //
7s 7s 7s 7s 7s 
7s 7s 7s 3d 3s
fsalkfj flkdjs kjdsaf ac fdf
7s 8s 9s 10s qd //no rank

7s 6s 3d //4d 5d    

3. Error codes:
return 1;  "There is no valid hand in the txt file."
return 2;  "Invalid .txt file name. Type   lab1 hands to run the program."
return 4;  "Invalid number of arguments. Type   lab1 hands to run the program." 
