This is the Readme file for the command line version of Tic-Tac-Toe I made.

## LICENSE

If you have the source code, you're free to use it but you have to mention the real author (me) if you release it with your changes or if you use it in one of your project. For now I release it without license because it's just a little game that I developed for hobby. 

## REQUIREMENTS

This software is written in C language with ncurses.h library so, if you can't compile or run it, you have to install additional packages.

For example, in Fedora, RHEL and CentOS you have to install
 - ncurses-devel
 - ncurses

instead, on Debian and Ubuntu you have to install
 - libncurses5-dev 
 - libncursesw5-dev

Remember that if you want to compile the source from command line you have to add the -lncurses option, for example:

gcc trisr.c -lncurses

## AUTHOR

Author: Edoardo M. F. Tullio "tuzzo"
Version: 0.8
First release date: 01/08/2017
Release date (this version): 01/08/2017

## TO DO

1- Highscore function is not implemented
2- Don't stop the program when user choose a menu option
