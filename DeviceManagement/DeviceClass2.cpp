#include "DeviceClass.h"

namespace mgmt
{
	namespace dev
	{
		Class2::Class2(void)
		{
			this->setDeviceClass(2);
		}

		std::shared_ptr<Class2> Class2::parse(nlohmann::json json)
		{
			//@ToDo: parse Json
			return std::shared_ptr<Class2>();
		}

		nlohmann::json Class2::toJson(void)
		{
			nlohmann::json jsonObject = Class3::toJson();
			jsonObject["st"] = this->getSensorType();
			jsonObject["sv"] = this->getSensorValue();
			return jsonObject;
		}

		std::string Class2::getSensorType()
		{
			return this->sensorType;
		}

		void Class2::setSensorType(std::string sensorType)
		{
			this->sensorType = sensorType;
		}

		std::string Class2::getSensorValue()
		{
			return this->sensorValue;
		}

		void Class2::setSensorValue(std::string sensorValue)
		{
			this->sensorValue = sensorValue;
		}
	}
}