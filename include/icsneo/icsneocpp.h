#ifndef __ICSNEOCPP_H_
#define __ICSNEOCPP_H_

#include <vector>
#include <memory>

#include "icsneo/device/device.h"
#include "icsneo/api/version.h"
#include "icsneo/api/eventmanager.h"

#include "icsneo/communication/message/canmessage.h"
#include "icsneo/communication/message/ethernetmessage.h"

namespace icsneo {

std::vector<std::shared_ptr<Device>> FindAllDevices();
std::vector<DeviceType> GetSupportedDevices();

size_t EventCount(EventFilter filter = EventFilter());
std::vector<APIEvent> GetEvents(EventFilter filter, size_t max = 0);
std::vector<APIEvent> GetEvents(size_t max = 0, EventFilter filter = EventFilter());
void GetEvents(std::vector<APIEvent>& events, EventFilter filter, size_t max = 0);
void GetEvents(std::vector<APIEvent>& events, size_t max = 0, EventFilter filter = EventFilter());
APIEvent GetLastError();
void DiscardEvents(EventFilter filter = EventFilter());
void SetEventLimit(size_t newLimit);
size_t GetEventLimit();

}

#endif