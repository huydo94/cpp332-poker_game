========================================================================
Lab 2

Author: Huy Do
WUSTL email: huy.do@wustl.edu
========================================================================

I/ I ran into so many errors in this lab. The most notable ones are: 

1. It is difficult to declare and define ( Deck& operator<< (Deck& deck2, Hand& somehand4);  ) correctly because this function access the private member variable
of both class Hand and Deck. Thus I had to declare this function operator in both classes and friend the Hand/Deck class in each other's class. 

2. The proper way to write the copy "=" operator is :

Hand& Hand::operator=(const Hand &somehand1) {
	if (&somehand1 == this)
		return *this;
	myhand = somehand1.myhand;
	return *this;
}

3. Two strings cannot be compared using  ("shuffle"==str2). Had to use str.compare();

4. Declaring 	vector<Hand> ninehands(9); and run std::sort(ninehands.begin(), ninehands.end(), poker_rank);  
caused some unfathomable errors. 

II/ Cases I ran:
+ Playing with the command line:
1. lab2  
Not enough input arguments
2. lab2 fdsa
Invalid .txt file name. Type   lab2 card_file to run the program.
3. lab2 card_file d;lsak
Enter lab2 card_file -shuffle to run
4. lab2 card_file -shuffle lkfdjsf
Too many input arguments

Valid inputs:

lab2 card_file
lab2 card_file -shuffle
lab2 -shuffle card_file

+ Playing with the input txt file: 
5. Put less than 45 valid card strings -> cannot deal 9 hands fully. The print out is:
There is less than 45 valid card strings in the txt file.
6. Put more than 45 valid card strings but with duplicate cards -> there will be some invalid hands. The print out is:
Sort nine hands due to their ranks:
Cannot sort. One or many hands are invalid (contain duplicates/ less than 5 cards per hand)
7. Put 9 duplicate hands in the txt file. The program just sorts normally and print out 9 duplicate hands.

8. Put 52 valid card strings of a poker deck. The print out is:
Printing the contents of nine hands just dealt:
2S 4D 5H JD KC
5S 7C 7H 10S JH
2D 3C 4C 5C QH
3H 7D 8S 10H KS
6C 9D 9H QS AS
8D QC QD KD KH
3S 4S 6H 8H 9C
2H 6D 9S 10D AC
3D 5D 8C AD AH
Sort nine hands in lexical order: (from low to high)
3S 4S 6H 8H 9C
5S 7C 7H 10S JH
2D 3C 4C 5C QH
3H 7D 8S 10H KS
2S 4D 5H JD KC
8D QC QD KD KH
2H 6D 9S 10D AC
6C 9D 9H QS AS
3D 5D 8C AD AH
Sort nine hands due to their ranks: (from high to low)
8D QC QD KD KH
3D 5D 8C AD AH
6C 9D 9H QS AS
5S 7C 7H 10S JH
2H 6D 9S 10D AC
2S 4D 5H JD KC
3H 7D 8S 10H KS
2D 3C 4C 5C QH
3S 4S 6H 8H 9C

========================================================================================
EXTRA CREDIT
========================================================================================
1. Exceptions: I use exceptions mostly to throw strings of error messages. Whenever 
a function contains a throw, I put it in a try/catch block whenever I call it in main()

2. Pointers and arrays: Got an error in sort() because I declare a fixed-size vector for vector<Hand> ninehands

3. Debugging: used debugging call stacks to find functions not behaving correctly. In this lab, my "=" operator for class Hand has errors that only appear in
call stacks.

4. Constructors: didn't really have to use initialization list for constructors except for: 
Card::Card(ranks rank1 = two, suits suit1 = spades)
	:Suits(suit1), Ranks(rank1) {}
where I followed the guidelines

5. copy and assignment operator rules : do not apply in this lab (they are all public)

6. do not apply. There's only one header/ source file.


