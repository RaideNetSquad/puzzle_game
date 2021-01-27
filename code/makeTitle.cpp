#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

void makeTitle(SDL_Renderer *mRenderer,std::string title, int posX, int posY)
{
    /*
        Создаю Заголовок на холсте mRenderer
    */
    TTF_Font* font = TTF_OpenFont("./Copperplate-Bold.ttf", 20);
    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface *msgSurf = TTF_RenderText_Blended(font, title.c_str(), white);
    SDL_Texture *pictMsg = SDL_CreateTextureFromSurface(mRenderer, msgSurf);
    SDL_Rect msgRect = {
        posX, posY,
        msgSurf->w, msgSurf->h
    };
    SDL_RenderCopy(mRenderer, pictMsg, NULL, &msgRect);

    SDL_FreeSurface(msgSurf);
    SDL_DestroyTexture(pictMsg);
	TTF_CloseFont(font);
}
