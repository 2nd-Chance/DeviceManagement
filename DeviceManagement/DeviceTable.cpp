#include "DeviceTable.h"

namespace mgmt
{
	DeviceTable::DeviceTable(void)
	{
		this->setTable(std::make_shared<TableType>());
	}

	std::shared_ptr<DeviceTable> DeviceTable::parse(nlohmann::json json)
	{
		//@ToDo: parse json
		return std::make_shared<DeviceTable>();
	}

	bool DeviceTable::add(std::shared_ptr<mgmt::Device> device)
	{
		std::uint32_t key = device->getDeviceId();
		auto ret = this->getTable()->insert(
			std::pair<std::uint32_t, std::shared_ptr<mgmt::Device>>(key, device));
		return ret.second;
	}

	bool DeviceTable::remove(std::uint32_t key)
	{
		return this->getTable()->erase(key) != 0;
	}

	std::shared_ptr<mgmt::Device> DeviceTable::get(std::uint32_t key)
	{
		auto found = this->getTable()->find(key);
		if (found != this->getTable()->end())
		{
			return found->second;
		}
		else
		{
			return nullptr;
		}
	}

	std::shared_ptr<DeviceTable::TableType> DeviceTable::getTable(void)
	{
		return this->table;
	}

	void DeviceTable::setTable(std::shared_ptr<DeviceTable::TableType> table)
	{
		this->table = table;
	}

	nlohmann::json DeviceTable::toJson(void)
	{
		//@ToDo: define json
		return nlohmann::json();
	}
}