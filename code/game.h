#ifndef GAME_H
#define GAME_H

#include "app.h"

void add_to_games_top(game_user u);
class Game : public App
{
    protected:


        SDL_Window* gWindow = NULL;
        SDL_Renderer* gRenderer = NULL;
        std::string item_menu;
        std::string pictPath;
        int pieces;
        int pieceIndex;


    public:
        Game();
};

#endif

