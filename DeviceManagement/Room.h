#ifndef Room_h__
#define Room_h__


#include <iostream>
#include <cinttypes>
#include <memory>

#include "DeviceTable.h"
#include "Location.h"

namespace mgmt
{
	class Room
	{
	public:
		Room();

		static std::shared_ptr<Room> parse(nlohmann::json json);

		std::uint32_t getId(void);
		void setId(std::int32_t id);
		std::shared_ptr<mgmt::Location> getLocation(void);
		void setLocation(std::shared_ptr<mgmt::Location> location);
		bool getAlertState(void);
		void setAlertState(bool state);
		bool getAliveState(void);
		void setAliveState(bool state);
		std::shared_ptr<mgmt::DeviceTable> getDeviceTable(void);
		nlohmann::json getJson(void);

	protected:
		void setDeviceTable(std::shared_ptr<mgmt::DeviceTable> deviceTable);

	private:
		std::uint32_t id;
		std::shared_ptr<mgmt::Location> location;
		bool alertState = false;
		bool aliveState = true;
		std::shared_ptr<mgmt::DeviceTable> deviceTable;
	};
}


#endif // Room_h__
