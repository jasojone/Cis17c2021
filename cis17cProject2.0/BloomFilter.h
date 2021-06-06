/* 
 * File:   BloomFilter.h
 * Author: Jason
 *
 * Created on May 31, 2021, 6:42 PM
 */


#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include "Game.h"


/******************************************************************************\
BloomFilter Class                                                           
This Class will check to see if a player has played the game before by 
storing all usernames in a bloom filter bit vector. If the user has played
a welcome back will be displayed. If the user has not played the rules 
menu option will be encouraged                                            
\******************************************************************************/
#define BFarrSize 512

class BloomFilter
{

private:
    bool *bitarray;
    void getBloomData();//reads the bloom filter form text file
    void pushBloomData();//pushes bloom data to the file
    
public:
    BloomFilter();
    ~BloomFilter();
    // search the bloom filter for user case
    bool bfSearch(string s);
    // set the bloom filter in the event there is a new user case
    void bfPush(string s);
    // elf hash function 
    unsigned int ELFHash(const std::string& str);
    // aph hash function
    unsigned int APHash(const std::string& str);
    };
/******************************************************************************\
 BloomFilter constructor                                                           
 overloaded constructor that creates the bit array                                   
\******************************************************************************/
    inline BloomFilter::BloomFilter()
    {
        bitarray = new bool[BFarrSize];
        for (int i = 0; i < BFarrSize; i++)
        bitarray[i] = false;
        getBloomData();
    }
/******************************************************************************\
 BloomFilter destructor                                                           
 The destructor will delete the bit vector                                      
\******************************************************************************/
    inline BloomFilter::~BloomFilter()
    {
        pushBloomData();
        delete[] bitarray;
    }

#endif /* BLOOMFILTER_H */

