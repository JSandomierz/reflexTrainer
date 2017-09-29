#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Timer.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Reflex tester");
    sf::Event e;
    short score=0,secondsToChange;
    bool isColorChanged=false;
    vector<double> times;
    Timer t;
    srand(time(NULL));
    secondsToChange=rand()%6+2;
    t.start();
    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type==sf::Event::Closed) window.close();
            if(e.type==sf::Event::KeyPressed)
            {
                t.stop();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isColorChanged){
                    cout<<t.getMilliseconds()<<endl;
                    times.push_back(t.getMilliseconds());
                    score++;
                }
                else cout<<"Falstart!\n";
                isColorChanged=false;
                secondsToChange=rand()%6+2;
                if(score==10){
                    double sum=0;
                    for(double i:times) sum+=i;
                    cout<<"Avg time "<<sum/10<<"ms +-50ms"<<endl;
                    times.clear();
                    score=0;
                }
                t.start();
            }
            if(e.type==sf::Event::MouseButtonPressed)
            {
                isColorChanged=true;
                t.start();
            }
        }
        //check timing
        if(isColorChanged){
            window.clear(sf::Color::Red);
        }else{
            window.clear(sf::Color::Black);
            t.stop();
            if(t.getSeconds()==secondsToChange)
            {
                isColorChanged=true;
                t.start();
            }
        }
        window.display();
    }
    return 0;
}
