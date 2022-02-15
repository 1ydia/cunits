#include "units.h"
#pragma once

namespace cunits {
    static const Unit minute = 60 * second;
    static const Unit hour = 60 * minute;
    static const Unit day = 24 * hour;
    static const Unit year = 365.25 * day;
}
