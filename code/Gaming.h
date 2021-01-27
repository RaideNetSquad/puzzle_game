#pragma once
#include "app.h"
#include <map>
//плитка
struct Tile {
    SDL_Texture *clip;
    SDL_Rect rect;
    int pos;
    Tile(SDL_Texture *_clip, SDL_Rect _rect, int _pos) :
        clip(_clip), rect(_rect), pos(_pos) {}
};
class Gaming : public App
{
    public:
        Gaming(SDL_Window *, SDL_Renderer *,
               std::string *event_menu, int *_pieceIndex,
               std::string *pictPath,
               game_user *u,
               std::vector<game_user> *games_top,
               std::vector<game_user> *session);
        ~Gaming();
    protected:
        std::vector<game_user> *games_top;
        std::vector<game_user> *session_stat;
        game_user* igrok;

        std::string *event_menu;
        SDL_Renderer *mRenderer;
        SDL_Window *gWindow;
        std::vector<Tile *> tiles;


        std::string *item_menu;
        std::string *pictPath;

        int *pieceIndex;
        int clipPerRow,
            clipPerColumn;

        void setTiles(std::string image, int rows, int cols);
        void drawPuzzle();
        void drawMessage(std::string mess);
        void puzzle();
        int check_win();
};
