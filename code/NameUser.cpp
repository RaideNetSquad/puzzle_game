#include "NameUser.h"
#include "handler.h"
NameUser::NameUser(SDL_Window *_gWindow, SDL_Renderer *_gRendrer,
                   std::string *_event_menu, game_user *u) :
    gWindow(_gWindow), mRenderer(_gRendrer), event_menu(_event_menu), igrok(u)
{
    TTF_Init();
    std::cout << "getUser\n";
    getUser();
    std::cout << "outUser\n";
}

void NameUser::getUser()
{
    std::cout << "getUser start\n";
    SDL_SetRenderDrawColor(mRenderer, 0x26, 0x24, 0x5D, 0x00);
	SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    bool exitt = false;
    Handler handler;
    igrok->name = "";
    std::cout << "wh\n";
    while(!exitt)
    {
        std::cout << "Name 1" << igrok->name;
        makeTitle(mRenderer,"Введите имя Вашего Игрока:", 200, 200);
        makeTitle(mRenderer,"Продолжить", 250, 320);
        makeTitle(mRenderer,"Выход", 700, 50);
        if(igrok->name != "")
        {
            makeTitle(mRenderer,igrok->name, 200, 240);
        }

        std::string eventname = handler.getEvent("UserName");
        std::cout << "Name 2 " << igrok->name;
        if ((eventname == "CONTINUE") && (igrok->name != ""))
        {
			*event_menu = "CONTINUE";
			std::cout << "CONTINUE";
			std::cout << "Name " << igrok->name;
			exitt = true;
		}else if(eventname == "EXIT")
		{
		    std::cout << "Exit";
		    exit(1);
		}

		else if((eventname != "UNDEFINED") && (eventname != "EXIT") && (eventname != "CONTINUE")){
		    igrok->name += eventname;
		    std::cout << "You name symbol " << igrok->name;
		}
        std::cout << "Name " << igrok->name;
        SDL_RenderPresent(mRenderer);
	    SDL_RenderClear(mRenderer);

    }
}
