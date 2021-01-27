#include "app.h"
#include <cstdlib>
void App::makePict(SDL_Renderer *mRenderer,std::string path, int posX, int posY, int w, int h)
{
    /*
        Создаю картинки на холсте mRenderer
    */
    SDL_Surface *surf = IMG_Load(path.c_str());
    SDL_Texture *picture = SDL_CreateTextureFromSurface(mRenderer, surf);
    SDL_Rect pictRect = {
        posX,
        posY,
        w,
        h
    };
    SDL_RenderCopy(mRenderer, picture, NULL, &pictRect);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(picture);
}

void App::makeTitle(SDL_Renderer *mRenderer,std::string title, int posX, int posY)
{
    /*
        Создаю Заголовок на холсте mRenderer
    */
    TTF_Font* font = TTF_OpenFont("./arial.ttf", 30);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 0};

    SDL_Surface *msgSurf = TTF_RenderUTF8_Solid(font, title.c_str(), white);
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





void App::write_state(std::string path, std::vector<game_user> *g)
{

    std::fstream fs(path, std::ios::out | std::ios::binary);
    std::vector<game_user> us = *g;
    std::cout << "Namer " << us.at(0).name;
    if(fs.is_open())
    {
        boost::archive::binary_oarchive boa(fs);
        boa << us;
        fs.close();
        fs.open(path, std::ios::in | std::ios::binary);
        if(fs.is_open())
        {
            boost::archive::binary_iarchive bia(fs);
            bia >> us;
                std::cout << "Read from file:\n\n";
            for(auto& i : us) std::cout << i.count << " : " << i.name << std::endl;
            fs.close();
        }

    }
    std::cout << "Writing end\n";
}

void App::read_state(std::string path, std::vector<game_user>*users)
{
    std::vector<game_user> u;
    std::fstream fs;
    fs.open(path, std::ios::in | std::ios::binary);
    if(fs.is_open())
    {
        boost::archive::binary_iarchive bia(fs);
        bia >> u;
        std::cout << "Read from file:\n\n";
        for(auto& i : u) std::cout << i.count << " : " << i.name << std::endl;
        fs.close();
    }

    *users = u;

}


void App::add_to_games_top(game_user u, std::vector<game_user> *games_top){

    games_top->push_back(u);
    std::cout << "add_to_games_top dtart " << games_top->size() << "\n";
    if(games_top->size() > 1)
        std::sort(games_top->begin(), games_top->end(), game_user());
}
