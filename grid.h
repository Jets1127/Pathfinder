#pragma once
#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "graph.h"

class Grid {

	friend class Graph; 

public:
	Grid() { fill_grid(); }
	void fill_grid();



	sf::RectangleShape get_square(int x) { return grrid[x]; }
	int get_square_x(int);
	int get_square_y(int);

	int locate_square(sf::RenderWindow &);
	int set_target(sf::RenderWindow &);
	int set_beg(sf::RenderWindow &);

	void board_edit(sf::RenderWindow &);
	void drawing_obstacles(sf::RenderWindow &);
	void mark_target(sf::RenderWindow &);
	void set_source(sf::RenderWindow &);
	void reset();

	int get_target() { return target; }
	int get_start() { return start; }

	void make_graph(Graph &g);

	void set_color(int i, const sf::Color c) { grrid[i].setFillColor(c); }


private:
	sf::RectangleShape grrid[500];
	int target = -1; 
	int start = -1;
};

#endif 
