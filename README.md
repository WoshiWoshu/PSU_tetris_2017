# PSU_tetris_2017
First year mini project in C focusing on files and parameters parsing methods. The program reads and parse informations from the folder "tetriminos" located in the project root. It contains several files describing the tetriminos pieces. The form is "WIDTH - HEIGHT - COLOR" on the first line. From the second line the files describes the pieces shape.

USING :

1) Make 2) ./tetris [options]

Options:

       --help                  Display this help.
       -L --level={num}        Start Tetris at level num (default: 1).
       -l --key-left={K}       Move the tetrimino LEFT using the K key (default: left arrow).
       -r --key-right={K}      Move the tetrimino RIGHT using the K key (default: right arrow).
       -t --key-turn={K}       TURN the tetrimino clockwise 90d using the K key (default: top
       arrow).
       -d --key-drop={K}      DROP the tetrimino using the K key (default: down arrow).
       -q --key-quit={K}      QUIT the game using the K key (default: 'q' key).
       -p --key-pause={K}     PAUSE/RESTART the game using the K key (default: space bar).
       --map-size={row,col}   Set the numbers of rows and columns of the map (default: 20,10).
       -w --without-next      Hide the next tetrimino (default: false).
       -D --debug             Debug mode (default: false).
 
EXEMPLE :

       ./tetris -D -d ‘x’ --key-turn=‘q’ -p ‘p’ --key-quit=u -L 2

       > *** DEBUG MODE ***

       > Key Left :  ^EOD

       > Key Right :  ^EOC

       > Key Turn :  ‘q’

       > Key Drop :  ‘x’

       > Key Quit :  u

       > Key Pause :  ‘p’

       > Next :  Yes

       > Level :  2

       > Size :  20*10

       > Tetriminos :  8

       > Tetriminos :  Name 7 :  Size 5*4 :  Color 3

       > Tetriminos :  Name bar :  Size 1*4 :  Color 2

       > Tetriminos :  Name square :  Size 2*2 :  Color 1

       > Tetriminos :  Name 6 :  Size 2*3 :  Color 6

       > Tetriminos :  Name inverted-L :  Size 2*3 :  Color 5

       > Tetriminos :  Name 5 :  Size 1*1 :  Color 4

       > Tetriminos :  Name 4 :  Error

       > Press any key to start Tetris
