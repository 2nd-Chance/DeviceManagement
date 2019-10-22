#include <iostream>

#include "json.hpp"
#include "DeviceClass.h"
#include "DeviceTable.h"

int main(void)
{
	std::cout << "=== start ===" << std::endl << std::endl;

	//std::shared_ptr<mgmt::dev::Class1> tuple(new mgmt::dev::Class1());
	auto tuple = std::make_shared<mgmt::dev::Class1>();
	tuple->setDeviceId(123);
	tuple->setDeviceUuid("dev uuid");
	tuple->setBluetoothMac("bt mac");
	tuple->setSensorType("sens type");
	tuple->setSensorValue("sens val");
	
	std::cout << tuple->getDeviceId() << std::endl
		<< tuple->getDeviceUuid() << std::endl
		<< tuple->getBluetoothMac() << std::endl;

	std::shared_ptr<mgmt::DeviceTable> table(new mgmt::DeviceTable());
	table->add(tuple);
	auto found = table->get(123);
	if (found)
	{
		std::cout << found->toJson().dump() << std::endl;
	}
	std::cout << table->remove(123) << std::endl;
	std::cout << table->remove(123) << std::endl;

	std::cout << std::endl << "=== end ===" << std::endl;
}