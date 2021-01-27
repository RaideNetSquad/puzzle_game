#include "handler.h"

std::string Handler::getPuzzleHandle()
{
    static int movedTile = -1;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }

        if (tiles.size() == 0) {
            return "UNDEFINED";
        }

        if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Coords " << x << " " << y << "\n";
            if (488 <= x && x <= 585 && 48 <= y && y <= 80)
                return "EXIT";
            if (598 <= x && x <= 705 && 48 <= y && y <= 80)
                return "MENU";

        }
        if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEMOTION) {
            if (movedTile == -1)
                break;
            int x = e.motion.xrel,
                y = e.motion.yrel;
            tiles[movedTile]->rect.x += x;
            tiles[movedTile]->rect.y += y;
        }

        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT)) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            for (int i = 0; i < (int) tiles.size(); i++) {
                SDL_Rect area = tiles[i]->rect;
                int xLow = area.x,
                    xHigh = area.x + area.w,
                    yLow = area.y,
                    yHigh = area.y + area.h;

                if (xLow < x && x < xHigh)
                    if (yLow < y && y < yHigh)
                        movedTile = i;

            }
        }

        if (e.type == SDL_MOUSEBUTTONUP){
            movedTile = -1;
        }

    }
    return "UNDEFINED";
}

std::string Handler::getMenuHandle()
{
    SDL_Event e;
    SDL_StartTextInput();

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }
        else if(e.type == SDL_TEXTINPUT)
        {
            return e.text.text;
        }

        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Coords " << x << " " << y << "\n";
            if (x >= 9 && x <= 99 && y >= 10 && y <= 40)
                return "EXIT";
            if (x >= 105 && x <= 325 && y >= 10 && y <= 40)
                return "MAINMENU";

            else if (x >= 30 && x <= 50 && y >= 250 && y <= 280)
                return "PICT_CH_BACK";
            else if (x >= 295 && x <= 316 && y >= 256 && y <= 278)
                return "PICT_CH_FRONT";

            else if (x >= 25 && x <= 50 && y >= 450 && y <= 480)
                return "PIE_CH_BACK";
            else if (x >= 295 && x <= 319 && y >= 450 && y <= 480)
                return "PIE_CH_FRONT";
            else if (x >= 630 && x <= 749 && y >= 385 && y <= 419)
                return "START";
            else if (x >= 580 && x <= 780 && y >= 430 && y <= 465)
                return "REPLACE";
        }

    }
    return "UNDEFINED";
}


std::string Handler::getUserNameHandle()
{

    SDL_StartTextInput();

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }
        else if(e.type == SDL_TEXTINPUT)
        {
            return e.text.text;
        }
        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);

            if (x >= 700 && 850 >= x && y >= 40 && 80 >= y)
                return "EXIT";
            else if (x >=240 && x <= 440 && y >= 310 && y <= 370)
                return "CONTINUE";
        }
    }
    return "UNDEFINED";
}

std::string Handler::getMainMenu(){
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }
        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Coords " << x << " " << y << "\n";
            if (x >= 434 && 510 >= x && y >= 95 && 140 >= y)
                return "MENU";
            else if (x >=370 && x <= 570 && y >= 195 && y <= 240)
                return "REPLACE";
            else if (x >=325 && x <= 620 && y >= 300 && y <= 337)
                return "RESULTS";
            else if (x >=424 && x <= 518 && y >= 395 && y <= 440)
                return "EXIT";
            }
        }
        return "UNDEFINED";
};

std::string Handler::getWindowWinner()
{
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }
        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Coords " << x << " " << y << "\n";
            if (488 <= x && x <= 585 && 48 <= y && y <= 80)
                return "EXIT";
            if (598 <= x && x <= 705 && 48 <= y && y <= 80)
                return "MENU";
            }
    }
    return "UNDEFINED";
}

std::string Handler::getEvent(std::string handle_name)
{

    if (handle_name == "Puzzle")
        return getPuzzleHandle();
    else if(handle_name == "Menu")
        return getMenuHandle();
    else if(handle_name == "UserName")
        return getUserNameHandle();
    else if(handle_name == "MainMenu")
        return getMainMenu();
    else if(handle_name == "WINNER")
        return getWindowWinner();
    else if(handle_name == "RESULTS")
        return getResult();
}

std::string Handler::getResult()
{
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return "EXIT";
        }
        else if (e.button.button == SDL_BUTTON(SDL_BUTTON_LEFT) &&
                e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            std::cout << "Coords " << x << " " << y;
            if (x >= 700 && 850 >= x && y >= 40 && 80 >= y)
                return "EXIT";
            else if(x >= 15 && x <= 400 && 70 <= y && 120 >= y)
                return "MENU";
            else if(x >= 15 && x <= 400 && 0 <= y && 60 >= y)
                return "CLEAR";
        }
    }
    return "UNDEFINED";
}

Handler::Handler() = default;

Handler::Handler(std::vector<Tile *> &_tiles) :
    tiles(_tiles) {}

