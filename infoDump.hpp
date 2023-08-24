#ifndef InfoDump_Defined
#define InfoDump_Defined

#include <iostream>
#include <string>
#include <vector>


#include "player.hpp"

using namespace std;


int parameterToN(string parameter, vector<string> allNames){
    vector<string>::iterator found;
    found = find(allNames.begin(), allNames.end(), parameter);

    if(found == allNames.end()){
        return -1;
    } else {
        return distance( allNames.begin(), found );
    }


}


void sortedBy(vector<vector<string>> info, string parameterString){


   

    auto comp = [](vector<string> p1, vector<string> p2, int sortIndex)
    {
        return p1[sortIndex].compare(p2[sortIndex]) > 0;
    };

    set<vector<string>, decltype(comp)> playerSet(comp);

     for (int i = 0; i < info.size(); i++){
        playerSet.insert(info[i]);

     }

     // print

    int topn = 10;
    int i = 0;
//     for(set<vector<string>>::iterator it = playerSet.begin(); i < topn && it != playerSet.end(); it++){

//     cout << it->begin()[0] << " | " << endl;
//     //  cout << iterator->name << " | ";
//     //  for (string pos : iterator->positions){
//     //     cout << pos << " ";
//     //  } 
//     //  cout << "| Rating: " << iterator->totalRating / iterator->ratingCount << " | ";
//     //  cout << "Count: " << iterator->ratingCount << endl;

//      i++;
//   }


    for (vector<string> const& player : playerSet)
    {
        if(i == topn) break;
        std::cout << player[1] << endl;
        i++;
    }

    return;
}


#endif