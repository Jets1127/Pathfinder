#include "node.h"
#include <iostream>

void Node::add_nodes(sf::RectangleShape &a, int b)
{
	node = a;
	vertex_num = b;
	x_cord = a.getPosition().x;
	y_cord = a.getPosition().y;
}

void Node::add_adjacency(int a)
{
	adjacent_nodes.push_back(a);
}

void Node::print_adjacency()
{
	for (auto i : adjacent_nodes)
		std::cout << i << std::endl; 

	std::cout << " " << std::endl; 
}

void Node::print_n()
{
	std::cout << "Node: " << vertex_num << std::endl; 
	std::cout << "X-coordinate: " << x_cord << std::endl; 
	std::cout << "Y-coordinate: " << y_cord << std::endl;
	std::cout << " " << std::endl; 
}

void Node::set_col(const sf::Color c)
{
	node.setFillColor(c);
}

void Node::erase_adjacency()
{
	adjacent_nodes.erase(adjacent_nodes.begin(), adjacent_nodes.end());
}