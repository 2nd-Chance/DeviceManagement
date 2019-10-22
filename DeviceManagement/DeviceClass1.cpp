#include "DeviceClass.h"

namespace mgmt
{
	namespace dev
	{
		Class1::Class1(void)
		{
			this->setDeviceClass(1);
		}

		std::shared_ptr<Class1> Class1::parse(nlohmann::json json)
		{
			//@ToDo: parse Json
			return std::shared_ptr<Class1>();
		}

		nlohmann::json Class1::toJson(void)
		{
			return Class3::toJson();
		}
	}
}