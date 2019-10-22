#ifndef DeviceTable_h__
#define DeviceTable_h__


#include <string>
#include <cinttypes>
#include <memory>
#include <map>

#include "Device.h"
#include "json.hpp"

namespace mgmt
{

	class DeviceTable
	{
	public:
		using TableType = std::map<std::uint32_t, std::shared_ptr<mgmt::Device>>;

		DeviceTable(void);

		static std::shared_ptr<DeviceTable> parse(nlohmann::json json);

		bool add(std::shared_ptr<mgmt::Device> tuple);
		bool remove(std::uint32_t key);
		std::shared_ptr<mgmt::Device> get(std::uint32_t key);
		std::shared_ptr<TableType> getTable(void);
		nlohmann::json toJson(void);

	protected:
		void setTable(std::shared_ptr<TableType> deviceTable);

	private:
		std::shared_ptr<TableType> table;
	};
}


#endif // DeviceTable_h__