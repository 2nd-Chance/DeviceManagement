#include "DeviceInfoEntity.h"

std::uint32_t DeviceInfoEntity::getDeviceId(void)
{
	return this->deviceId;
}

void DeviceInfoEntity::setDeviceId(std::uint32_t deviceId)
{
	this->deviceId = deviceId;
}

std::string DeviceInfoEntity::getDeviceUuid(void)
{
	return this->deviceUuid;
}

void DeviceInfoEntity::setDeviceUuid(std::string deviceUuid)
{
	this->deviceUuid = deviceUuid;
}

std::string DeviceInfoEntity::getBluetoothMac(void)
{
	return this->bluetoothMac;
}

void DeviceInfoEntity::setBluetoothMac(std::string bluetoothMac)
{
	this->bluetoothMac = bluetoothMac;
}

bool DeviceInfoEntity::getAlertState(void)
{
	return this->alertState;
}

void DeviceInfoEntity::setAlertState(bool alertState)
{
	this->alertState = alertState;
}

bool DeviceInfoEntity::getAliveState(void)
{
	return this->aliveState;
}

void DeviceInfoEntity::setAliveState(bool aliveState)
{
	this->aliveState = aliveState;
}

std::uint32_t DeviceInfoEntity::getDeviceClass()
{
	return this->deviceClass;
}

void DeviceInfoEntity::setDeviceClass(std::uint32_t deviceClass)
{
	this->deviceClass = deviceClass;
}