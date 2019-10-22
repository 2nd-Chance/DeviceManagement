#include "DeviceInfoEntityClass.h"

DeviceInfoEntityClass3::DeviceInfoEntityClass3(void)
{
	this->setDeviceClass(3);
}

nlohmann::json DeviceInfoEntityClass3::getJson(void)
{
	nlohmann::json j = {
		{"id", this->getDeviceId()},
		{"uid", this->getDeviceUuid()},
		{"mac", this->getBluetoothMac()},
		{"ar", this->getAlertState()},
		{"al", this->getAliveState()},
		{"cl", this->getDeviceClass()}
	};
	return j;
}

DeviceInfoEntityClass2::DeviceInfoEntityClass2(void)
{
	this->setDeviceClass(2);
}

nlohmann::json DeviceInfoEntityClass2::getJson(void)
{
	nlohmann::json jsonObject = DeviceInfoEntityClass3::getJson();
	jsonObject["st"] = this->getSensorType();
	jsonObject["sv"] = this->getSensorValue();
	return jsonObject;
}

std::string DeviceInfoEntityClass2::getSensorType()
{
	return this->sensorType;
}

void DeviceInfoEntityClass2::setSensorType(std::string sensorType)
{
	this->sensorType = sensorType;
}

std::string DeviceInfoEntityClass2::getSensorValue()
{
	return this->sensorValue;
}

void DeviceInfoEntityClass2::setSensorValue(std::string sensorValue)
{
	this->sensorValue = sensorValue;
}



DeviceInfoEntityClass1::DeviceInfoEntityClass1(void)
{
	this->setDeviceClass(1);
}

nlohmann::json DeviceInfoEntityClass1::getJson(void)
{
	nlohmann::json jsonObject = DeviceInfoEntityClass3::getJson();
	jsonObject["cn"] = this->getConnections();
	return jsonObject;
}

std::vector<std::uint32_t> &DeviceInfoEntityClass1::getConnections()
{
	return this->connections;
}