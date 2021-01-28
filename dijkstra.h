#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "node.h"
#include <iostream>

class Dijkstra_Table {

public:

	Dijkstra_Table() = default;
	Dijkstra_Table(Node &b) : point(b) {}
	void set_table(Node &b, Node &e, double w) { point = b; prev = e; length = w; }
	void set_point(Node &beg) { point = beg; }
	void set_prev(Node &end) { prev = end; }
	void set_len(double l) { length = l; }

	Node & get_point() { return point; }
	Node & get_prev() { return prev; }
	double get_len() { return length; }



	void print_table_entry();

private:
	Node point;
	Node prev;
	double length = 100000;

};

#endif 