//
// Created by bk296745 on 21/01/2022.
//

#include <fstream>
#include <iostream>
#include "listVille.h"

using namespace std;

listVille::listVille() {
    string line;

    string name;
    int latitude;
    int longitude;
    int num;

    int start;
    int end;

    ifstream file;
    file.open("C:/users/bk296745/Desktop/RO/top80.txt", ios_base::in);

    if(file.is_open()){
        getline(file, line);
        cout << line;

        while (!file.eof()){
            start = 0;
            end = line.find(" ");
            while(end != -1){
                cout << line.substr(start, end - start);
                start = end + 1;
                end = line.find(" ", start);

                cout << line.substr(start, end - start) << endl;

                getline(file, line);
            }
        }

        file.close();
    }else{
        cout << "Impossible de lire le fichier";
    }
}

void listVille::insert(ville newVille) {

}


