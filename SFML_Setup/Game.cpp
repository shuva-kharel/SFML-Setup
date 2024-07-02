#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
	:Window(sf::VideoMode(720,1080), "Game"), Player(), Texture() {
	Player.setPosition(360.f, 540.f);
	if (!Texture.loadFromFile("Media/two.jpeg"));
	Player.setTexture(Texture);
	Player.setPosition(100.f, 100.f);
}

void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time TimePerFrame = sf::seconds(1.f / 500.f);

	while (Window.isOpen()){
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update();
		}
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (Window.pollEvent(event)) {
		switch (event.type){
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed():
			Window.close();
			break;
		}
	}
}

void Game::update() {
	sf::Vector2f movement(0.f, 0.f);
	if (IsMovingUp)
		movement.y -= 1.f;
	if (IsMovingDown)
		movement.y += 1.f;
	if (IsMovingLeft)
		movement.x -= 1.f;
	if (IsMovingRight)
		movement.x += 1.f;
	if (IsJumping)
		movement.y -= 3.f;

	Player.move(movement);
}

void Game::render() {
	Window.clear(sf::Color::Black);
	Window.draw(Player);
	Window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W)
		IsMovingUp = isPressed;
	if (key == sf::Keyboard::S)
		IsMovingDown = isPressed;
	if (key == sf::Keyboard::A)
		IsMovingLeft = isPressed;
	if (key == sf::Keyboard::D)
		IsMovingRight = isPressed;
	if (key == sf::Keyboard::Space)
		IsJumping = isPressed;
}