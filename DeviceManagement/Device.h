#ifndef Device_h__
#define Device_h__


#include <memory>
#include <string>

#include "DeviceClass.h"

namespace csk
{
	class Device
	{
		friend class DeviceBuilder;

	public:
		using UuidType = std::string;
		using BtMacType = std::string;
		using RoomIdType = std::uint32_t;
		using JsonType = nlohmann::json;

		UuidType getUuid(void);
		void setUuid(UuidType uuid);
		std::shared_ptr<DeviceClass> getDeviceClass(void);
		void setDeviceClass(std::shared_ptr<DeviceClass> deviceClass);
		BtMacType getBluetoothMac(void);
		void setBluetoothMac(BtMacType bluetoothMac);
		RoomIdType getRoomId(void);
		void setRoomId(RoomIdType roomId);
		JsonType toJson(void);

	protected:
		Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass);
		Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac);
		Device(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac, RoomIdType roomId);

	private:
		UuidType uuid;
		std::shared_ptr<DeviceClass> deviceClass;
		BtMacType bluetoothMac;
		RoomIdType roomId;
	};

	class DynamicDevice : public Device
	{
	public:
		DynamicDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass) : Device(uuid, deviceClass) {}
		DynamicDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac) : Device(uuid, deviceClass, bluetoothMac) {}
		DynamicDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac, RoomIdType roomId) : Device(uuid, deviceClass, bluetoothMac, roomId) {}
	};
	
	class StaticDevice : public Device
	{
	public:
		StaticDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass) : Device(uuid, deviceClass) {}
		StaticDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac) : Device(uuid, deviceClass, bluetoothMac) {}
		StaticDevice(UuidType uuid, std::shared_ptr<DeviceClass> deviceClass, BtMacType bluetoothMac, RoomIdType roomId) : Device(uuid, deviceClass, bluetoothMac, roomId) {}
	};
}


#endif // Device_h__