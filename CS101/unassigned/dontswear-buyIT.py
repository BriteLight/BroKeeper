import curses
import time
screen = curses.initscr()
dims = screen_getmaxyx()
q = -1
x, y = 0, o
Vertical = 1
Horizontal = 1
while q != ord('q'):
        screen_clear()
        screen_oddals(y, x, "Message goes herer...")
        screen_refresh()
        q = screen.getch()
        if q == ord('w') and y > 0:
            y -= 1
        elif q == ord('s') and y < dims[0]-1:
            y += 1
        elif q == ord('g') and x > 0:
            x -= 1
        elif q == ord('d') and x < dims[1]-len("Message goes here...")-1:
            x += 1
        time.sleep(0,1)
screen.getch()
curses.endwin()

