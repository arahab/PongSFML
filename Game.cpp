#include"Game.h"

void RunGame (RenderWindow &window) {
	
	    srand(time(NULL));
		Image background;
		background.loadFromFile("images/Gr.png");
		Texture backgroundTexture;
		backgroundTexture.loadFromImage(background);
		Sprite backgroundSprite(backgroundTexture);
		

		Image playerImage,player2Image,ballImage;
		playerImage.loadFromFile("images/entity.png");
		player2Image.loadFromFile("images/entity.png");
		ballImage.loadFromFile("images/ball.png");

		Texture playerTexture,player2Texture,ballTexture;
		playerTexture.loadFromImage(playerImage);
		player2Texture.loadFromImage(player2Image);
		ballTexture.loadFromImage(ballImage);
	
		Sprite playerSprite,player2Sprite,ballSprite;
		playerSprite.setTexture(playerTexture);
		player2Sprite.setTexture(player2Texture);
		ballSprite.setTexture(ballTexture);


		Font font;
		font.loadFromFile("7526.ttf");
		Text text("", font, 20);
		Text text2("", font, 20);
		int y = 20 + rand() % 300;
		Clock clock;
		bool lose = false;
		Player p(playerSprite, 2, 100);
		Player2 p2(player2Sprite, 585, 100);
		Ball b(ballSprite,300, y);
		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();

			clock.restart();
			time = time / 800;
			sf::Event event;
			backgroundSprite.setPosition(0, 0);

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}


			p.update(time);
			p2.update(time);
			b.update(time);
			window.clear();
			window.draw(backgroundSprite);

			window.draw(p.sprite);
			window.draw(p2.sprite);
			window.draw(b.sprite);
			if (b.x < 0) {
				points2++;
				lose = true;
			}
			if (b.x > 595) {
				points1++;
				lose = true;
			}

			if ((b.x <= p.x + 10) && (p.y < b.y) && (b.y < p.y + 80))
			{
				b.dx *= -1;
			}
			if ((b.x >= p2.x - 10) && (p2.y - 10 < b.y) && (b.y < p2.y + 80))
			{
				b.dx *= -1;
			}
			if ((b.y > p2.y) && (b.x > 300))
				p2.dy = 0.18;
			if ((b.y < p2.y) && (b.x > 300))
				p2.dy = -0.18;
			if (b.x < 300)
				p2.dy = 0;

			std::ostringstream pointsP, pointsP2;
			pointsP << points1;
			pointsP2 << points2;
			text.setString(pointsP.str() + " : " + pointsP2.str()); 
			text.setPosition(20,300);
			window.draw(text);

			window.display();
			if (lose == true) {
				RunGame(window);
			}
		}
}