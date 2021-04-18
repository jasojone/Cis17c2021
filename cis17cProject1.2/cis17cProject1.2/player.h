#pragma once
#include <string>
#include <map>

using namespace std;



class player
{
public:
    player()
    {
        map<string, int> playerInfo;
    };
    player(const player& orig);
    virtual ~player();
private:

};

