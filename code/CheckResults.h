#pragma once
#include "app.h"

class CheckResults : public App
{
    public:
        CheckResults(SDL_Window *, SDL_Renderer *, std::string *_ev_res, game_user *igrok, std::vector<game_user> *s);
        ~CheckResults();
    private:
        std::string *ev_res;
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;
        game_user *igrok;
        std::vector<game_user> *session_stat;
        void getResults();
};
