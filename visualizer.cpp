#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "graph.h"


void draw_grid(Grid &g, sf::RenderWindow &);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pathfinder  ");
	Grid g;
	Graph t;

	g.make_graph(t);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.clear(sf::Color::White);	
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && g.get_start() != -1 && g.get_target() != -1) { 
			t.add_edges(g);
			t.dijkstras(g, window, g.get_start(), g.get_target());
			t.reset_graph();
		}

		draw_grid(g, window);
		g.board_edit(window);
		window.display();
	}
	return 0;
}

void draw_grid(Grid &g, sf::RenderWindow &w)
{
	for (int i = 0; i < 500; i++) 
		w.draw(g.get_square(i));
}