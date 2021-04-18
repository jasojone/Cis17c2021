/* 
 * File:   player.h
 * Author: Jason
 *
 * Created on April 14, 2021, 8:25 AM
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <string>

using namespace std;



class player 
{
public:
    player()
{
    map<string, int> playerInfo;
}
    player(const player& orig);
    virtual ~player();
private:

};

#endif /* PLAYER_H */

