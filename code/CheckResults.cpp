#include "CheckResults.h"
#include "handler.h"
CheckResults::CheckResults(SDL_Window *_gWindow, SDL_Renderer *_gRendrer, std::string *_ev_res, game_user *_igrok,
                           std::vector<game_user> *_session_stat) :
    gWindow(_gWindow), mRenderer(_gRendrer), ev_res(_ev_res), igrok(_igrok), session_stat(_session_stat)
{
    TTF_Init();

    getResults();
}

void CheckResults::getResults()
{
    SDL_SetRenderDrawColor(mRenderer, 0x26, 0x24, 0x5D, 0x00);
	SDL_RenderClear(mRenderer);
    SDL_RenderPresent(mRenderer);

    bool exitt = false;
    Handler handler;

    while(!exitt)
    {
        makeTitle(mRenderer,"Очистить результаты", 15, 20);
        makeTitle(mRenderer,"Вернуться в главное меню", 15, 90);
        std::string event_name = handler.getEvent("RESULTS");
        makeTitle(mRenderer,"Ваши результаты за эту сессию", 15, 130);
        int counter = 200;
        for(int i = 0; i < session_stat->size(); ++i){
            makeTitle(mRenderer, std::to_string(i+1) + " игра: " + std::to_string(session_stat->at(i).count), 90, counter);
            counter += 40;
        }

        if (event_name == "EXIT") {
			exit(1);
		}
		else if(event_name == "CLEAR")
		{
		    *session_stat = {};
		}
		else if(event_name != "UNDEFINED"){
            *ev_res = event_name;
            exitt = true;
		}

        SDL_RenderPresent(mRenderer);
	    SDL_RenderClear(mRenderer);

    }
}
