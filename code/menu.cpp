#include <string>
#include <vector>

#include "app.h"
#include "menu.h"
#include "handler.h"
#include "MainMenu.h"

void Menu::menu()
{
    /*
        Реализация меню
    */
    SDL_SetRenderDrawColor(mRenderer, 0x26, 0x24, 0x5D, 0x00);
	SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    std::string path = "./pictures/";
    std::vector<std::string> imgPaths;

    for (int i = 1; i <= 5; i++)
        imgPaths.push_back(path + std::to_string(i) + ".jpg");
    std::vector<std::string> piecesNum = { "4","8","35"};
    pieceIndex = 0;
    int imgIndex = 0;

    bool ex = false;
    Handler menuHandle;
    std::string res;
    int x_name = 390;
    int y_name = 340;

    int get_name = 0;
    int new_user = 0;

    while (!ex) {
        std::string rc = menuHandle.getEvent("Menu");
        std::cout << "Rc " << rc << std::endl;
        std::cout << "After rc";
        if (rc == "START") {
                std::cout << "What start\n";
            //work_with_file(WRITE_FILE, username, MY_NAME);
            *event_menu = "START";
            pieceIndex = 0;
            *pictPath = imgPaths[imgIndex];
            *pieces = pieceIndex;
            ex = true;
        }
        std::cout << "What 0\n";
        makeTitle(mRenderer, "Выбор картинки", 60, 130);
        std::cout << "What 1\n";
        makeTitle(mRenderer, "Количество пазл", 55, 400);
        makeTitle(mRenderer, "<", 30, 250);
        makeTitle(mRenderer, ">", 300, 250);
        makeTitle(mRenderer, "<", 30, 450);
        makeTitle(mRenderer, ">", 300, 450);
        makeTitle(mRenderer, "START", 640, 390);
        makeTitle(mRenderer, "Сменить Имя", 590, 430);
        makeTitle(mRenderer,"Выход", 10, 10);
        makeTitle(mRenderer,"Основное меню", 110, 10);
        makePict(mRenderer, imgPaths[imgIndex], 87, 180, 170, 170);

        makeTitle(mRenderer, piecesNum.at(pieceIndex), 165, 450);

        makeTitle(mRenderer, "TOP 10 Игроков(в секундах)", 500, 10);
        int counter = 40;
        std::cout << "What \n";
        std::cout << games_top->size();
        std::cout << "What 2 \n";

        if(games_top->size() > 0)
        {
            for (int i = 0; i < games_top->size(); ++i)
            {
                    if(i == 9)
                    {
                        break;
                    }
                        game_user ig = games_top->at(i);
                        std::cout << "make titile " << ig.name << " " << ig.count << "\n";
                        makeTitle(mRenderer, ig.name + " : " + std::to_string(ig.count), 590, counter + 10);
                        counter += 30;
            };
        }


        /*if(get_name == 0){
            username = getName();
            get_name = 1;
        }
        if((username == "") && (new_user != 1)){
            makeTitle(mRenderer, "Enter your name: ", 340, 259);
        }else*/
        if(igrok->name != ""){
            std::string u = "Привет, " + igrok->name;
            makeTitle(mRenderer, u, x_name, y_name);
        }

        /*
        if(rc == "NEWGAMER")
        {
            makeTitle(mRenderer, "Enter your new name: ", 340, 259);
            username = "";
            new_user = 1;

        }
        if(new_user == 1 && rc != "NEWGAMER"){
            makeTitle(mRenderer, "Enter your new name: ", 340, 259);
            //if(name_user != "")
                //makeTitle(mRenderer, name_user, x_name, y_name);
        }*/

        std::string key;
        SDL_RenderPresent(mRenderer);
	    SDL_RenderClear(mRenderer);

        if (rc == "PICT_CH_BACK") {
            imgIndex--;
            if (imgIndex < 0)
                imgIndex = imgPaths.size() - 1;
        }
        else if (rc == "PICT_CH_FRONT") {
            imgIndex++;
            if (imgIndex > (int) imgPaths.size() - 1)
                imgIndex = 0;
        }

        else if (rc == "PIE_CH_BACK") {
            pieceIndex--;
            if (pieceIndex < 0)
                pieceIndex = piecesNum.size() - 1;
        }

        else if (rc == "PIE_CH_FRONT") {
            pieceIndex++;
            if (pieceIndex > (int) piecesNum.size() - 1)
                pieceIndex = 0;
        }
		else if (rc == "EXIT") {
                std::cout << "Exit";
			*pieces = -1;
			exit(1);
		} else if (rc == "MAINMENU") {
		    *event_menu = "MAINMENU";
            ex = true;
		}else if(rc == "REPLACE"){
		    *event_menu = "REPLACE";
		    ex = true;
		}


        SDL_Delay(32);
    }

}

Menu::~Menu()
{
	TTF_Quit();
}

Menu::Menu(SDL_Window *_gWindow, SDL_Renderer *_gRendrer,
        std::string *_pictPath, int *_pieces, std::string *_event_menu,
        game_user *_igrok,
        std::vector<game_user> *_games_top) :
    gWindow(_gWindow), mRenderer(_gRendrer),
    pictPath(_pictPath), pieces(_pieces), event_menu(_event_menu),
    igrok(_igrok), games_top(_games_top)
{
    TTF_Init();

    menu();
    std::cout << "NAME MENU() " << igrok->name << "\n";
}

