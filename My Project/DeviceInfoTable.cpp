#include "DeviceInfoTable.h"

bool DeviceInfoTable::addTuple(std::shared_ptr<DeviceInfoEntity> tuple)
{
	std::uint32_t key = tuple->getDeviceId();
	auto ret = this->getTable().insert(
		std::pair<std::uint32_t,std::shared_ptr<DeviceInfoEntity>>(key, tuple));
	return ret.second;
}

bool DeviceInfoTable::removeTuple(std::uint32_t key)
{
	return this->getTable().erase(key) != 0;
}

std::shared_ptr<DeviceInfoEntity> DeviceInfoTable::getTuple(std::uint32_t key)
{
	auto found = this->getTable().find(key);
	if (found != this->getTable().end())
	{
		return found->second;
	}
	else
	{
		return nullptr;
	}
}
