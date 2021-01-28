#include "grid.h"


void Grid::fill_grid()
{
	int counter = 0;
	float x_pos = 0, y_pos = 0;

	for (int i = 0; i < 500; i++) {

		if (counter % 20 == 0 && counter != 0) {
			y_pos += 50;
			x_pos = 0;
		}

		sf::RectangleShape temp(sf::Vector2f(50, 50));
		grrid[i] = temp;
		grrid[i].setOutlineThickness(5);
		grrid[i].setOutlineColor(sf::Color::Blue);
		grrid[i].setPosition(x_pos, y_pos);
		
		x_pos += 50;
		counter++;
		
	}
}

int Grid::get_square_x(int a)
{
	int temp = grrid[a].getPosition().x;
	return temp;
}

int Grid::get_square_y(int b)
{
	int temp = grrid[b].getPosition().y;
	return temp;
}

void Grid::board_edit(sf::RenderWindow &w)
{
	drawing_obstacles(w);
	mark_target(w);
	set_source(w);
	reset(); 
}


void Grid::drawing_obstacles(sf::RenderWindow &w)
{
	int change = locate_square(w);

	grrid[change].setFillColor(sf::Color::Black);

}

void Grid::mark_target(sf::RenderWindow &window)
{
		int spot = set_target(window);
		grrid[spot].setFillColor(sf::Color::Red);
}

void Grid::set_source(sf::RenderWindow &window)
{
	int spot = set_beg(window);
	grrid[spot].setFillColor(sf::Color::Green);
}

int Grid::locate_square(sf::RenderWindow &w2)
{
	for (int i = 0; i < 500; i++) {

		int mouse_x = sf::Mouse::getPosition(w2).x;
		int mouse_y = sf::Mouse::getPosition(w2).y;

		int x_coord = get_square_x(i);
		int y_coord = get_square_y(i);

		if ((mouse_x >= x_coord && mouse_x <= x_coord + 50) && (mouse_y >= y_coord && mouse_y <= y_coord + 50) && (sf::Mouse::isButtonPressed(sf::Mouse::Right))) {
			return i;
		}
		
	}
}

int Grid::set_target(sf::RenderWindow &window)
{

	for (int i = 0; i < 500; i++) {

		int mouse_x = sf::Mouse::getPosition(window).x;
		int mouse_y = sf::Mouse::getPosition(window).y;

		int x_coord = get_square_x(i);
		int y_coord = get_square_y(i);

		if ((mouse_x >= x_coord && mouse_x <= x_coord + 50) && (mouse_y >= y_coord && mouse_y <= y_coord + 50) && (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))) {
			if (target == -1) {
				target = i;
			}
			else {
				grrid[target].setFillColor(sf::Color::White);
				target = i; 
			}
			return i;
		}
	}

}

int Grid::set_beg(sf::RenderWindow &window)
{

	for (int i = 0; i < 500; i++) {

		int mouse_x = sf::Mouse::getPosition(window).x;
		int mouse_y = sf::Mouse::getPosition(window).y;

		int x_coord = get_square_x(i);
		int y_coord = get_square_y(i);

		if ((mouse_x >= x_coord && mouse_x <= x_coord + 50) && (mouse_y >= y_coord && mouse_y <= y_coord + 50) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))) {
			if (start == -1) {
				start = i;
			}
			else {
				grrid[start].setFillColor(sf::Color::White);
				start = i;
			}
			return i;
		}
	}

}

void Grid::reset()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {

		for (auto &i : grrid) {
			i.setFillColor(sf::Color::White);
		}

		target = -1;
		start = -1;
	}
}

void Grid::make_graph(Graph &g)
{
	for (int i = 0; i < 500; i++) {
		g.add_node(grrid[i], i);
	}
}