#pragma once
#include "app.h"

class MainMenu : public App
{
    public:
        MainMenu(SDL_Window *, SDL_Renderer *, std::string *_ev_res,std::vector<game_user> *games_top);
        ~MainMenu();
    private:
        std::string *ev_res;
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;
        void getMainMenu();
        std::vector<game_user> *games;
};
