#include "Location.h"

namespace mgmt
{
	std::shared_ptr<Location> Location::parse(nlohmann::json json)
	{
		//@ToDo: parse Json
		return std::shared_ptr<Location>();
	}

	std::uint32_t Location::getLevel(void)
	{
		return this->level;
	}

	void Location::setLevel(std::uint32_t level)
	{
		this->level = level;
	}

	std::shared_ptr<mgmt::Point>  Location::getPoint(void)
	{
		return this->point;
	}

	void Location::setPoint(std::shared_ptr<mgmt::Point> point)
	{
		this->point = point;
	}
	
	nlohmann::json Location::toJson(void)
	{
		//@ToDo: define Json
		return nlohmann::json();
	}
}