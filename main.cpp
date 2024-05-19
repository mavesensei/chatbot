#include "mavechatbot.cpp"
#include <iostream>
int main() {
    mavebot bot("responses.txt");
    bot.startchat();
    return 0;
}