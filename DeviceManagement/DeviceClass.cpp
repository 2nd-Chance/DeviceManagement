#include "DeviceClass.h"

namespace csk
{
	bool DeviceClass::getAlertState(void)
	{
		return this->alertState;
	}
	
	void DeviceClass::setAlertState(bool state)
	{
		this->alertState = state;
	}
	
	bool DeviceClass::getAliveState(void)
	{
		return this->aliveState;
	}

	void DeviceClass::setAliveState(bool state)
	{
		this->aliveState = state;
	}

	DeviceClass::JsonType DeviceClass::toJson(void)
	{
		JsonType json = JsonType::object();
		json["ar"] = static_cast<int>(this->getAlertState());
		json["al"] = static_cast<int>(this->getAliveState());
		return json;
	}
	
	DeviceClass2::DeviceClass2(std::string sensorType, std::string sensorValue)
	{
		this->setSensorType(sensorType);
		this->setSensorValue(sensorValue);
	}

	std::string DeviceClass2::getSensorType(void)
	{
		return this->sensorType;
	}
	
	void DeviceClass2::setSensorType(std::string sensorType)
	{
		this->sensorType = sensorType;
	}
	
	std::string DeviceClass2::getSensorValue(void)
	{
		return this->sensorValue;
	}

	void DeviceClass2::setSensorValue(std::string sensorValue)
	{
		this->sensorValue = sensorValue;
	}

	DeviceClass::JsonType DeviceClass2::toJson(void)
	{
		JsonType json = DeviceClass3::toJson();
		json["st"] = this->getSensorType();
		json["sv"] = this->getSensorValue();
		return json;
	}
	
	DeviceClass::JsonType DeviceClass3::toJson(void)
	{
		return DeviceClass::toJson();
	}
	
	DeviceClass::JsonType DeviceClass1::toJson(void)
	{
		return DeviceClass2::toJson();
	}
}