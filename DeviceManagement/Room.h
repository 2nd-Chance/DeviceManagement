#ifndef Room_h__
#define Room_h__


#include <cinttypes>
#include <memory>
#include <set>
#include <map>

#include "Location.h"
#include "json.hpp"
#include "Device.h"
#include "DeviceMap.h"
#include "MySet.h"

namespace csk
{
	class Room
	{
		friend class RoomBuilder;

	public:
		using IdType = std::uint32_t;
		using LinkListType = csk::MySet<IdType>;
		using StaticDeviceListType = csk::DeviceMap<StaticDevice>;
		using DynamicDeviceListType = csk::DeviceMap<DynamicDevice>;
		using JsonType = nlohmann::json;
		
		Room(IdType id);
		Room(IdType id, std::shared_ptr<Location> location);
		Room(IdType id, std::shared_ptr<Location> location, bool alertState, bool aliveState);

		static std::shared_ptr<Room> parse(JsonType &json);

		IdType getId(void);
		std::shared_ptr<Location> getLocation(void);
		bool getAlertState(void);
		void setAlertState(bool state);
		bool getAliveState(void);
		void setAliveState(bool state);
		std::shared_ptr<LinkListType> getLinks(void);
		std::shared_ptr<StaticDeviceListType> getStaticDevices(void);
		std::shared_ptr<DynamicDeviceListType> getDynamicDevices(void);
		JsonType toJson(void);

	protected:
		void setId(IdType id);
		void setLocation(std::shared_ptr<Location> location);
		void setLinks(std::shared_ptr<LinkListType> links);
		void setStaticDevices(std::shared_ptr<StaticDeviceListType> devices);
		void setDynamicDevices(std::shared_ptr<DynamicDeviceListType> devices);

	private:
		IdType id;
		std::shared_ptr<Location> location;
		bool alertState;
		bool aliveState;
		std::shared_ptr<LinkListType> links;
		std::shared_ptr<StaticDeviceListType> staticDevices;
		std::shared_ptr<DynamicDeviceListType> dynamicDevices;
	};
}


#endif // Room_h__