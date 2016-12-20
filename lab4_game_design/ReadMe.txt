Lab4
Huy Do, Sihao Xu, Yuanqing Jin 

Errors, warnings and design choices:
- The betting is implemented using two functions: betPhase() and betturn(&Player) :
+ betPhase() manages the order of betting, calling betturn() on each player and check for all terminating conditions of betting.
+ betturn(&Player) is where each player’s action (check/bet) and (call/raise/fold) is implemented. If the user input an invalid action, the program will ask the user to do it again. However, the program doesn’t take into account invalid input of money being bet/raise. 

- For the betting process, we took into account all of the possible cases in a poker game, notably:
+ When everyone except one person folded, the program will skip all the turns and go straight to the after_round() function
+ When someone runs out of money during betting, he/she will stay in the turns but won’t be able to make any bet. 
+ When someone folded, he/she won’t participate in any betting/ discarding cards activity

- For the after_round() function, anyone who folded will lose and their hands won’t be printed out. If a person wins by forcing others to fold, the winner’s hand also won’t be printed out.

- To select the best 5 combination out of 7 cards, we first used a recursive algorithm to insert all 21 possible combinations into a vector. Then we sort the cards in each hand element in the vector, then sort the whole vector. 

- In FiveCardDraw, we need to have auto-sorting in << operator. But the auto sorting is not desirable in SevenCardStud. To solve this problem, we create another operator >> specifically for SevenCardDraw so that cards are not automatically sorted in this game. This helps printing out the cards in each of the 5 turns in the correct order of face up/ face down cards that they are dealt. 

- In FiveCardDraw, the max number of players is 10. In SevenCardStud, the max number of players is 7. We made sure that no player can join the game if the maximum is reached. When a game is stopped and a new game is created, if user enters too many players, the program will exit.



Test cases:
1. Invalid inputs
>lab4.exe
>lab4 daskkj 
Enter lab4 FiveCardDraw or lab4 SevenCardDraw and at least 2 players separated by a comma to start
>lab4 SevenCardStud 1 2 3 4 5  6 7 8
The maximum number of players to start the game is only 7.

2. A normal FiveCardDraw game
>lab4.exe FiveCardDraw Alice Bob

Alice, can not be open, and I will build the file.

Bob can not be open, and I will build the file.

There are 2 players. Let's start a new round.

Alice,'s hand: 3D 3H JS QD QS

Bob's hand: 2D 6C JD QC AC

Bob's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 2

What do you wanna do? (check/bet)

check

checked

Alice's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 2

What do you wanna do? (check/bet)

check

checked

Name: Bob

Hand: 2D 6C JD QC AC

index of cards to discard (from 1 to 5). Enter 0 if don't want to discard any:

if you want to discard more than one card, type in space between each index.

2

Name: Alice

Hand: 3D 3H JS QD QS

index of cards to discard (from 1 to 5). Enter 0 if don't want to discard any:

if you want to discard more than one card, type in space between each index.

0

Name: Bob

Hand (after_turn): 2D 7S JD QC AC

Name: Alice

Hand (after_turn): 3D 3H JS QD QS

Bob's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 2

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

2

Bob's bet turn ends. Chips bet in the phase: 2 Chips remaining: 17

Alice's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 4

What do you wanna do? (fold/call/raise)

call

Alice's bet turn ends. Chips bet in the phase: 2 Chips remaining: 17

Alice  Games Won: 1  Games Lost: 0 chip account: 23

won with hand:

3D 3H JS QD QS

Bob  Games Won: 0  Games Lost: 1 chip account: 17

lost with hand:

2D 7S JD QC AC

Is there any player want to leave? (yes/no)

no

Is there any player want to join the game? (yes/no)

no

There are 2 players. Let's start a new round.

Alice's hand: 2H 3D 7D 7S QS

Bob's hand: 6S 8H 9D AD AS

Alice's turn begins. Chips bet in the phase:0 Chips remaining: 22 Pot: 2

What do you wanna do? (check/bet)
bet
How much do you wanna bet? (1 or 2)
1
Alice’s bet turn ends. Chips bet in the phase: 1 Chips remaining 21
Bob’s turn begins. Chips bet in the phase:0 Chips remaining: 16 Pot 3
What do you wanna do? (fold/call/raise)
raise
How much do you wanna raise? (1 or 2)
2
Bob’s bet turn ends. Chips bet in the phase: 2 Chips remaining: 14
Alice’s turn begins. Chips bet in the phase:1 Chips remaining 21 Pot: 5
What do you wanna do? (fold/call/raise)
call
Alice’s bet turn ends. Chips bet in the phase: 2 Chips remaining: 20
Name: Alice
Hand 2H 3D 7D 7D QS
index of cards to discard (from 1 to 5). Enter 0 if don't want to discard any:

if you want to discard more than one card, type in space between each index.

0
Name: Bob
Hand: 6S 8H 9D AD AS
index of cards to discard (from 1 to 5). Enter 0 if don't want to discard any:

if you want to discard more than one card, type in space between each index.

1
Name: Alice
Hand (after_turn): 2H 3D 7D 7S QS
Name: Bob
Hand (after_turn): 2D 8H 9D AD AS
Alice’s turn begins. Chips bet in the phase: 0 Chips remaining: 20 Pot: 6
What do you wanna do? (check/bet)
check
checked
Bob’s turn begins. Chips bet in the phase: 0 Chips remaining: 14 Pot: 6
What do you wanna do? (check/bet)
bet
How much do you wanna bet? (1 or 2)
2
Bob’s bet turn ends. Chips bet in the phase: 2 Chips remaining: 12
Alice’s turn begins. Chips bet in the phase: 0 Chips remaining: 20 Pot: 8
What do you wanna do? (fold/call/raise)
call
Alice’s bet turn ends. Chips bet in the phase: 2 Chips remaining: 18
Bob Games Won: 1 Games Lost: 1 chip account: 22
won with hand: 2D 8H 9H AD AS
Alice Games Won: 1 Games Lost: 1 chip account: 18
lost with hand: 2H 3D 7D 7S QS


3. A normal SevenCardStud Game
>lab4.exe SevenCardStud Cathy Dan Evan

Cathy can not be open, and I will build the file.

Dan can not be open, and I will build the file.

Evan can not be open, and I will build the file.

There are 3 players. Let's start a new round.

Turn 1 begins:

Cathy's view:

Cathy's hand: 2H 4D KS

Dan's hand:  (*) (*) 2S

Evan's hand:  (*) (*) 10C

Dan's view:

Cathy's hand:  (*) (*) KS

Dan's hand: 10H QC 2S

Evan's hand:  (*) (*) 10C

Evan's view:

Cathy's hand:  (*) (*) KS

Dan's hand:  (*) (*) 2S

Evan's hand: 6C QS 10C

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 3

What do you wanna do? (check/bet)

check

checked

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 3

What do you wanna do? (check/bet)

check

checked

Cathy's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 3

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

2

Cathy's bet turn ends. Chips bet in the phase: 2 Chips remaining: 17

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 5

What do you wanna do? (fold/call/raise)

raise

How much do you wanna raise? (1 or 2)

2

Dan's bet turn ends. Chips bet in the phase: 4 Chips remaining: 15

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 19 Pot: 9

What do you wanna do? (fold/call/raise)

call

Evan's bet turn ends. Chips bet in the phase: 4 Chips remaining: 15

Cathy's turn begins. Chips bet in the phase:2 Chips remaining: 17 Pot: 13

What do you wanna do? (fold/call/raise)

call

Cathy's bet turn ends. Chips bet in the phase: 4 Chips remaining: 15

Turn 2 begins:

Cathy's view:

Cathy's hand: 2H 4D KS 3C

Dan's hand:  (*) (*) 2S  2D

Evan's hand:  (*) (*) 10C  AS

Dan's view:

Cathy's hand:  (*) (*) KS  3C

Dan's hand: 10H QC 2S 2D

Evan's hand:  (*) (*) 10C  AS

Evan's view:

Cathy's hand:  (*) (*) KS  3C

Dan's hand:  (*) (*) 2S  2D

Evan's hand: 6C QS 10C AS

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 15 Pot: 15

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

1

Dan's bet turn ends. Chips bet in the phase: 1 Chips remaining: 14

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 15 Pot: 16

What do you wanna do? (fold/call/raise)

call

Evan's bet turn ends. Chips bet in the phase: 1 Chips remaining: 14

Cathy's turn begins. Chips bet in the phase:0 Chips remaining: 15 Pot: 17

What do you wanna do? (fold/call/raise)

call

Cathy's bet turn ends. Chips bet in the phase: 1 Chips remaining: 14

Turn 3 begins:

Cathy's view:

Cathy's hand: 2H 4D KS 3C 4S

Dan's hand:  (*) (*) 2S  2D  8H

Evan's hand:  (*) (*) 10C  AS  3S

Dan's view:

Cathy's hand:  (*) (*) KS  3C  4S

Dan's hand: 10H QC 2S 2D 8H

Evan's hand:  (*) (*) 10C  AS  3S

Evan's view:

Cathy's hand:  (*) (*) KS  3C  4S

Dan's hand:  (*) (*) 2S  2D  8H

Evan's hand: 6C QS 10C AS 3S

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 14 Pot: 18

What do you wanna do? (check/bet)

check

checked

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 14 Pot: 18

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

2

Evan's bet turn ends. Chips bet in the phase: 2 Chips remaining: 12

Cathy's turn begins. Chips bet in the phase:0 Chips remaining: 14 Pot: 20

What do you wanna do? (fold/call/raise)

fold

Cathy's bet turn ends. Chips bet in the phase: 0 Chips remaining: 14

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 14 Pot: 20

What do you wanna do? (fold/call/raise)

call

Dan's bet turn ends. Chips bet in the phase: 2 Chips remaining: 12

Turn 4 begins:

Dan's view:

Dan's hand: 10H QC 2S 2D 8H AC

Evan's hand:  (*) (*) 10C  AS  3S  10S

Evan's view:

Dan's hand:  (*) (*) 2S  2D  8H  AC

Evan's hand: 6C QS 10C AS 3S 10S

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 12 Pot: 22

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

1

Dan's bet turn ends. Chips bet in the phase: 1 Chips remaining: 11

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 12 Pot: 23

What do you wanna do? (fold/call/raise)

raise

How much do you wanna raise? (1 or 2)

2

Evan's bet turn ends. Chips bet in the phase: 3 Chips remaining: 9

Dan's turn begins. Chips bet in the phase:1 Chips remaining: 11 Pot: 26

What do you wanna do? (fold/call/raise)

call

Dan's bet turn ends. Chips bet in the phase: 3 Chips remaining: 9

Turn 5 begins:

Dan's view:

Dan's hand: 10H QC 2S 2D 8H AC 8S

Evan's hand:  (*) (*) 10C  AS  3S  10S  (*)

Evan's view:

Dan's hand:  (*) (*) 2S  2D  8H  AC  (*)

Evan's hand: 6C QS 10C AS 3S 10S 7S

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 9 Pot: 28

What do you wanna do? (check/bet)

check

checked

Evan's turn begins. Chips bet in the phase:0 Chips remaining: 9 Pot: 28

What do you wanna do? (check/bet)

bet

How much do you wanna bet? (1 or 2)

1

Evan's bet turn ends. Chips bet in the phase: 1 Chips remaining: 8

Dan's turn begins. Chips bet in the phase:0 Chips remaining: 9 Pot: 29

What do you wanna do? (fold/call/raise)

call

Dan's bet turn ends. Chips bet in the phase: 1 Chips remaining: 8

Evan  Games Won: 1  Games Lost: 0 chip account: 38

won with hand:

3S 7S 10S QS AS

Cathy  Games Won: 0  Games Lost: 1 chip account: 14

folded.

Dan  Games Won: 0  Games Lost: 1 chip account: 8

lost with hand:

2D 2S 8H 8S AC

4. When a game ends, the program asks user to continue or quit the game:

Is there any player want to leave? (yes/no)
no
Is there any player want to join the game? (yes/no)
no
There is less than 2 players.
Game ended. Choose (continue/quit):
continue
Enter the type of game (FiveCardDraw/SevenCardStud):
SevenCardStud
Enter the player names (separated by space):
A B C D E
There are 5 players. Let's start a new round.

