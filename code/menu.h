#ifndef MENU_H
#define MENU_H

#include "app.h"

class Menu : public App
{
    private:
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;
        std::string *pictPath;
        int  pieceIndex;
        int *pieces;
        std::string *event_menu;
        std::vector<game_user> *games_top;
        game_user *igrok;
        void menu();

    public:
        Menu(SDL_Window *, SDL_Renderer *, std::string *_pictPath, int *_pieces,
             std::string *_event_menu,
             game_user *_igrok,
             std::vector<game_user> *games_top);
        ~Menu();
};

#endif

