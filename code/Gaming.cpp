#include "Gaming.h"

#include "handler.h"
#include "app.h"
void add_to_session_stat(game_user u);
Gaming::Gaming(SDL_Window *_gWindow, SDL_Renderer *_gRendrer, std::string *_ev_res,
                            int *_pieceIndex, std::string *_pictPath,
                            game_user *_u,
                           std::vector<game_user> *_games_top,
                           std::vector<game_user> *_session):
                            gWindow(_gWindow), mRenderer(_gRendrer),
                            event_menu(_ev_res), pieceIndex(_pieceIndex),
                            pictPath(_pictPath),
                            igrok(_u),
                            games_top(_games_top),
                            session_stat(_session)
{
    TTF_Init();
    //name_user = read_from_file(MY_NAME);
    int rows = 0,
        cols = 0;
    if (*pieceIndex != -1) {

        if (*pieceIndex == 0) {
            rows = 2;
            cols = 2;
        }
        else if (*pieceIndex == 1) {
            rows = 2;
            cols = 4;
        }
        else if (*pieceIndex == 2) {
            rows = 5;
            cols = 7;
        }

        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        setTiles(*pictPath, rows, cols);
        puzzle();
        SDL_RenderClear(mRenderer);
        *pieceIndex = 0;
        *pictPath = "";

    }
}
void Gaming::setTiles(std::string image, int row, int col)
{
     SDL_Surface* surf = IMG_Load(image.c_str());

    if (surf == nullptr)
        std::cout << IMG_GetError() << std::endl;
    //обрезаю по строке
    this->clipPerRow = row;
    //обрезаю колонну
    this->clipPerColumn = col;

    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(mRenderer, surf);
    SDL_FreeSurface(surf);

    //получакю ширину пазла, делением ширины изображения на кол-во строк
    int textureWidth = IMAGE_WIDTH / this->clipPerRow;
    //получакю высоту пазла, делением высоты изображения на кол-во столбцов
    int textureHeight = IMAGE_HEIGHT / this->clipPerColumn;

    std::default_random_engine gen;
    gen.seed(std::random_device()());
    //Вернуть рандомное число из диапазона
    std::uniform_int_distribution<int>
        randX(textureWidth, SCREEN_WIDTH - textureWidth);
    std::uniform_int_distribution<int>
        randY(textureHeight, SCREEN_HEIGHT - textureHeight);
    int pos = 0;
    for (int i = 0; i < clipPerRow; i++) {
        for (int j = 0; j < clipPerColumn; j++) {
            SDL_Texture *clip =
                SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_TARGET,
                        IMAGE_WIDTH / this->clipPerRow,
                        IMAGE_HEIGHT / this->clipPerColumn);
            SDL_SetTextureBlendMode(clip, SDL_BLENDMODE_BLEND);

            SDL_Rect rect = {
                i * IMAGE_WIDTH / this->clipPerRow,
                j * IMAGE_HEIGHT / this->clipPerColumn,
                textureWidth,
                textureHeight
            };

            SDL_SetRenderTarget(mRenderer, clip);
            SDL_RenderCopy(mRenderer, imageTexture, &rect, NULL);

            rect.x = randX(gen);
            rect.y = randY(gen);
            pos += 1;
            this->tiles.push_back(new Tile(clip, rect, pos));

        }
    }

	SDL_DestroyTexture(imageTexture);

    time_game_start = clock();
}

void Gaming::drawPuzzle()
{
    int ticksPresent = SDL_GetTicks();

    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00,0x00,0x00);
    SDL_RenderClear(mRenderer);
    int pos = 0;
    for (int i = 0; i < this->clipPerRow; i++) {
        for (int j = 0; j < this->clipPerColumn; j++) {

            Tile *tmp_tile = this->tiles[pos];

            SDL_Rect rect = {
                tmp_tile->rect.x,
                tmp_tile->rect.y,
                IMAGE_WIDTH / this->clipPerRow,
                IMAGE_HEIGHT / this->clipPerColumn
            };

            SDL_RenderCopy(mRenderer, tmp_tile->clip, NULL, &rect);

            this->tiles[pos]->rect.x = rect.x;
            this->tiles[pos]->rect.y = rect.y;
            pos += 1;
        }
    }
    makeTitle(mRenderer,"Выход", 500, 50);
    makeTitle(mRenderer,"Меню", 600, 50);
    SDL_RenderPresent(mRenderer);

    ticksPresent = SDL_GetTicks() - ticksPresent;
    //if (ticksPresent < TICK_LIMIT)
        //SDL_Delay(TICK_LIMIT - ticksPresent);
}

void Gaming::puzzle()
{

    SDL_SetRenderTarget(mRenderer, NULL);


    Handler puzzleHandle(tiles);
    int win = 0;
    bool ex = false;

    int pieceIndex = 0;
    while (!ex) {
        std::string rc = puzzleHandle.getEvent("Puzzle");
        if (rc == "EXIT")
            exit(1);
        if(rc == "MENU")
        {

            *event_menu = "MENU";
            ex = true;
        }
        if(win != 1 && check_win() == 1) {
            drawPuzzle();
        }else if(win == 0)
        {
            SDL_RenderClear(mRenderer);

            igrok->count = time_game;
            std::cout << igrok->count;
            win = 1;
            //im here stop

            add_to_games_top(*igrok, games_top);
            add_to_session_stat(*igrok, session_stat);
            write_state(GAMES_FILE, games_top);
            write_state(SESSION_FILE, session_stat);


            std::string str = "You won in " + std::to_string(time_game) + " sec";
            ex = true;
            drawMessage(str);

        };
    };

};
void Gaming::drawMessage(std::string mess)
{
    SDL_SetRenderTarget(mRenderer, NULL);

    SDL_SetRenderDrawColor(mRenderer, 0x64, 0x95, 0xFF, 0xFF);
    SDL_RenderClear(mRenderer);

    bool ex_win = false;
    Handler h;
    while(!ex_win)
    {
        std::string rc = h.getEvent("WINNER");
        makeTitle(mRenderer,mess, 250, 250);
        makeTitle(mRenderer,"Выход", 500, 50);
        makeTitle(mRenderer,"Меню", 600, 50);
        SDL_RenderPresent(mRenderer);

        if(rc == "EXIT")
        {
            std::cout << "Exit\n";
            exit(1);
        }
        if(rc == "MENU")
        {
            std::cout << "MENU\n";
            SDL_RenderClear(mRenderer);
            ex_win = true;
            *event_menu = "MENU";
        }
    }

}
int Gaming::check_win()
{

    //Проверяю победу
    int x_pred;
    int y_pred;

    int x_curr;
    int y_curr;

    int w = this->tiles[0]->rect.w;
    int h = this->tiles[0]->rect.h;

    int counter_win = 1;

    for(int i = 1; i < tiles.size(); ++i){
        x_pred = tiles[i-1]->rect.x;
        y_pred = tiles[i-1]->rect.y;

        x_curr = tiles[i]->rect.x;
        y_curr = tiles[i]->rect.y;

        if(x_curr == x_pred)
        {
            counter_win += 1;
        }else if(i == clipPerColumn)
        {
            if(x_pred == x_curr - w)
            {
                counter_win += 1;
            }
        }
        if(counter_win == this->tiles.size()){
            time_game_finish = clock();
            time_game = (time_game_finish - time_game_start) / CLOCKS_PER_SEC;

            return 0;
        }
    }
    return 1;
}

