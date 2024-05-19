#include <iostream>
using namespace std;
class mavebot{
    public:
        mavebot(const string& filename);
        void startchat();
    private:
        struct response{
            string question;
            string responses[100];
            int respondnumber;
        };
        string respond(const string& inp);
        response responses[1000];
        int respondnumber;
};