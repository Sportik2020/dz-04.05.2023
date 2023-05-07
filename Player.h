#pragma once
#include "settings.h"
#include "cmath"
#include <list>
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int angle;
	float speed, speedx, speedy;
	int cd = fire_cooldown;
	int hp = Player_max_hp;
public:
	Player() {
		texture.loadFromFile(Player_File_Name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2);
		angle = 0;
		speed = 0.f;
	}
	void update() {
		for (int i = 0; i < 5; i++) {
			angle++;
		}
		sprite.setRotation(angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speed += 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speed -= 1.f;
		}
		if (speed < 0) speed = 0.f;
		else if (speed > 2) speed = 2.f;
		speedx = speed * sin(angle * PI / 180);
		speedy = -speed * cos(angle * PI / 180);
		sprite.move(speedx, speedy);
	}
	void fire() {}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void decreaseHp(int damage) { hp -= damage; }
	int getHp() { return hp; }
};

