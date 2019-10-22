#include "DeviceClass.h"

namespace mgmt
{
	namespace dev
	{
		Class3::Class3(void)
		{
			this->setDeviceClass(3);
		}

		std::shared_ptr<Class3> Class3::parse(nlohmann::json json)
		{
			//@ToDo: parse Json
			return std::shared_ptr<Class3>();
		}

		nlohmann::json Class3::toJson(void)
		{
			nlohmann::json j = {
				{"id", this->getDeviceId()},
				{"uid", this->getDeviceUuid()},
				{"mac", this->getBluetoothMac()},
				{"ar", this->getAlertState()},
				{"al", this->getAliveState()},
				{"cl", this->getDeviceClass()}
			};
			return j;
		}
	}
}