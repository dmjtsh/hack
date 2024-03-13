#include <SFML/Audio.hpp>
#include <assert.h>

#include "menu.h"
#include "hack.h"

/*
*   MENU BUTTON CLASS
*/

Button::Button(const char* button_text, const char* bg_image_path, float x_pos, float y_pos)
{
    assert(button_text   != nullptr);
    assert(bg_image_path != nullptr);

    shape.setPosition(x_pos, y_pos);
    
    bg_image.loadFromFile(bg_image_path);
    bg_texture.loadFromImage(bg_image);

    Vector2u bg_image_size = bg_image.getSize();
    shape.setSize(Vector2f(bg_image_size.x, bg_image_size.y));

    shape.setTexture(&bg_texture);

    text_font.loadFromFile("source/text_font.ttf");
    
    text.setFont(text_font);
    text.setString(button_text);
    text.setCharacterSize(32);
    
    text.setFillColor(Color::Black);
    text.setPosition(x_pos + bg_image_size.x / 2 - text.getGlobalBounds().width / 2, y_pos + bg_image_size.y / 2 - text.getGlobalBounds().height / 2);
}

bool Button::IsMouseOver(RenderWindow* window) 
{
    assert(window != nullptr);

    Vector2i  mouse_position = Mouse::getPosition(*window);
    FloatRect button_bounds  = shape.getGlobalBounds();
    
    return button_bounds.contains((Vector2f)(mouse_position));
}

void Button::Draw(RenderWindow* window)
{
    assert(window != nullptr);

    window->draw(shape);
    window->draw(text);
}

/*
*   BACKGROUND CLASS
*/

Background::Background(const char* image_path, float x_pos, float y_pos)
{
    assert(image_path != nullptr);

    image.loadFromFile(image_path);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void Background::Draw(RenderWindow* window)
{
    assert(window != nullptr);

    window->draw(this->sprite);
}

/*
*  MENU INTERFACE
*/

void DisplayStartMenu(RenderWindow* window, const char* prog_name)
{
    assert(window != nullptr);

    Background background("source/background.png", 0, 0);
    Button     button("Hack Program!", "source/button_bg.png", 300, 400);

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();

            if (event.type == Event::MouseButtonPressed) 
            {
                if (button.IsMouseOver(window)) 
                {
                    HackProgram(prog_name);
                    return;
                }
            }
        }
        
        window->clear(Color::Blue);
        background.Draw(window);
        button.Draw(window);

        window->display();
    }
}

void DisplayEndMenu(RenderWindow* window)
{
    assert(window != nullptr);

    Background background("source/finish_screen.png", 0, 0);
    
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }
        
        window->clear(Color::Blue);
        background.Draw(window);

        window->display();
    }
}

void PlayMenuSound(Sound* sound, SoundBuffer* buffer)
{
    assert(sound  != nullptr);
    assert(buffer != nullptr);

    sound->setBuffer(*buffer);
    sound->play();
}