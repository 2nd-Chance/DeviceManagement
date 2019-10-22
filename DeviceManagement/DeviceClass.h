#ifndef DeviceClass_h__
#define DeviceClass_h__


#include "json.hpp"
#include "Device.h"

namespace mgmt
{
	namespace dev
	{
		class Class3 : public mgmt::Device {
		public:
			Class3(void);

			static std::shared_ptr<Class3> parse(nlohmann::json json);

			virtual nlohmann::json toJson(void) override;
		};

		class Class2 : public Class3 {
		public:
			Class2(void);

			static std::shared_ptr<Class2> parse(nlohmann::json json);

			std::string getSensorType(void);
			void setSensorType(std::string sensorType);
			std::string getSensorValue(void);
			void setSensorValue(std::string sensorValue);
			virtual nlohmann::json toJson(void) override;

		protected:
			std::string sensorType = "";
			std::string sensorValue = "";
		};

		class Class1 : public Class2 {
		public:
			Class1(void);

			static std::shared_ptr<Class1> parse(nlohmann::json json);

			virtual nlohmann::json toJson(void) override;
		};
	}
}


#endif // DeviceClass_h__