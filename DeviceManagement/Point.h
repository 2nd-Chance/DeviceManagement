#ifndef Point_h__
#define Point_h__


#include <memory>

#include "json.hpp"

namespace mgmt
{
	class Point
	{
	public:
		static std::shared_ptr<Point> parse(nlohmann::json);

		int getX(void);
		void setX(int x);
		int getY(void);
		void setY(int y);
		nlohmann::json toJson(void);

	private:
		int x;
		int y;
	};
}


#endif // Point_h__