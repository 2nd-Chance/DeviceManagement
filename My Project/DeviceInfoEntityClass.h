#ifndef DeviceInfoEntityClass_h__
#define DeviceInfoEntityClass_h__


#include "DeviceInfoEntity.h"
#include "json.hpp"

class DeviceInfoEntityClass3 : public DeviceInfoEntity {
public:
	DeviceInfoEntityClass3(void);
	nlohmann::json getJson(void) override;
};

class DeviceInfoEntityClass2 : public DeviceInfoEntityClass3 {
public:
	DeviceInfoEntityClass2(void);
	nlohmann::json getJson(void) override;
	std::string getSensorType(void);
	void setSensorType(std::string sensorType);
	std::string getSensorValue(void);
	void setSensorValue(std::string sensorValue);

protected:
	std::string sensorType = "";
	std::string sensorValue = "";
};

class DeviceInfoEntityClass1 : public DeviceInfoEntityClass2 {
public:
	DeviceInfoEntityClass1(void);
	nlohmann::json getJson(void) override;
	std::vector<std::uint32_t> &getConnections(void);

	void test(std::uint32_t val) {
		connections.push_back(val);
	}

protected:
	std::vector<std::uint32_t> connections;
};


#endif // DeviceInfoEntityClass_h__