#include<iostream>
#include<vector>
#define WIDTH 20
#define HEIGHT 20

class Point {
private:
	int _x;
	int _y;
public:
	Point() { 
	_x = 0;
	_y = 0;
	};

	Point(int x, int y) : _x(x), _y(y) {}

	int getX() const {
		return _x;
	}
	int getY() const {
		return _y;
	}
	void setX(int x)  {
		_x = x;
	}
	void setY(int y)  {
		_y = y;
	}
};

enum Direction {
	DIR_UP,
	DIR_RIGHT,
	DIR_LEFT,
	DIR_DOWN
};


class Snake {
private:
	std::vector<Point> snakeBody;
	bool find(int dx, int dy) {
		for (int i = 0; i < snakeBody.size(); ++i) {
			if ((dx == snakeBody[i].getX()) && (dy == snakeBody[i].getY())) {
				return true;
			}


		} return false;


	}
public:
	Snake(int x, int y) {
		snakeBody.push_back(Point(x, y));
	}
    const std::vector<Point>& getSnakeBody() const  {
		return snakeBody;
	}
	//0/0 1 2
	// 1  .
	// 2  .
	void move(int direction) {
		int dx = snakeBody.front().getX();
		int dy = snakeBody.front().getY();
		if (direction == DIR_UP) {
			--dy;
		}
		else if (direction == DIR_RIGHT) {
			++dx;
		}
		else if (direction == DIR_LEFT) {
			--dx;
		}
		else if (direction == DIR_DOWN) {
			++dy;
		}
		snakeBody.insert(snakeBody.begin(), Point(dx, dy));
		snakeBody.pop_back();
	}

	void grow() {
		int dx = snakeBody.back().getX();
		int dy = snakeBody.back().getY();
		if (find(dx + 1, dy)) {
			--dx;
		}
		else if (find(dx - 1, dy)) {
			++dx;
		}
		else if (find(dx, dy + 1)) {
			--dx;
		}
		else if (find(dx, dy - 1)) {
			++dx;
		}
		snakeBody.push_back(Point(dx, dy));
	}
};


class Field {
	private:
		char field[HEIGHT][WIDTH];
public:
	Field() {
		for (int i = 0; i < HEIGHT; ++i) {	
			for (int j = 0; j < WIDTH; ++j) {
				field[i][j] = '.';
			}
		}
	}
	// .o
	// xx
	// 1 2 3 4

	bool isInside(const Point& point) const {
		return ((0 <= point.getY() < HEIGHT) && (0 <= point.getX() < WIDTH));
	}

	bool checkInField(const Snake& snake) {
		for (auto obj : snake.getSnakeBody()) {
			if (!isInside(obj)) {
				return false;
			}
		}
		return true;
	}

	void updateField(const Snake& snake, const Point& fruit) {
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				field[i][j] = '.';
			}
		}
		for (auto obj : snake.getSnakeBody()) {
			field[obj.getY()][obj.getX()] = 'x';
		}
		field[fruit.getY()][fruit.getX()] = 'o';
	}     

	void draw() {
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j)
				std::cout << field[i][j];
			std::cout << "\n";
		}
	}
};



int main() {

}
