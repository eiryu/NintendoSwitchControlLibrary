/*
Copyright (c) 2019 celclow
released under the MIT license
https://opensource.org/licenses/mit-license.php
*/

#include "./CustomHID.h"

#ifndef TRANSFER_RELEASE
#define TRANSFER_RELEASE 0
#endif

#if defined(USBCON)

CustomHID_::CustomHID_() {}

int CustomHID_::SendReport(const void *data, int len) {
#if defined(ARDUINO_SEEED_XIAO_M0)
  auto ret = USBDevice.send(pluggedEndpoint | TRANSFER_RELEASE, data, len);
#else
  auto ret = USB_Send(pluggedEndpoint | TRANSFER_RELEASE, data, len);
#endif
  return ret;
}

CustomHID_ &CustomHID() {
  static CustomHID_ obj;
  return obj;
}

#endif /* if defined(USBCON) */
