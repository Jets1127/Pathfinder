#pragma once
#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge {

public:
	Edge() = default; 
	Edge(int a, int b) : begin(a), end(b), weight(50) {}
	int get_begin() { return begin; }
	int get_end() { return end; }
	double get_weight() { return weight; }

	void print_ees()
	{
		std::cout << "Begin: " << begin << " " << "End: " << end << std::endl; 
	}

private:
	int begin;
	int end;
	double weight; 
};

#endif 
