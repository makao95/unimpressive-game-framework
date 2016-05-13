#include "UGF/ParticleSystem.h"
#include "UGF/ResourceManager.h"
#include "UGF/BitmapFont.h"
#include "UGF/Text.h"
#include "UGF/Framecounter.h"
#include <SFML/System.hpp>
#include <iostream>

sf::RenderWindow window;

ugf::ParticleSystem* createParticlesForClick() {
    ugf::ParticleSystem* p =new ugf::ParticleSystem(sf::Lines);
    p->setColor(sf::Color::Magenta);
    p->setColorTransition(sf::Color::Transparent);
	p->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	p->setParticleLifetime(sf::seconds(0.1), sf::seconds(0.5));
	p->setParticlesPerSecond(40000);
	p->applyForce(sf::Vector2f(0,1000));
	p->setParticlesVelocity(1000);
	p->setSystemLifetime(sf::seconds(0.1));
	return p;
}

int main() {
	window.create(sf::VideoMode::getDesktopMode(), "Demo");
        window.setVerticalSyncEnabled(true);
//	window.setFramerateLimit(60);

    ugf::ParticleSystem particles(sf::PrimitiveType::LinesStrip);
	particles.setParticleLifetime(sf::seconds(0.5), sf::seconds(0.6));
	particles.setParticlesPerSecond(6000);
	particles.setParticlesVelocity(100);
	particles.setColor(sf::Color::Cyan);
	particles.setColorTransition(sf::Color::Red);
    particles.applyForce(sf::Vector2f(0, -700));
	particles.setSystemLifetime(sf::seconds(200));

	sf::Texture fontTexture;
	fontTexture.loadFromFile("pixel.png");

	ugf::BitmapFont bitmapFont;
    bitmapFont.setTexture(ugf::ResourceManager::getInstance().getTexture("pixel.png"));
	bitmapFont.loadCharactersFromFile("pixel.txt");

	ugf::Text text;
	text.setFont(bitmapFont);
	text.setText("Liczba czasteczek: 0");
	text.setColor(sf::Color::Yellow);
	text.setPosition(sf::Vector2f(20, 20));
	text.setScale(2);

	int i = 0;
	std::vector<ugf::ParticleSystem*> actors;
	ugf::FrameCounter frameCounter;
	while(window.isOpen()) {
		sf::Event event;
        while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseMoved) {
                particles.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
//                actors.at(0).setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
			} else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
					ugf::ParticleSystem *p = createParticlesForClick();
					actors.push_back(p);
				}
			}
		}

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
            particles.setParticleLifetime(sf::seconds(1), sf::seconds(1));
            particles.setColorTransition(sf::Color::Transparent);
            particles.setColor(sf::Color::Green);
        }else{
            particles.setParticleLifetime(sf::seconds(0.5), sf::seconds(0.6));
            particles.setColorTransition(sf::Color(205, 0, 0, 10));
            particles.setColor(sf::Color::Cyan);
        }

        particles.update(sf::seconds(1/60.0f));
//        particles.update(sf::seconds(1.0f/300.0f));
        window.draw(particles);
		int particlesCount = particles.getParticlesCount();
		for (auto actor : actors) {
			actor->update(sf::seconds(1/60.f));
			window.draw(*actor);
			particlesCount += actor->getParticlesCount();
		}
		i++;
		if (i>20) {
			text.setText("Liczba czasteczek: " + std::to_string(particlesCount));
			text.setScale(2);
			i = 0;
		}
		window.draw(text);
		window.display();
		frameCounter.countFrame();
		window.clear(sf::Color::Black);
		window.setTitle("FPS: " + std::to_string(frameCounter.getFPS()));
	}
	return 0;
}
