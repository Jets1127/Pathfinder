#pragma once
#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>
#include "edge.h"

class Node {

public:
	Node() = default;
	Node(sf::RectangleShape &b, int c) : node(b), vertex_num(c)
	{
		x_cord = b.getPosition().x;
		y_cord = b.getPosition().y;
	}

	void add_nodes(sf::RectangleShape &b, int);
	void add_adjacency(int);
	void print_adjacency();
	std::vector<int> get_adjacency() { return adjacent_nodes; }

	sf::RectangleShape get_node() { return node; }
	int get_vnum() { return vertex_num; }
	int get_xcord() { return x_cord; }
	int get_ycord() { return y_cord; }

	void set_col(const sf::Color);
	sf::RectangleShape & get_sq() { return node; }
	void print_n();
	void erase_adjacency();

private:
	sf::RectangleShape node;
	int vertex_num;
	int x_cord;
	int y_cord;
	std::vector<int> adjacent_nodes = {};

};

#endif