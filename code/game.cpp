#include "game.h"
#include "menu.h"
#include "head.h"
#include "handler.h"
#include "NameUser.h"
#include "MainMenu.h"
#include "Gaming.h"
#include "CheckResults.h"
Game::Game()
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    gWindow = SDL_CreateWindow("Puzzle",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    //создаю холст
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderTarget(gRenderer, NULL);

    //Заставка
    new Head(gWindow, gRenderer);
    SDL_Delay(3000);
    new NameUser(gWindow, gRenderer, &item_menu, &igrok);

    new MainMenu(gWindow, gRenderer, &item_menu, &games_top);
    bool ex = false;

    std::cout << "ITEM MENU " << item_menu << "\n";
    while(!ex)
    {
        int pieceIndex = 0;
        std::cout << "START WHILE " << item_menu << "\n";
        if(item_menu == "REPLACE")
        {
            std::cout << "REPLACE\n";
            new NameUser(gWindow, gRenderer, &item_menu, &igrok);
            session_stat = {};
        }else if(item_menu == "RESULTS")
        {
            //TODO
            new CheckResults(gWindow, gRenderer, &item_menu, &igrok, &session_stat);
        }else if((item_menu == "MENU") || (item_menu == "CONTINUE"))
        {
            std::cout << "\nMenu\n";
            //Меню игры
            new Menu(gWindow, gRenderer, &pictPath, &pieceIndex, &item_menu, &igrok, &games_top);
        }
        if(item_menu == "MAINMENU")
        {
            new MainMenu(gWindow, gRenderer, &item_menu, &games_top);
        }else if(item_menu == "REPLACE")
        {

            new NameUser(gWindow, gRenderer, &item_menu, &igrok);
            session_stat = {};
        }else if(item_menu == "START")
        {

            new Gaming(gWindow, gRenderer, &item_menu,
                       &pieceIndex, &pictPath,&igrok,&games_top,&session_stat);

        }else if(item_menu == "EXIT")
        {
            exit(1);
        }
    }
}

