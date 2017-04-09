#include "Ncurse.hpp"

Ncurse::Ncurse(void) {
  return;
}

Ncurse::Ncurse(int nbLine, int nbColumn, int posx, int posy) : _nbLine(nbLine), _nbColumn(nbColumn), _posx(posx), _posy(posy) {
  initscr();
  noecho();
  curs_set(0);
  start_color();
  cbreak();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_color(COLOR_CYAN, 212, 212, 212);
attron(COLOR_PAIR(1));
  this->_win = newwin(this->_nbLine, this->_nbColumn, this->_posx, this->_posy);
  nodelay(this->_win, true);
  keypad(this->_win, true);
  return;
}

Ncurse::~Ncurse(void) {
  return;
}

Ncurse::Ncurse(Ncurse const & src) {
  *this = src;
  return;
}

Ncurse &    Ncurse::operator=(Ncurse const & src) {
  if (this != &src) {
    this->_nbLine = src.getNbLine();
    this->_nbColumn = src.getNbColumn();
    this->_nbColumn = src.getNbColumn();
    this->_posx = src.getPosx();
    this->_posy = src.getPosy();
    this->_win = newwin(this->_nbLine, this->_nbColumn, this->_posx, this->_posy);
  }
  return *this;
}

void        Ncurse::print(const char *str, int y, int x) const {
	mvwprintw(this->_win, y, x, str);
}

void        Ncurse::clear(void) const {
  werase(this->_win);
}

void        Ncurse::refresh(void) const {
  wrefresh(this->_win);
}

int         Ncurse::waitForInput(void) const {
  return wgetch(this->_win);
}

void        Ncurse::color(int i) const {
  wattron(this->_win, COLOR_PAIR(i));
}

int         Ncurse::getNbColumn(void) const {
  return this->_nbColumn;
}

int         Ncurse::getNbLine(void) const {
  return this->_nbLine;
}

int         Ncurse::getPosx(void) const {
  return this->_posx;
}

int         Ncurse::getPosy(void) const {
  return this->_posy;
}
