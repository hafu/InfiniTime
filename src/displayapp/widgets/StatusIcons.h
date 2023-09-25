#pragma once

#include <lvgl/lvgl.h>

#include "displayapp/screens/Screen.h"
#include "components/battery/BatteryController.h"
#include "components/ble/BleController.h"
#include "components/settings/Settings.h"
#include "displayapp/screens/BatteryIcon.h"
#include "utility/DirtyValue.h"

namespace Pinetime {
  namespace Applications {
    namespace Widgets {
      class StatusIcons {
      public:
        StatusIcons(Controllers::Settings& settingsController, const Controllers::Battery& batteryController, const Controllers::Ble& bleController);
        void Align();
        void Create();

        lv_obj_t* GetObject() {
          return container;
        }

        void Update();

      private:
        Screens::BatteryIcon batteryIcon;
        Controllers::Settings& settingsController;
        const Pinetime::Controllers::Battery& batteryController;
        const Controllers::Ble& bleController;

        Utility::DirtyValue<uint8_t> batteryPercentRemaining {};
        Utility::DirtyValue<bool> powerPresent {};
        Utility::DirtyValue<bool> bleState {};
        Utility::DirtyValue<bool> bleRadioEnabled {};
        Utility::DirtyValue<Pinetime::Controllers::Settings::Notification> notificationStatus {};

        lv_obj_t* bleIcon;
        lv_obj_t* batteryPlug;
        lv_obj_t* container;
        lv_obj_t* notificationOffIcon;
        lv_obj_t* notificationSleepIcon;
      };
    }
  }
}
