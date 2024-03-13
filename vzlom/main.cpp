#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "hack.h"
#include "menu.h"

using namespace sf;

int main(int argc, const char* argv[])
{
    RenderWindow window(VideoMode(900, 900), "Super Hacker Program", Style::Default);
    SoundBuffer buffer {};            
    if (!buffer.loadFromFile("source/music.wav"))          
        return -1;
    Sound sound {};
    
    PlayMenuSound(&sound, &buffer);
    DisplayStartMenu(&window, (argc >= 2) ? (argv[1]) : "CRACKME.COM");
    DisplayEndMenu(&window);

    return 0;
}