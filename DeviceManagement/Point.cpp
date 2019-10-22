#include "Point.h"

namespace mgmt
{
	std::shared_ptr<Point> Point::parse(nlohmann::json)
	{
		//@ToDo: parse Json
		return std::shared_ptr<Point>();
	}

	int Point::getX(void) {
		return this->x;
	}

	void Point::setX(int x) {
		this->x = x;
	}

	int Point::getY(void) {
		return this->y;
	}

	void Point::setY(int y) {
		this->y = y;
	}

	nlohmann::json Point::toJson(void)
	{
		//ToDo: define Json
		return nlohmann::json();
	}
}