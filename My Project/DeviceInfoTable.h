#ifndef DeviceInfoTable_h__
#define DeviceInfoTable_h__


#include <string>
#include <cinttypes>
#include <memory>
#include <map>

#include "DeviceInfoEntity.h"

using DeviceInfoMap = std::map<std::uint32_t, std::shared_ptr<DeviceInfoEntity>>;

class DeviceInfoTable
{
public:
	DeviceInfoMap& getTable(void) {
		return this->table;
	}

	bool addTuple(std::shared_ptr<DeviceInfoEntity> tuple);
	bool removeTuple(std::uint32_t key);
	std::shared_ptr<DeviceInfoEntity> getTuple(std::uint32_t key);

private:
	DeviceInfoMap table;
};


#endif // DeviceInfoTable_h__