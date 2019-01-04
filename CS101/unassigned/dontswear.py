#!/usr/bin/env python
from curses import *

def main(): {
        stdscr = curses.initscr()
        running = True
        while(running):
          key = getch()
#          if(key == 27):
          if(key == 10):
            running = False
            break
#        elif(chr(key) == 'a'):
        elif(key == ord('a')):
            move(2,0)
            addstr("Trigger character 'a' was pressed")
            continue
        move(10,0)
        addstr("Current keycode is " + str(key) + " which is ASCII character " + chr(key))
        move(0,0)

#        c = getch()
#        addstr(str(c))
#
#        getch()

        endwin()

        return 0
        }

if ( __name__ == "__main__" ): {
        main()
        }

