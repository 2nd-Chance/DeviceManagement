#include <algorithm>

#include "Room.h"

namespace csk
{
	Room::Room(IdType id) : Room(id, std::make_shared<Location>()) {}

	Room::Room(IdType id, std::shared_ptr<Location> location) : Room(id, location, false, true) {}

	Room::Room(IdType id, std::shared_ptr<Location> location, bool alertState, bool aliveState)
	{
		this->setId(id);
		this->setLocation(location);
		this->setAlertState(alertState);
		this->setAliveState(aliveState);

		this->setLinks(std::make_shared<LinkListType>());
		this->setStaticDevices(std::make_shared<StaticDeviceListType>());
		this->setDynamicDevices(std::make_shared<DynamicDeviceListType>());
	}

	std::shared_ptr<Room> Room::parse(JsonType &json)
	{
		//ToDo: parse JSON
		return std::shared_ptr<Room>();
	}

	Room::IdType Room::getId(void)
	{
		return this->id;
	}
	
	void Room::setId(IdType id)
	{
		this->id = id;
	}

	std::shared_ptr<Location> Room::getLocation(void)
	{
		return this->location;
	}

	void Room::setLocation(std::shared_ptr<Location> location)
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
		return this->aliveState;
	}

	void Room::setAliveState(bool state)
	{
		this->aliveState = state;
	}

	std::shared_ptr<Room::LinkListType> Room::getLinks(void)
	{
		return this->links;
	}

	void Room::setLinks(std::shared_ptr<LinkListType> links)
	{
		this->links = links;
	}

	std::shared_ptr<Room::StaticDeviceListType> Room::getStaticDevices(void)
	{
		return this->staticDevices;
	}

	void Room::setStaticDevices(std::shared_ptr<StaticDeviceListType> devices)
	{
		this->staticDevices = devices;
	}

	std::shared_ptr<Room::DynamicDeviceListType> Room::getDynamicDevices(void)
	{
		return this->dynamicDevices;
	}

	void Room::setDynamicDevices(std::shared_ptr<DynamicDeviceListType> devices)
	{
		this->dynamicDevices = devices;
	}

	Room::JsonType Room::toJson(void)
	{
		JsonType json = JsonType::object();
		json["id"] = this->getId();
		json["lc"] = this->getLocation()->toJson();
		json["ar"] = static_cast<int>(this->getAlertState());
		json["al"] = static_cast<int>(this->getAliveState());
		json["lk"] = *(this->getLinks()->getSet()); //@ToDo: fix this
		json["sd"] = this->getStaticDevices()->toJson();
		json["dd"] = this->getDynamicDevices()->toJson();
		return json;
	}
}