Lab4
Huy Do, Sihao Xu, Yuanqing Jin 

In FiveCardDraw.cpp and SevenCardDraw.cpp:

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

