#include "graph.h"
#include <iostream>

bool check_path(std::vector<int> p, int d)
{
	for (auto i : p) {
		if (i == d)
			return true;
	}

	return false; 

}

void Graph::print_nodes() 
{
	for (int i = 0; i < nodes.size(); i++) {
		std::cout << "Node " << nodes[i].get_vnum() << std::endl; 
		std::cout << "X-cordinate: " << nodes[i].get_xcord() << std::endl; 
		std::cout << "Y-coordinate: " << nodes[i].get_ycord() << std::endl;
		std::cout << " " << std::endl; 

		std::cout << "Adjacent nodes: " << std::endl; 
		nodes[i].print_adjacency();
		std::cout << " " << std::endl; 
	}
}

void Graph::add_node(sf::RectangleShape &b, int c)
{
	Node temp(b, c);
	nodes.push_back(temp);
}
int Graph::get_node_by_location(int x, int y)
{
	for (auto i : nodes) {
		if ((x >= i.get_xcord() && x < i.get_xcord() + 50) && (y >= i.get_ycord() && y < i.get_ycord() + 50)) { 
			return i.get_vnum();
		}
	}
}

void Graph::get_horizontal_adjacency(int i, Grid &ni)
{
	int temp = get_node_by_location(nodes[i].get_xcord() + 50, nodes[i].get_ycord());
	int temp2 = get_node_by_location(nodes[i].get_xcord() - 50, nodes[i].get_ycord());

	bool stat = check_edge(i, temp, edges);
	if (stat == false && temp < 500 &&  temp >= 0) {

		const sf::Color col1 = ni.get_square(temp).getFillColor();

		if (col1 != sf::Color::Black) {
			Edge t(i, temp);
			edges.push_back(t);
			nodes[i].add_adjacency(temp);
		}
		else{
		}
	}
	else {

	}

	bool stat2 = check_edge(i, temp2, edges);
	if (stat2 == false && temp2 < 500 && temp2 >= 0) {

		const sf::Color col2 = ni.get_square(temp2).getFillColor();
		if (col2 != sf::Color::Black) {
			Edge ti(i, temp2);
			edges.push_back(ti);
			nodes[i].add_adjacency(temp2);
		}
		else {

		}
	}
	else {

	}
		
}

void Graph::get_vertical_adjacency(int i, Grid &ni)
{
	int temp = get_node_by_location(nodes[i].get_xcord(), nodes[i].get_ycord() + 50);
	int temp2 = get_node_by_location(nodes[i].get_xcord(), nodes[i].get_ycord() - 50);

	if (temp < 500 && temp >= 0) {

		int temp_y = ni.get_square(temp).getPosition().y;
		const sf::Color col1 = ni.get_square(temp).getFillColor();

		if (col1 != sf::Color::Black && temp_y <= 950) {
			Edge t(i, temp);
			edges.push_back(t);
			nodes[i].add_adjacency(temp);
		}
		else {
			
		}
	}
	else {

	}
		

	bool stat2 = check_edge(i, temp2, edges);
	if (temp2 < 500 && temp2 >= 0) {

		int temp_y = ni.get_square(temp2).getPosition().y;
		const sf::Color col2 = ni.get_square(temp2).getFillColor();
		if (col2 != sf::Color::Black && temp_y <= 950) {
			Edge ti(i, temp2);
			edges.push_back(ti);
			nodes[i].add_adjacency(temp2);
		}
		else {
			
		}
	}
	else {

	}
		

}

void Graph::get_adjacency(int i, Grid &ger)
{
	get_horizontal_adjacency(i, ger);
	get_vertical_adjacency(i, ger);
}

bool Graph::check_edge(int x, int y, std::vector<Edge> &ees)
{
	for (auto i : ees) {
		if ((x == i.get_begin() && y == i.get_end()))
			return true;
	}

	return false; 
}

void Graph::add_edges(Grid &g)
{
	for (int i = 0; i < 500; i++) {
		get_adjacency(nodes[i].get_vnum(), g);
	}
}

void Graph::dijkstras(Grid &g, sf::RenderWindow &window, int beg, int end)
{
	bool status = true; 

	std::vector<Node> not_visited, visited;
	std::vector<Dijkstra_Table> map;
	not_visited = nodes;

	for (auto i : not_visited)
		map.push_back(Dijkstra_Table(i));

	 map[beg].set_len(0);
	 Node next;
	 next = not_visited[beg];
	 int index = 0;
	 visited.push_back(next);

	while (not_visited.size() != visited.size()) {

		Node current;

		if(index < visited.size()) {
			current = visited[index];
		}
		else {
			std::cout << "Couldn't find a path" << std::endl; 
			break;
		}

		for (auto i : current.get_adjacency()) {

			double temp = find_edge(current.get_vnum(), i).get_weight();
			if(i != beg && i != end)
				g.set_color(i, sf::Color::Cyan);
			
			next = get_node(i);
			if (!check_list(visited, i)) {
				visited.push_back(next);
			}
			drawing(g, window);
			window.display();
			update_table(temp, i, current, map);
			if (next.get_vnum() == end)
				break;
		}
		index++;
		if (next.get_vnum() == end)
			break;
		
		sf::sleep(sf::milliseconds(10));
		window.display();

	}

	std::vector<int> p = {};
	find_shortest_path(beg, end, map, p);

	for (auto i : p) {
		g.set_color(i, sf::Color::Green);
	}
}

Edge & Graph::find_edge(int beg, int end)
{
	for (auto &i : edges) {
		if (i.get_begin() == beg && i.get_end() == end)
			return i;
	}

}

void Graph::update_table(double distance, int a, Node &b, std::vector<Dijkstra_Table> &m)
{
	for (auto &i : m) {
		if (i.get_point().get_vnum() == a) {

			double temp = distance + get_prev_dist(b, m);
			if (temp < i.get_len()) {
				i.set_len(temp);
				i.set_prev(b);
			}
			break;
		}
	}

}

double Graph::get_prev_dist(Node &m, std::vector<Dijkstra_Table> &f)
{
	for (auto &i : f) {
		if (i.get_point().get_vnum() == m.get_vnum()) {
			return i.get_len();
		}
	}

	return 0;
}

void Graph::drawing(Grid &g, sf::RenderWindow &u)
{
	for (int i = 0; i < 500; i++) {
		u.draw(g.get_square(i));
	}
}

bool Graph::check_node(int n)
{
	for (auto i : nodes) {
		if (i.get_vnum() == n) {
			return true;
		}
	}
	return false;
}

bool Graph::check_list(std::vector<Node> &node, int f)
{
	for (auto i : node) {
		if (i.get_vnum() == f)
			return true;
	}

	return false;
}

Node & Graph::get_node(int i)
{
	for (auto &j : nodes) {
		if (j.get_vnum() == i)
			return j;
	}
}

void Graph::find_shortest_path(int beg, int end, std::vector<Dijkstra_Table> &map, std::vector<int> &path)
{
	Node current;
	Dijkstra_Table temp;

	for(auto &i : map) {
		if (i.get_point().get_vnum() == end) {
			temp = i;
			path.push_back(i.get_point().get_vnum());
			break;
		}
	}
	std::cout << "Beg: " << beg << std::endl;
	std::cout << "End: " << temp.get_point().get_vnum() << std::endl; 

	current = temp.get_prev();
	int temp2;

	while (current.get_vnum() != beg) {
		temp2 = current.get_vnum();
		for (auto &m : map) {
			if (m.get_point().get_vnum() == current.get_vnum()) {
				current = m.get_prev();		
				path.push_back(current.get_vnum());
				break;				
			}
		}
	}

	std::vector<int>::reverse_iterator iter;

	for (iter = path.rbegin(); iter != path.rend(); iter++)
		std::cout << (*iter) << std::endl; 

}

void Graph::remove_edges()
{
	edges.erase(edges.begin(), edges.end());

}

void Graph::remove_as()
{
	for (auto &i : nodes)
		i.erase_adjacency();
}

void Graph::reset_graph()
{
	remove_as();
	remove_edges();
}


