#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

int main()
{
    int arr[3] = { 0, 1, 1 };
    int size = 3;
    int end = 0, begin = 0, step = 0;

    sf::RenderWindow window(sf::VideoMode(300, 400), "Traffic Light");

    sf::RectangleShape base(sf::Vector2f(100, 300));
    base.setFillColor(sf::Color(0, 0, 0));
    base.setPosition(sf::Vector2f(50, 50));


    sf::CircleShape RedOn(25);
    RedOn.setOutlineThickness(1);
    RedOn.setPosition(sf::Vector2f(75, 75));
    RedOn.setFillColor(sf::Color(255, 0, 0));
    RedOn.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape YellowOn(25);
    YellowOn.setOutlineThickness(1);
    YellowOn.setPosition(sf::Vector2f(75, 150));
    YellowOn.setFillColor(sf::Color(255, 255, 0));
    YellowOn.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape GreenOn(25);
    GreenOn.setOutlineThickness(1);
    GreenOn.setPosition(sf::Vector2f(75, 225));
    GreenOn.setFillColor(sf::Color(0, 255, 0));
    GreenOn.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape RedOff(25);
    RedOff.setOutlineThickness(1);
    RedOff.setPosition(sf::Vector2f(75, 75));
    RedOff.setFillColor(sf::Color(128, 128, 128));
    RedOff.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape YellowOff(25);
    YellowOff.setOutlineThickness(1);
    YellowOff.setPosition(sf::Vector2f(75, 150));
    YellowOff.setFillColor(sf::Color(128, 128, 128));
    YellowOff.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape GreenOff(25);
    GreenOff.setOutlineThickness(1);
    GreenOff.setPosition(sf::Vector2f(75, 225));
    GreenOff.setFillColor(sf::Color(128, 128, 128));
    GreenOff.setOutlineColor(sf::Color(255, 255, 255));

    sf::CircleShape lights[3][2] = { {RedOn, RedOff}, {YellowOn, YellowOff}, {GreenOn, GreenOff} };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(255, 255, 255));


        for (int n = 0; n < 2; n++)
        {
            if (!(n % 2)) {
                begin = size - 1;
                end = 0;
                step = -1;
            }
            else {
                begin = 0;
                end = size - 1;
                step = 1;
            }

            for (int i = 0; i < size-1; i++)
            {
                int x = arr[begin];
                for (int j = begin; j != end; j += step)
                    arr[j] = arr[j + step];
                arr[end] = x;

                window.draw(base);
                window.draw(lights[0][arr[0]]);
                window.draw(lights[1][arr[1]]);
                window.draw(lights[2][arr[2]]);
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                window.clear(sf::Color(255, 255, 255));
            }
            std::cout << "\n";
        }
    }

    return 0;
}