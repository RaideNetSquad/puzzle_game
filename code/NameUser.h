#pragma once
#include "app.h"

class NameUser : public App
{
    public:
        NameUser(SDL_Window *, SDL_Renderer *, std::string *event_menu, game_user *u);
        ~NameUser();
    private:
        std::string *event_menu;
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;

        game_user *igrok;
        void getUser();
};
