#ifndef Device_h__
#define Device_h__


#include <string>
#include <cinttypes>
#include <vector>

#include "json.hpp"

namespace mgmt
{
	class Device
	{
	public:
		virtual ~Device() {}

		static std::shared_ptr<Device> parse(nlohmann::json json);

		std::uint32_t getDeviceId(void);
		void setDeviceId(std::uint32_t deviceId);
		std::string getDeviceUuid(void);
		void setDeviceUuid(std::string deviceUuid);
		std::string getBluetoothMac(void);
		void setBluetoothMac(std::string bluetoothMac);
		bool getAlertState(void);
		void setAlertState(bool alertState);
		bool getAliveState(void);
		void setAliveState(bool aliveState);
		std::uint32_t getDeviceClass(void);
		virtual nlohmann::json toJson(void) = 0;

	protected:
		void setDeviceClass(std::uint32_t deviceClass);

	protected:
		std::uint32_t deviceId = 0;
		std::string deviceUuid = "";
		std::string bluetoothMac = "";
		std::uint32_t deviceClass = 0;
		bool alertState = false;
		bool aliveState = true;
	};
}


#endif // Device_h__