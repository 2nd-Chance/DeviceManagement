#include "Room.h"

namespace mgmt
{
	Room::Room()
	{
		this->setDeviceTable(std::make_shared<mgmt::DeviceTable>());
	}

	std::shared_ptr<Room> Room::parse(nlohmann::json json)
	{
		//@ToDo: parse Json
		return std::shared_ptr<Room>();
	}

	std::uint32_t Room::getId(void)
	{
		return this->id;
	}

	void Room::setId(std::int32_t id)
	{
		this->id = id;
	}

	std::shared_ptr<mgmt::Location> Room::getLocation(void)
	{
		return this->location;
	}

	void Room::setLocation(std::shared_ptr<mgmt::Location> location)
	{
		this->location = location;
	}

	bool Room::getAlertState(void)
	{
		return this->alertState;
	}

	void Room::setAlertState(bool state)
	{
		this->alertState = state;
	}

	bool Room::getAliveState(void)
	{
		return this->alertState;
	}

	void Room::setAliveState(bool state)
	{
		this->aliveState = state;
	}

	std::shared_ptr<mgmt::DeviceTable> Room::getDeviceTable(void)
	{
		return this->deviceTable;
	}

	nlohmann::json Room::getJson(void)
	{
		//@ToDo: define Json
		return nlohmann::json();
	}

	void Room::setDeviceTable(std::shared_ptr<mgmt::DeviceTable> deviceTable)
	{
		this->deviceTable = deviceTable;
	}
}