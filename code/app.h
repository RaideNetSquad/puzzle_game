#pragma once

#include <iostream>
#include <sys/stat.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <istream>
#include <random>
#include <ctime>
#include <map>
#include <cstdio>
#include <algorithm>

// include input and output archivers
//#include <boost/archive/text_oarchive.hpp>


#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
// include this header to serialize vectors
#include <boost/serialization/vector.hpp>

struct game_user{

    int count;
    std::string name;
    bool operator()(const game_user& a, const game_user& b) const
    {
        return a.count < b.count;
    }
    friend class boost::serialization::access;
    template<class archive>
    void serialize(archive& ar, const unsigned int version)
    {
        ar & count;
        ar & name;
    }
};

inline  std::istream& operator>>(std::istream &stream, game_user &v)
{
    stream >> v.count;
    stream >> v.name;
    return stream;
}

inline std::ostream& operator<<(std::ostream &stream, const game_user &v)
{
    stream << v.count << v.name;
    return stream;
}


class App
{

    protected:
        void write_state(std::string path, std::vector<game_user> *g);
        void read_state(std::string path, std::vector<game_user>*users);
        void makePict(SDL_Renderer*,std::string, int, int, int, int);
        void makeTitle(SDL_Renderer*,std::string, int, int);
    protected:
        std::vector<game_user> games_top;
        std::vector<game_user> session_stat;
        const int SCREEN_WIDTH = 950;
        const int SCREEN_HEIGHT = 600;
        const int IMAGE_WIDTH = 440;
        const int IMAGE_HEIGHT = 440;
        const int TICK_LIMIT = 1000 / 60;

        const int OPEN_FILE = 0;
        const int WRITE_TO_FILE = 1;
        const int WRITE_FILE = 2;
        const int DELETE_FILE = 5;
        const int GAMES = 3;
        const int SESSION = 4;
        const std::string GAMES_FILE = "records.dat";
        const std::string SESSION_FILE = "session.dat";


        int time_game_start;
        int time_game_finish;
        int time_game;
        int counter;
        game_user igrok;
        protected:

            void add_to_games_top(game_user u, std::vector<game_user> *);
            void add_to_session_stat(game_user u, std::vector<game_user> * s){
                if(!s->size())
                    s->push_back(u);
                else{
                    for(int i = 0; i < s->size(); ++i)
                    {

                        if(u.name != s->at(i).name){
                            s->erase(s->begin() + i);
                        }

                    }
                    s->push_back(u);
                }

            }




};
