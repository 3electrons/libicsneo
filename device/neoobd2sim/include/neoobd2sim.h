#ifndef __NEOOBD2SIM_H_
#define __NEOOBD2SIM_H_

#include "device/include/device.h"
#include "platform/include/stm32.h"

namespace icsneo {

class NeoOBD2SIM : public Device {
public:
	// Serial numbers are OS****
	static constexpr const char* PRODUCT_NAME = "neoOBD2-SIM";
	static constexpr const uint16_t PRODUCT_ID = 0x1100;
	NeoOBD2SIM(neodevice_t neodevice) : Device(neodevice) {
		com = std::make_shared<Communication>(std::make_shared<STM32>(getWritableNeoDevice()));
		setProductName(PRODUCT_NAME);
		productId = PRODUCT_ID;
	}

	static std::vector<std::shared_ptr<Device>> Find() {
		std::vector<std::shared_ptr<Device>> found;

		for(auto neodevice : STM32::FindByProduct(PRODUCT_ID))
			found.push_back(std::make_shared<NeoOBD2SIM>(neodevice));

		return found;
	}
};

}

#endif