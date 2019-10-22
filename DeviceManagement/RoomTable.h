#ifndef RoomTable_h__
#define RoomTable_h__

#include <string>
#include <cinttypes>
#include <memory>
#include <map>

#include "Room.h"
#include "json.hpp"

namespace mgmt
{

	class RoomTable
	{
	public:
		using TableType = std::map<uint32_t, std::shared_ptr<mgmt::Room>>;

		RoomTable(void);

		static std::shared_ptr<RoomTable> parse(nlohmann::json json);

		bool add(std::shared_ptr<Room> room);
		bool remove(std::uint32_t key);
		std::shared_ptr<Room> get(uint32_t key);
		std::shared_ptr<TableType> getTable(void);
		nlohmann::json toJson(void);

	protected:
		void setTable(std::shared_ptr<TableType> table);

	private:
		std::shared_ptr<TableType> table;
	};
}


#endif // RoomTable_h__