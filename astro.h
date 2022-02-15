#include "units.h"
#pragma once

namespace cunits {
    static const Unit lightspeed = 2.99792458E+8 * meter / second;

    static const Unit lightyear = lightspeed * year;
    static const Unit lightsecond = lightspeed * second;

    static const Unit parsec = 3.0856775814913673E+16 * meter;
    static const Unit astronomical_unit = 1.495978707E+11 * meter;
    static const Unit lunar_distance = 3.844E+8 * meter;

    static const Unit solar_mass = 1.98892E+30 * kilogram;
    static const Unit jupiter_mass = 1.898E+27 * kilogram;
    static const Unit earth_mass = 5.9742E+24 * kilogram;
}
