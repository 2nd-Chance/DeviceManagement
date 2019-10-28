#include <stdexcept>

#include "Device.h"

namespace csk
{
	Device::Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass) : Device(uuid, deviceClass, "") {}

	Device::Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac) : Device(uuid, deviceClass, bluetoothMac, 0) {}

	Device::Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac, RoomIdType roomId)
	{
		this->setUuid(uuid);
		this->setDeviceClass(deviceClass);
		this->setBluetoothMac(bluetoothMac);
		this->setRoomId(roomId);
	}

	Device::UuidType Device::getUuid(void)
	{
		return this->uuid;
	}
	
	void Device::setUuid(UuidType uuid)
	{
		this->uuid = uuid;
	}

	std::shared_ptr<DeviceClass> Device::getDeviceClass(void)
	{
		return this->deviceClass;
	}

	void Device::setDeviceClass(std::shared_ptr<DeviceClass> deviceClass)
	{
		if (deviceClass == nullptr)
		{
			throw std::invalid_argument("Device class cannot be a nullptr.");
		}

		this->deviceClass = deviceClass;
	}

	Device::BtMacType Device::getBluetoothMac(void)
	{
		return this->bluetoothMac;
	}
	
	void Device::setBluetoothMac(BtMacType bluetoothMac)
	{
		this->bluetoothMac = bluetoothMac;
	}
	
	Device::RoomIdType Device::getRoomId(void)
	{
		return this->roomId;
	}
	
	void Device::setRoomId(RoomIdType roomId)
	{
		this->roomId = roomId;
	}
	
	Device::JsonType Device::toJson(void)
	{
		JsonType json = JsonType::object();
		json["id"] = this->getUuid();
		json["cl"] = this->getDeviceClass()->toJson();
		json["bm"] = this->getBluetoothMac();
		json["rm"] = this->getRoomId();
		return json;
	}
}