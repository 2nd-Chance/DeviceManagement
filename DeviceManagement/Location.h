#ifndef Location_h__
#define Location_h__


#include <cinttypes>
#include <memory>

#include "Point.h"
#include "json.hpp"

namespace mgmt
{
	class Location
	{
	public:
		static std::shared_ptr<Location> parse(nlohmann::json json);
		
		std::uint32_t getLevel(void);
		void setLevel(std::uint32_t level);
		std::shared_ptr<mgmt::Point> getPoint(void);
		void setPoint(std::shared_ptr<mgmt::Point> point);
		nlohmann::json toJson(void);

	private:
		std::uint32_t level;
		std::shared_ptr<mgmt::Point> point;
	};
}


#endif // Location_h__