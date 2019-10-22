#ifndef DeviceInfoEntity_h__
#define DeviceInfoEntity_h__


#include <string>
#include <cinttypes>
#include <vector>

#include "json.hpp"

class DeviceInfoEntity
{
public:
	DeviceInfoEntity() {}

	std::uint32_t getDeviceId(void);
	virtual nlohmann::json getJson(void) = 0;
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

protected:
	void setDeviceClass(std::uint32_t deviceClass);

protected:
	std::uint32_t deviceId = 0;
	std::string deviceUuid = "";
	std::string bluetoothMac = "";

	bool alertState = false;
	bool aliveState = true;
	std::uint32_t deviceClass = 0;
};


#endif // DeviceInfoEntity_h__