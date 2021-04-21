/*
 * File:   Card.h
 * Author: Jason
 *
 * Created on April 14, 2021, 8:25 AM
 */
 /*****************************************************************************\
 * Card.h                                                                      *
 * This header file will contain the attributes of the card.                   *
 * Attributes: the cards suit, the power of the card and the cards ascii art.  *
 \*****************************************************************************/
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <map>

using namespace std;

class Card
{
public:
    string suit;    // cards suit 
    int cPower;     // power of the card to determine who will win the round
    Card(string s, int p)
    {
        suit = s;
        cPower = p;
    }
    //cardArt is the map with a nested map that contains cars ascii visual art
    // H   C   D   S 
    map<string, map<int, string>> cardArt =
    {
        {"CLUBS",
        {

        {2, ".------.\n|2    C|\n|  ()  |\n| ()() |\n|C    2|\n`------'\n"},
        {3, ".------.\n|3    C|\n|  ()  |\n| ()() |\n|C    3|\n`------'\n"},
        {4, ".------.\n|4    C|\n|  ()  |\n| ()() |\n|C    4|\n`------'\n"},
        {5, ".------.\n|5    C|\n|  ()  |\n| ()() |\n|C    5|\n`------'\n"},
        {6, ".------.\n|6    C|\n|  ()  |\n| ()() |\n|C    6|\n`------'\n"},
        {7, ".------.\n|7    C|\n|  ()  |\n| ()() |\n|C    7|\n`------'\n"},
        {8, ".------.\n|8    C|\n|  ()  |\n| ()() |\n|C    8|\n`------'\n"},
        {9, ".------.\n|9    C|\n|  ()  |\n| ()() |\n|C    9|\n`------'\n"},
        {10, ".------.\n|10   C|\n|  ()  |\n| ()() |\n|C   10|\n`------'\n"},
        {11, ".------.\n|J    C|\n|  ()  |\n| ()() |\n|C    J|\n`------'\n"},
        {12, ".------.\n|Q    C|\n|  ()  |\n| ()() |\n|C    Q|\n`------'\n"},
        {13, ".------.\n|K    C|\n|  ()  |\n| ()() |\n|C    K|\n`------'\n"},
        {14, ".------.\n|A    C|\n|  ()  |\n| ()() |\n|C    A|\n`------'\n"}
        }
    },
    {"DIAMONDS",
        {
        {2, ".------.\n|2    D|\n|  /\\  |\n|  \\/  |\n|D    2|\n`------'\n"},
        {3, ".------.\n|3    D|\n|  /\\  |\n|  \\/  |\n|D    3|\n`------'\n"},
        {4, ".------.\n|4    D|\n|  /\\  |\n|  \\/  |\n|D    4|\n`------'\n"},
        {5, ".------.\n|5    D|\n|  /\\  |\n|  \\/  |\n|D    5|\n`------'\n"},
        {6, ".------.\n|6    D|\n|  /\\  |\n|  \\/  |\n|D    6|\n`------'\n"},
        {7, ".------.\n|7    D|\n|  /\\  |\n|  \\/  |\n|D    7|\n`------'\n"},
        {8, ".------.\n|8    D|\n|  /\\  |\n|  \\/  |\n|D    8|\n`------'\n"},
        {9, ".------.\n|9    D|\n|  /\\  |\n|  \\/  |\n|D    9|\n`------'\n"},
        {10, ".------.\n|10   D|\n|  /\\  |\n|  \\/  |\n|D   10|\n`------'\n"},
        {11, ".------.\n|J    D|\n|  /\\  |\n|  \\/  |\n|D    J|\n`------'\n"},
        {12, ".------.\n|Q    D|\n|  /\\  |\n|  \\/  |\n|D    Q|\n`------'\n"},
        {13, ".------.\n|K    D|\n|  /\\  |\n|  \\/  |\n|D    K|\n`------'\n"},
        {14, ".------.\n|A    D|\n|  /\\  |\n|  \\/  |\n|D    A|\n`------'\n"}
        }
    },
    {"HEARTS",
        {
        {2, ".------.\n|2   H |\n| (\\/) |\n|  \\/  |\n|H    2|\n`------'\n"},
        {3, ".------.\n|3   H |\n| (\\/) |\n|  \\/  |\n|H    3|\n`------'\n"},
        {4, ".------.\n|4   H |\n| (\\/) |\n|  \\/  |\n|H    4|\n`------'\n"},
        {5, ".------.\n|5   H |\n| (\\/) |\n|  \\/  |\n|H    5|\n`------'\n"},
        {6, ".------.\n|6   H |\n| (\\/) |\n|  \\/  |\n|H    6|\n`------'\n"},
        {7, ".------.\n|7   H |\n| (\\/) |\n|  \\/  |\n|H    7|\n`------'\n"},
        {8, ".------.\n|8   H |\n| (\\/) |\n|  \\/  |\n|H    8|\n`------'\n"},
        {9, ".------.\n|9   H |\n| (\\/) |\n|  \\/  |\n|H    9|\n`------'\n"},
        {10, ".------.\n|10  H |\n| (\\/) |\n|  \\/  |\n|H   10|\n`------'\n"},
        {11, ".------.\n|J   H |\n| (\\/) |\n|  \\/  |\n|H    J|\n`------'\n"},
        {12, ".------.\n|Q   H |\n| (\\/) |\n|  \\/  |\n|H    Q|\n`------'\n"},
        {13, ".------.\n|K   H |\n| (\\/) |\n|  \\/  |\n|H    K|\n`------'\n"},
        {14, ".------.\n|A   H |\n| (\\/) |\n|  \\/  |\n|H    A|\n`------'\n"}
        }
    },
    {"SPADES",
        {
        {2, ".------.\n|2   S |\n|  /\\  |\n| (__) |\n|S    2|\n`------'\n"},
        {3, ".------.\n|3   S |\n|  /\\  |\n| (__) |\n|S    3|\n`------'\n"},
        {4, ".------.\n|4   S |\n|  /\\  |\n| (__) |\n|S    4|\n`------'\n"},
        {5, ".------.\n|5   S |\n|  /\\  |\n| (__) |\n|S    5|\n`------'\n"},
        {6, ".------.\n|6   S |\n|  /\\  |\n| (__) |\n|S    6|\n`------'\n"},
        {7, ".------.\n|7   S |\n|  /\\  |\n| (__) |\n|S    7|\n`------'\n"},
        {8, ".------.\n|8   S |\n|  /\\  |\n| (__) |\n|S    8|\n`------'\n"},
        {9, ".------.\n|9   S |\n|  /\\  |\n| (__) |\n|S    9|\n`------'\n"},
        {10, ".------.\n|10  S |\n|  /\\  |\n| (__) |\n|S   10|\n`------'\n"},
        {11, ".------.\n|J   S |\n|  /\\  |\n| (__) |\n|S    J|\n`------'\n"},
        {12, ".------.\n|Q   S |\n|  /\\  |\n| (__) |\n|S    Q|\n`------'\n"},
        {13, ".------.\n|K   S |\n|  /\\  |\n| (__) |\n|S    K|\n`------'\n"},
        {14, ".------.\n|A   S |\n|  /\\  |\n| (__) |\n|S    A|\n`------'\n"}
        }
    }
    };

    //    Card & operator = (const Card & other)
    //    {
    //        if (this == & other)
    //            return * this;
    //    }
    //    void test()
    //    {
    //        //cardArt.insert(make_pair("CLUBS", make_pair(2, "342")));
    //        cardArt.insert(make_pair("CLUBS", map<int, string>()));
    //        cardArt["CLUBS"].insert(make_pair(2, "test"));
    //
    //        //map<string, map<int, string>>::iterator itr = cardArt.begin(); itr != cardArt.end(); itr++
    //        for(auto &itr: cardArt)
    //        {
    //            cout << "Suit: " << itr.first << endl;
    //
    //            for (auto& innerITR: itr.second)
    //            {
    //                cout << "Power: " << innerITR.first << endl;
    //                cout << "Art:" << endl;
    //                cout << innerITR.second << endl;
    //            }
    //        }
    //    }
};

#endif /* CARD_H */

