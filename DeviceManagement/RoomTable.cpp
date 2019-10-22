#include "RoomTable.h"

namespace mgmt
{
	RoomTable::RoomTable(void)
	{
		this->setTable(std::make_shared<TableType>());
	}

	std::shared_ptr<RoomTable> RoomTable::parse(nlohmann::json json)
	{
		//@ToDo: parse Json
		return std::shared_ptr<RoomTable>();
	}

	bool RoomTable::add(std::shared_ptr<Room> room)
	{
		std::uint32_t key = room->getId();
		auto ret = this->getTable()->insert(
			std::pair<std::uint32_t, std::shared_ptr<mgmt::Room>>(key, room));
		return ret.second;
	}

	bool RoomTable::remove(std::uint32_t key)
	{
		return this->getTable()->erase(key) != 0;
	}

	std::shared_ptr<Room> RoomTable::get(uint32_t key)
	{
		auto found = this->getTable()->find(key);
		if (found != this->getTable()->end())
		{
			return found->second;
		}
		else
		{
			return nullptr;
		}
	}

	std::shared_ptr<RoomTable::TableType> RoomTable::getTable(void)
	{
		return this->table;
	}

	void RoomTable::setTable(std::shared_ptr<RoomTable::TableType> table)
	{
		this->table = table;
	}

	nlohmann::json RoomTable::toJson(void)
	{
		//@ToDo: define Json
		return nlohmann::json();
	}
}
