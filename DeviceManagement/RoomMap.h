#ifndef RoomMap_h__
#define RoomMap_h__


#include <cinttypes>

#include "MyMap.h"
#include "Room.h"

namespace csk
{
	class RoomMap : public MyMap<std::uint32_t, std::shared_ptr<csk::Room>>
	{
	public:

	};
}


#endif // RoomMap_h__