#pragma once
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(#{base_class_name}Config,

  DECLARE_VALUE(#{base_class_name}Enabled, bool, "Enabled?", true);

  INIT_FUNCTION(
    INIT_VALUE(#{base_class_name}Enabled);
  )

)
