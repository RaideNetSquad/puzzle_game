#include <iostream>
#include <map>
#include "game.h"
/*
const int OPEN_FILE = 0;
        const int WRITE_TO_FILE = 1;
        const int WRITE_FILE = 2;
        const int DELETE_FILE = 5;
        const int GAMES = 3;
        const int MY_NAME = 4;
        const std::string GAMES_FILE = "records.txt";
        const std::string MYNAME_FILE = "myname.txt";
void work_with_file(int state, std::string text, int file_curr)
{

    if(state == OPEN_FILE){
        std::ofstream file;
        if(!std::ifstream("myname.txt")){
            file.open("myname.txt");
            file.close();
        }
        if(!std::ifstream("records.txt")){
            file.open("records.txt");
            file.close();
        }
    }

    if(state == WRITE_TO_FILE){
            std::fstream file_games;
    std::fstream file_myname;
        if(file_curr == GAMES){
            file_games.open(GAMES_FILE, std::ios::app);
            if(file_games.is_open())
                file_games << text;
            std::cout << text;
            file_games.close();

        };
        if(file_curr == MY_NAME){
            file_myname.open(MYNAME_FILE, std::ios::app);
            if(file_myname.is_open())
                file_myname << text << "\n";
            file_myname.close();

        };
    };
    if(state == WRITE_FILE){
            std::fstream file_games;
    std::fstream file_myname;
        if(file_curr == GAMES){
            file_games.open(GAMES_FILE);
            if(file_games.is_open())
                file_games << text;
            file_games.close();

        };
        if(file_curr == MY_NAME){
            file_myname.open(MYNAME_FILE);
            if(file_myname.is_open())
                file_myname << text;
            file_myname.close();

        };
    };
    if(state == DELETE_FILE){
        if(file_curr == GAMES){
            const char* r = GAMES_FILE.c_str();
            std::remove(r);

        };
        if(file_curr == MY_NAME){
            const char* r = MYNAME_FILE.c_str();
            std::remove(r);
        };
    }
}

std::string read_from_file(int file_curr)
{
    std::string res;
    std::ifstream file_games;
    std::string line;
    if(file_curr == GAMES){
            file_games.open("records.txt");
            if (file_games.is_open())
            {
                while (getline(file_games, line))
                {
                    res += line;
                }
            }
            file_games.close();     // закрываем файл
            return res;
    };
    return "Error";
}*/
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    new Game();
    return 0;
}

