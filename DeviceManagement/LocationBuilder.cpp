#include "LocationBuilder.h"


namespace csk
{
	int LocationBuilder::getLevel(void)
	{
		return this->level;
	}

	LocationBuilder &LocationBuilder::setLevel(int level)
	{
		this->level = level;
		return *this;
	}

	int LocationBuilder::getX(void)
	{
		return this->x;
	}

	LocationBuilder &LocationBuilder::setX(int x)
	{
		this->x = x;
		return *this;
	}
	
	int LocationBuilder::getY(void)
	{
		return this->y;
	}
	
	LocationBuilder &LocationBuilder::setY(int y)
	{
		this->y = y;
		return *this;
	}
	
	std::shared_ptr<csk::Location> LocationBuilder::build(void)
	{
		auto location = std::make_shared<csk::Location>();
		location->setLevel(this->getLevel());
		location->setX(this->getX());
		location->setY(this->getY());
		return location;
	}
}