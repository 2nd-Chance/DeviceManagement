#include <iostream>

#include "json.hpp"
#include "DeviceInfoEntityClass.h"
#include "DeviceInfoTable.h"

int main(void)
{
	std::cout << "=== start ===" << std::endl << std::endl;

	std::shared_ptr<DeviceInfoEntityClass1> tuple(
		new DeviceInfoEntityClass1());
	tuple->setDeviceId(123);
	tuple->setDeviceUuid("dev uuid");
	tuple->setBluetoothMac("bt mac");
	tuple->setSensorType("sens type");
	tuple->setSensorValue("sens val");
	tuple->test(99);
	tuple->test(88);
	
	std::cout << tuple->getDeviceId() << std::endl
		<< tuple->getDeviceUuid() << std::endl
		<< tuple->getBluetoothMac() << std::endl;

	std::shared_ptr<DeviceInfoTable> table(new DeviceInfoTable());
	table->addTuple(tuple);
	auto found = table->getTuple(123);
	if (found)
	{
		std::cout << found->getJson().dump() << std::endl;
	}
	std::cout << table->removeTuple(123) << std::endl;
	std::cout << table->removeTuple(123) << std::endl;

	std::cout << std::endl << "=== end ===" << std::endl;
}