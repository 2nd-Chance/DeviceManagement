#include "Device.h"

namespace mgmt
{
	std::shared_ptr<Device> Device::parse(nlohmann::json json)
	{
		//@ToDo: parse Json
		return std::shared_ptr<Device>();
	}

	std::uint32_t Device::getDeviceId(void)
	{
		return this->deviceId;
	}

	void Device::setDeviceId(std::uint32_t deviceId)
	{
		this->deviceId = deviceId;
	}

	std::string Device::getDeviceUuid(void)
	{
		return this->deviceUuid;
	}

	void Device::setDeviceUuid(std::string deviceUuid)
	{
		this->deviceUuid = deviceUuid;
	}

	std::string Device::getBluetoothMac(void)
	{
		return this->bluetoothMac;
	}

	void Device::setBluetoothMac(std::string bluetoothMac)
	{
		this->bluetoothMac = bluetoothMac;
	}

	bool Device::getAlertState(void)
	{
		return this->alertState;
	}

	void Device::setAlertState(bool alertState)
	{
		this->alertState = alertState;
	}

	bool Device::getAliveState(void)
	{
		return this->aliveState;
	}

	void Device::setAliveState(bool aliveState)
	{
		this->aliveState = aliveState;
	}

	std::uint32_t Device::getDeviceClass()
	{
		return this->deviceClass;
	}

	void Device::setDeviceClass(std::uint32_t deviceClass)
	{
		this->deviceClass = deviceClass;
	}
}