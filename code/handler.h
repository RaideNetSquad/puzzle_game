#ifndef HANDLE_H
#define HANDLE_H

#include "game.h"
#include "Gaming.h"
#include "app.h"


class Handler : public App {
    private:
        std::string getPuzzleHandle();
        std::string getMenuHandle();
        std::string getUserNameHandle();
        std::string getMainMenu();
        std::string getWindowWinner();
        std::string getResult();
        std::vector<Tile *> tiles;
        SDL_Event e;
    public:
        Handler();
        Handler(std::vector<Tile *> &tiles);
        std::string getEvent(std::string handle_name);
};

#endif

