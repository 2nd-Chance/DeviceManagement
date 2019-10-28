#include "Location.h"

namespace csk
{
	Location::Location(void) : Location(0, 0) {}
	
	Location::Location(int x, int y) : Location(1, x, y) {}
	
	Location::Location(int level, int x, int y)
	{
		this->setLevel(level);
		this->setX(x);
		this->setY(y);
	}
	
	Location Location::parse(JsonType &json)
	{
		//ToDo: parse JSON
		return Location();
	}
	
	int Location::getLevel(void)
	{
		return this->level;
	}

	void Location::setLevel(int level)
	{
		if (level == 0) {
			throw level;
		}
		this->level = level;
	}
	
	int Location::getX(void)
	{
		return this->x;
	}

	void Location::setX(int x)
	{
		this->x = x;
	}

	int Location::getY(void)
	{
		return this->y;
	}

	void Location::setY(int y)
	{
		this->y = y;
	}

	Location::JsonType Location::toJson(void)
	{
		nlohmann::json json;
		json["l"] = this->getLevel();
		json["x"] = this->getX();
		json["y"] = this->getY();
		return json;
	}
}
