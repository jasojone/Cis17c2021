#include <iostream>
#include <cmath>

using namespace std;

unsigned int ELFHash(const std::string& str)
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

unsigned int APHash(const std::string& str)
{
    unsigned int hash = 0xAAAAAAAA;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ str[i] * (hash >> 3)) :
            (~((hash << 11) + (str[i] ^ (hash >> 5))));
    }

    return hash;
}

bool search(bool* bitarray, int arrSize, string s)
{
    return (bitarray[ELFHash(s) % arrSize] && bitarray[APHash(s) % arrSize]);
}

void push(bool* bitarray, int arrSize, string s)
{
        bitarray[ELFHash(s) % arrSize] = true;
        bitarray[APHash(s) % arrSize] = true;

        cout << s << " added to bloom filter" << endl;
}

int main()
{
    const int arrSize = 6;
    bool bitarray[arrSize];
    int falsePosCnt = 0;

    for (int i = 0; i < arrSize; i++)
        bitarray[i] = false;
    
    string nArrayIn[4] = { "mark", "jason", "ansh", "omar" };
    for (int i = 0; i < 4; i++) {
        push(bitarray, arrSize, nArrayIn[i]);
    }

    string nArrayNotIn[4] = { "joe", "john", "gaddis", "ondol" };
    for (int i = 0; i < 4; i++) {
        if (search(bitarray, arrSize, nArrayNotIn[i]))
            falsePosCnt++;
    }
    
    // simulating the values 
    int x = 0;
    cout << "\n\n4 names searched that we know do not exist in the bit vector" << endl;
    cout << "the number of potential collisions: " << falsePosCnt << endl;
    x = falsePosCnt / 4.0 * 100;
    cout << "the simulated false positive percentage is: " << x << "%" << endl;
    
    // calculating the expected values  
    int n = arrSize;
    int m = 4;
    int k = 2;
    int p = 0;
    
    //P = (1-e^-km/n)^k*100 where P = percentage probability of false positives.
    p = pow(1.0 - exp(-k * m / static_cast<double>(n)), static_cast<double>(k)) * 100;
    cout << "the calculated probability of a false positive: " << p << "%" << endl;
    return 0;
}