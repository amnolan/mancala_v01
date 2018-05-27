# mancala
Mancala - An ancient board game, computerized

## how to build

Lucky for you this project includes a makefile. Download or checkout the repository. In the corresponding directory 
run the following:

    $ make

Then to start:

    $ ./mancala
    
## gameplay

Mancala is an ancient board game with several sets of rules. There is evidence this game has been played in ancient Sumeria as
far back as 5000 years ago.

There are two rows, player one's row is the bottom row, the computer's row is the top row. There are two stores one to the
left and one to the right, which are owned by the computer and player one respectively.

The game begins when player one picks up all the stones from a pot by selecting a number between one and six. The program
then moves counter-clockwise depositing one stone per pot until there are no more, while skipping your opponent's store. 
If the last stone is deposited into player one's pot, then player one goes again by starting at that final pot and by 
picking up all stones and moving counter-clockwise again, if there are no stones in that pot, player one's turn is finished. 

The same rules apply to the computer (player two).

## scoring

You can score points in one of two ways.

The first way to score points is by passing your pot during a turn, where you will score one point.

The second way to score points is by ending on an empty pot on your side which has stones in the hole perpendicular (directly
above or below the final hole). If this occurs, you get all the stones in that perpendicular pot.

## example

In the below image the bottom row belongs to player one and the store on the right (spot 7) belongs to player one as well. The top row and spot 14 belong to the computer.

    Welcome to Mancala!
    
    
        14    13     12     11     10      9      8     7  
     ________________________________________________________
     |       ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )       |\
     | ( 0 )                                          ( 0 ) | \
     |       ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )       |  |
     --------------------------------------------------------  |
     \         1      2      3      4      5      6          \ |
      \_______________________________________________________\|
    
    
    Player one, please enter a valid input (1 - 6) or -1 to quit: 1
    
    This turn ended on player one's side, player one goes again.
    
        14    13     12     11     10      9      8     7  
     ________________________________________________________
     |       ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )  ( 4 )       |\
     | ( 0 )                                          ( 0 ) | \
     |       ( 0 )  ( 5 )  ( 5 )  ( 5 )  ( 5 )  ( 4 )       |  |
     --------------------------------------------------------  |
     \         1      2      3      4      5      6          \ |
      \_______________________________________________________\|
    
        14    13     12     11     10      9      8     7  
     ________________________________________________________
     |       ( 4 )  ( 4 )  ( 4 )  ( 5 )  ( 5 )  ( 5 )       |\
     | ( 0 )                                          ( 1 ) | \
     |       ( 0 )  ( 5 )  ( 5 )  ( 5 )  ( 0 )  ( 5 )       |  |
     --------------------------------------------------------  |
     \         1      2      3      4      5      6          \ |
      \_______________________________________________________\|
    
    
    The Computer selected spot number: 13
    
    
    
        14    13     12     11     10      9      8     7  
     ________________________________________________________
     |       ( 0 )  ( 4 )  ( 4 )  ( 5 )  ( 5 )  ( 5 )       |\
     | ( 1 )                                          ( 1 ) | \
     |       ( 1 )  ( 6 )  ( 6 )  ( 5 )  ( 0 )  ( 5 )       |  |
     --------------------------------------------------------  |
     \         1      2      3      4      5      6          \ |
      \_______________________________________________________\|
    
    
    Player one, please enter a valid input (1 - 6) or -1 to quit:      

## notes

Enjoy!
