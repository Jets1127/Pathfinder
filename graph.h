#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "grid.h"
#include "node.h"
#include "dijkstra.h"


class Graph {

	friend class Grid;

public:
	Graph() { nodes = {}; }
	void add_node(sf::RectangleShape &b, int c);
	std::vector<Node> get_nodes() { return nodes; }
	void print_nodes();

	void get_adjacency(int i, Grid &);
	int get_node_by_location(int, int);
	void get_horizontal_adjacency(int i, Grid &);
	void get_vertical_adjacency(int i, Grid &);

	bool check_edge(int, int, std::vector<Edge> &);
	std::vector<Edge> get_edges() { return edges; }
	void add_edges(Grid &g);

	void dijkstras(Grid &g, sf::RenderWindow &w, int beg, int end);
	Edge & find_edge(int, int);
	void update_table(double, int, Node &b, std::vector<Dijkstra_Table> &m);
	double get_prev_dist(Node &, std::vector<Dijkstra_Table> &f);
	void drawing(Grid &g, sf::RenderWindow &f);
	void find_shortest_path(int, int, std::vector<Dijkstra_Table> &m, std::vector<int> &);

	bool check_node(int);
	bool check_list(std::vector<Node> &, int);
	Node & get_node(int);

	void remove_edges();
	void remove_as();
	void reset_graph();

private:
	std::vector<Node> nodes;
	std::vector<Edge> edges;

};

#endif 