#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <sstream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    //-----------------------beginned processing data----------------------------------//
    int max = 2600; // max row 2573

    fstream f;
    fstream fout;
    f.open("BTC-USD.csv");
    string date[max], line, temp;

    // high, low, volume, second dimension is the date
    double bitcoin_price[3][max]; 

    vector <string> row;
    int index = 0;
    getline(f, line); //get rid of first line 

    // read data 
    while (!f.eof())
    {
        row.clear();
        getline(f, line);
        stringstream s(line);
        while (s.good())
        {
            string substr;
            getline(s, substr, ',');
            row.push_back(substr);
        }
        bitcoin_price[0][index] = stod(row[2]); // high
        bitcoin_price[1][index] = stod(row[3]); // low
        bitcoin_price[2][index] = stod(row[5]); // volume
        // cout << bitcoin_price[0][index] <<" " << bitcoin_price[1][index] <<" " << bitcoin_price[2][index] << endl;
        index++;
    }
    f.close();
    //-----------------------finished processing data----------------------------------//



    return 0;
}