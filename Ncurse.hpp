#ifndef NCURSE_HPP
#define NCURSE_HPP

#include <curses.h>
#include <iostream>

#define KEY_SPACE 32

class Ncurse {
  public:
    Ncurse(int nbLine, int nbColumn, int posx, int posy);
    Ncurse(Ncurse const & src);
    ~Ncurse(void);

    Ncurse &    operator=(Ncurse const & src);

    void        print(const char * str, int y, int x) const;
    int         waitForInput(void) const;
    void        refresh(void) const;
    void        clear(void) const;
    void        color(int i) const;
    WINDOW      getWin(void) const;
    int         getNbLine(void) const;
    int         getNbColumn(void) const;
    int         getPosx(void) const;
    int         getPosy(void) const;

  private:
    Ncurse(void);
    int     _nbLine;
    int     _nbColumn;
    int     _posx;
    int     _posy;
    WINDOW  *_win;

};

#endif
