#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


int main()
{
    string line;
    ifstream myfile ("input.txt");

    if (myfile.is_open()) {
        getline(myfile, line);
        myfile.close();
    } else cout << "unable to open file";

    //initial coordinates
    string dir = "N";
    int x = 0;
    int y = 0;
    for(int j=0; j < line.length(); j++) {
        if(line[j+1] == ',') {
        } else if ((line[j] == ' ') || (line[j]==',')) {
        } else if ( (line[j]=='R') || (line[j]=='L') ) {
            string d = ",";
            string val = (line.substr(j+1,line.find(d)-1));
            int vali = atoi( val.c_str() );
            if(dir == "N") {
                if(line[j]=='R') { dir = "E"; x = x + vali;
                } else if (line[j]=='L') { dir = "W"; x = x - vali;}
            } else if (dir == "S") {
                if(line[j]=='R') { dir = "W"; x = x - vali;
                } else if (line[j]=='L') { dir = "E"; x = x + vali;}
            } else if (dir == "E") {
                if(line[j]=='R') { dir = "S"; y = y - vali;
                } else if (line[j]=='L') { dir = "N"; y = y + vali;}
            } else if (dir == "W") {
                if(line[j]=='R') { dir = "N"; y = y + vali;
                } else if (line[j]=='L') { dir = "S"; y = y - vali;}
            }
            cout << vali << " " << dir << " " << x << " " << y << endl;
        }
    }
    cout << endl<< abs(x) + abs(y) << endl;
    return 0;
}

