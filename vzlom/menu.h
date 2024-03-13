#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Background
{
    public:
        Background(const char* image_path, float x_pos, float y_pos);

        void Draw(RenderWindow* window);

    private:
        Sprite  sprite;
        Image   image;
        Texture texture;
};

class Button 
{
    public:
        Button(const char* button_text, const char* bg_image_path, float x_pos, float y_pos);
    
        bool IsMouseOver(RenderWindow* window);
    
        void Draw(RenderWindow* window);

    private:
        RectangleShape shape;
        
        Text text;
        Font text_font;

        Image   bg_image;
        Texture bg_texture;
};

void DisplayStartMenu(RenderWindow* window, const char* prog_name);
void DisplayEndMenu  (RenderWindow* window);

void PlayMenuSound(Sound* sound, SoundBuffer* buffer);