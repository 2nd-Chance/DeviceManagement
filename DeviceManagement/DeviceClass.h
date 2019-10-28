#ifndef DeviceClass_h__
#define DeviceClass_h__


#include <string>

#include "json.hpp"

namespace csk
{
	class DeviceClass
	{
		friend class DeviceClassBuilder;

	public:
		using JsonType = nlohmann::json;

		bool getAlertState(void);
		void setAlertState(bool state);
		bool getAliveState(void);
		void setAliveState(bool state);
		virtual JsonType toJson(void);

	protected:
		DeviceClass(void) {}

	private:
		bool alertState = false;
		bool aliveState = true;
	};

	class DeviceClass3 : public DeviceClass
	{
	public:
		JsonType toJson(void) override;
	};

	class DeviceClass2 : public DeviceClass3
	{
	public:
		DeviceClass2(void) : DeviceClass3() {}
		DeviceClass2(std::string sensorType, std::string sensorValue);

		std::string getSensorType(void);
		void setSensorType(std::string sensorType);
		std::string getSensorValue(void);
		void setSensorValue(std::string sensorValue);
		JsonType toJson(void) override;

	private:
		std::string sensorType;
		std::string sensorValue;
	};

	class DeviceClass1 : public DeviceClass2
	{
	public:
		DeviceClass1(void) : DeviceClass2() {}
		DeviceClass1(std::string sensorType, std::string sensorValue) : DeviceClass2(sensorType, sensorValue) {}

		JsonType toJson(void) override;
	};
}


#endif // DeviceClass_h__