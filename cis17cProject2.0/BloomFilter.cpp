/* 
 * File:   BloomFilter.cpp
 * Author: Jason
 *
 * Created on May 31, 2021, 6:43 PM
 */
#include "BloomFilter.h"
/******************************************************************************\
 bfSearch
 This function will search the bit vector for the event of a positive flag set                                                           
\******************************************************************************/
bool BloomFilter::bfSearch(string s)
{
  return (bitarray[ELFHash(s) % BFarrSize] && bitarray[APHash(s) % BFarrSize]);
}

/******************************************************************************\
 bfPush                                                           
 This function will push the hashed name to the bitvector setting two flags 
\******************************************************************************/
void BloomFilter::bfPush(string s)
{
   bitarray[ELFHash(s) % BFarrSize] = true;
   bitarray[APHash(s) % BFarrSize] = true;
}

/******************************************************************************\
 ELFHash                                                           
\******************************************************************************/
unsigned int BloomFilter::ELFHash(const std::string& str)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = (hash << 4) + str[i];
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }
        hash &= ~x;
    }

    return hash;
}

/******************************************************************************\
 APHash                                                           
\******************************************************************************/
unsigned int BloomFilter::APHash(const std::string& str)
{
    unsigned int hash = 0xAAAAAAAA;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ str[i] * (hash >> 3)) :
            (~((hash << 11) + (str[i] ^ (hash >> 5))));
    }

    return hash;
}

/******************************************************************************\
 getBloomData                                                           
 This function populate the bitvector from the binary file save data.  
\******************************************************************************/
void BloomFilter::getBloomData()
{
    ifstream file ("bloomFilter.bin", ios::binary|ios::in);
    file.read(reinterpret_cast<char *>(bitarray), sizeof(bool) * BFarrSize);
    file.close();
}

/******************************************************************************\
 bfPush                                                           
 This function will save the bloom filter bitvector to a binary file  
\******************************************************************************/
void BloomFilter::pushBloomData()
{
    ofstream file ("bloomFilter.bin", ios::binary|ios::out);
    file.write(reinterpret_cast<char *>(bitarray), sizeof(bool) * BFarrSize);
    file.close();
}