
#include "head.h"

void Head::head()
{
    SDL_SetRenderDrawColor(mRenderer, 0x12, 0x10, 0xFF, 0x00);
	SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    makeTitle(mRenderer, "Название игры: Puzzle!", 230, 50);
    makeTitle(mRenderer, "Фамилия автора: Baby", 230, 90);
    makeTitle(mRenderer, "Группа автора: Home for baby", 230, 130);

    makePict(mRenderer, "./pictures/head.jpg", 230, 210, 350, 300);


    SDL_RenderPresent(mRenderer);
    SDL_RenderClear(mRenderer);
}

Head::Head(SDL_Window *_gWindow, SDL_Renderer *_gRendrer) :
    gWindow(_gWindow), mRenderer(_gRendrer)
{
    TTF_Init();
    head();
}

Head::~Head()
{
	TTF_Quit();
}
