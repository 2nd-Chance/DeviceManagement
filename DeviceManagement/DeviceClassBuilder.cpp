#include "DeviceClassBuilder.h"

namespace csk
{
	/*
		Base class
	*/

	bool DeviceClassBuilder::getAlertState(void)
	{
		return this->alertState;
	}

	DeviceClassBuilder &DeviceClassBuilder::setAlertState(bool state)
	{
		this->alertState = state;
		return *this;
	}
	
	bool DeviceClassBuilder::getAliveState(void)
	{
		return this->aliveState;
	}
	
	DeviceClassBuilder &DeviceClassBuilder::setAliveState(bool state)
	{
		this->aliveState = state;
		return *this;
	}

	/*
		Class 3
	*/

	std::shared_ptr<DeviceClass> DeviceClass3Builder::build(void)
	{
		auto class3 = std::make_shared<DeviceClass3>();
		class3->setAlertState(this->getAlertState());
		class3->setAliveState(this->getAliveState());
		return class3;
	}

	/*
		Class 2
	*/

	std::string DeviceClass2Builder::getSensorType(void)
	{
		return this->sensorType;
	}
	
	DeviceClass2Builder &DeviceClass2Builder::setSensorType(std::string sensorType)
	{
		this->sensorType = sensorType;
		return *this;
	}

	std::string DeviceClass2Builder::getSensorValue(void)
	{
		return this->sensorValue;
	}
	
	DeviceClass2Builder &DeviceClass2Builder::setSensorValue(std::string sensorValue)
	{
		this->sensorValue = sensorValue;
		return *this;
	}

	std::shared_ptr<DeviceClass> DeviceClass2Builder::build(void)
	{
		auto class2 = std::make_shared<DeviceClass2>();
		class2->setAlertState(this->getAlertState());
		class2->setAliveState(this->getAliveState());
		class2->setSensorType(this->getSensorType());
		class2->setSensorValue(this->getSensorValue());
		return class2;
	}

	/*
		Class 1
	*/
	
}