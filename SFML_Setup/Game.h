#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


	bool IsMovingUp{ false };
	bool IsMovingDown{ false };
	bool IsMovingLeft{ false };
	bool IsMovingRight{ false };
	bool IsJumping{ false };
	sf::Texture Texture;
	sf::Sprite Player;
	sf::RenderWindow Window;
};

#endif // !_GAME_H_