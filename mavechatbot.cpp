#include <iostream>
#include <fstream>
#include <sstream>
#include "mavechatbot.h"
using namespace std;
mavebot::mavebot(const string& filename) : respondnumber(0){
    ifstream file(filename);
    if(!file.is_open()){
        cerr << filename << "'s not opened.\n";
        return;
    } while(respondnumber < 1000 && getline(file, responses[respondnumber].question)){
        string line;
        if(!getline(file, line)){
            cerr << filename << "'s respond data is not found!\n";
            break;
        }
        istringstream iss(line);
        int i = 0;
        while(i < 100 && getline(iss, responses[respondnumber].responses[i], '|'))
            i++;
        responses[respondnumber].respondnumber = i;
        respondnumber++;
    }
    file.close();
}
void mavebot::startchat(){
    string inp;
    cout << "Mave Bot: Hello! What do you wanna talk about?\n";
    while(true){
        cout << "You: ";
        getline(cin, inp);
        if(inp == "exit" || inp == "bye" || inp == "see you"){
            cout << "Mave Bot: See you again!\n";
            break;
        }
        string response = respond(inp);
        cout << "Mave Bot: " << response << "\n";
    }
}
string mavebot::respond(const string& inp){
    for(int i = 0; i < respondnumber; i++){
        if(inp == responses[i].question){
            if(responses[i].respondnumber > 0){
                int resp = rand() % responses[i].respondnumber;
                return responses[i].responses[resp];
            }
        }
    }
    return "Sorry my idiotic creator didn't add an answer for that, can you try something else?\n";
}