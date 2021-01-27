
#ifndef HEAD_H
#define HEAD_H

#include "app.h"

class Head : public App{
    private:
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;
        void head();

    public:
        Head(SDL_Window *, SDL_Renderer *);
        ~Head();
};

#endif

