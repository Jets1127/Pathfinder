#include "dijkstra.h"

void Dijkstra_Table::print_table_entry()
{
	std::cout << "Point: " << point.get_vnum() << std::endl; 
	std::cout << "Previous Vertex: " << prev.get_vnum() << std::endl; 
	std::cout << "Min Distance: " << get_len() << std::endl; 
	std::cout << " " << std::endl; 
}