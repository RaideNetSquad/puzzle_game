#include "MainMenu.h"
#include "handler.h"
MainMenu::MainMenu(SDL_Window *_gWindow, SDL_Renderer *_gRendrer, std::string *_ev_res, std::vector<game_user> *games_top) :
    gWindow(_gWindow), mRenderer(_gRendrer), ev_res(_ev_res), games(games_top)
{
    TTF_Init();
    try{
        read_state(GAMES_FILE, games);
        throw 1;
    }catch(int a){
        std::cout << "Err\n";
    }
    getMainMenu();
}

void MainMenu::getMainMenu()
{
    SDL_SetRenderDrawColor(mRenderer, 0x26, 0x24, 0x5D, 0x00);
	SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    bool exitt = false;
    Handler handler;

    while(!exitt)
    {
        makeTitle(mRenderer,"Игра", 435, 100);
        makeTitle(mRenderer,"Смена игрока", 375, 200);
        makeTitle(mRenderer,"Просмотр результата", 325, 300);
        makeTitle(mRenderer,"Выход", 430, 400);

        std::string event_name = handler.getEvent("MainMenu");

        if (event_name == "EXIT") {
			exit(1);
		}
		else if(event_name != "UNDEFINED"){
            *ev_res = event_name;
            exitt = true;
		}

        SDL_RenderPresent(mRenderer);
	    SDL_RenderClear(mRenderer);

    }
}
