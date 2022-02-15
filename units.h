#include <vector>
#include <algorithm>
#pragma once

namespace units {
    /* Ideas for new features:
    * 1. Literals
    * 2. Uncertainty (a±b)
    */

    enum BaseUnit { METER, KILOGRAM, SECOND, AMPERE, KELVIN, MOLE, CANDELA };

    struct UnitPart {
        BaseUnit type;
        int exp;
        UnitPart(BaseUnit _type, int _exp) {
            type = _type;
            exp = _exp;
        }
    };
    static bool operator==(UnitPart a, UnitPart b) {
        return a.type == b.type && a.exp == b.exp;
    }

    class Unit {
    public:
        std::vector<UnitPart> parts;
        double value;
        Unit(std::vector<UnitPart> _parts, double _value) {
            parts = _parts;
            value = _value;
        }
        Unit(BaseUnit _type, double _value) {
            parts.push_back(UnitPart(_type, 1));
            value = _value;
        }
    };
    // Unit Operators
    static Unit operator*(Unit a, Unit b) {
        std::vector<UnitPart> parts = a.parts;
        for (UnitPart& part : b.parts) {
            std::vector<UnitPart>::iterator it = std::find(parts.begin(), parts.end(), part);
            if (it == parts.end()) {
                parts.push_back(part);
            }
            else {
                part.exp *= next(it)->exp;
            }
        }
        return Unit(parts, a.value * b.value);
        return a;
    }
    static Unit operator*(Unit u, double d) {
        return Unit(u.parts, u.value * d);
    }
    static Unit operator*(double d, Unit u) {
        return Unit(u.parts, u.value * d);
    }

    static Unit operator/(Unit a, Unit b) {
        for (UnitPart& p : b.parts) {
            p.exp *= -1;
        }
        b.value = 1 / b.value;
        return a * b;
    }
    static Unit operator/(Unit u, double d) {
        u.value /= d;
        return u;
    }
    static Unit operator/(double d, Unit u) {
        for (UnitPart& p : u.parts) {
            p.exp *= -1;
        }
        u.value = d / u.value;
        return u;
    }

    // BASE UNITS
    static const Unit meter = Unit(BaseUnit::METER, 1);
    static const Unit kilogram = Unit(BaseUnit::KILOGRAM, 1);
    static const Unit second = Unit(BaseUnit::SECOND, 1);
    static const Unit ampere = Unit(BaseUnit::AMPERE, 1);
    static const Unit kelvin = Unit(BaseUnit::KELVIN, 1);
    static const Unit mole = Unit(BaseUnit::MOLE, 1);
    static const Unit candela = Unit(BaseUnit::CANDELA, 1);

    // SI UNITS
    // Length
    static const Unit yottameter = 1E+24 * meter;
    static const Unit zettameter = 1E+21 * meter;
    static const Unit exameter = 1E+18 * meter;
    static const Unit petameter = 1E+15 * meter;
    static const Unit terameter = 1E+12 * meter;
    static const Unit gigameter = 1E+9 * meter;
    static const Unit megameter = 1E+6 * meter;
    static const Unit kilometer = 1E+3 * meter;
    static const Unit hectometer = 1E+2 * meter;
    static const Unit decameter = 1E+1 * meter;
    // meter
    static const Unit decimeter = 1E-1 * meter;
    static const Unit centimeter = 1E-2 * meter;
    static const Unit millimeter = 1E-3 * meter;
    static const Unit micrometer = 1E-6 * meter;
    static const Unit nanometer = 1E-9 * meter;
    static const Unit picometer = 1E-12 * meter;
    static const Unit femtometer = 1E-15 * meter;
    static const Unit attometer = 1E-18 * meter;
    static const Unit zeptometer = 1E-21 * meter;
    static const Unit yoctometer = 1E-24 * meter;

    // Mass
    static const Unit yottagram = 1E+21 * kilogram;
    static const Unit zettagram = 1E+18 * kilogram;
    static const Unit exagram = 1E+15 * kilogram;
    static const Unit petagram = 1E+12 * kilogram;
    static const Unit teragram = 1E+9 * kilogram;
    static const Unit gigagram = 1E+6 * kilogram;
    static const Unit megagram = 1E+3 * kilogram;
    // kilogram
    static const Unit hectogram = 1E-1 * kilogram;
    static const Unit decagram = 1E-2 * kilogram;
    static const Unit gram = 1E-3 * kilogram;
    static const Unit decigram = 1E-4 * kilogram;
    static const Unit centigram = 1E-5 * kilogram;
    static const Unit milligram = 1E-6 * kilogram;
    static const Unit microgram = 1E-9 * kilogram;
    static const Unit nanogram = 1E-12 * kilogram;
    static const Unit picogram = 1E-15 * kilogram;
    static const Unit femtogram = 1E-18 * kilogram;
    static const Unit attogram = 1E-21 * kilogram;
    static const Unit zeptogram = 1E-24 * kilogram;
    static const Unit yoctogram = 1E-27 * kilogram;

    // Time
    static const Unit yottasecond = 1E+24 * second;
    static const Unit zettasecond = 1E+21 * second;
    static const Unit exasecond = 1E+18 * second;
    static const Unit petasecond = 1E+15 * second;
    static const Unit terasecond = 1E+12 * second;
    static const Unit gigasecond = 1E+9 * second;
    static const Unit megasecond = 1E+6 * second;
    static const Unit kilosecond = 1E+3 * second;
    static const Unit hectosecond = 1E+2 * second;
    static const Unit decasecond = 1E+1 * second;
    // second
    static const Unit decisecond = 1E-1 * second;
    static const Unit centisecond = 1E-2 * second;
    static const Unit millisecond = 1E-3 * second;
    static const Unit microsecond = 1E-6 * second;
    static const Unit nanosecond = 1E-9 * second;
    static const Unit picosecond = 1E-12 * second;
    static const Unit femtosecond = 1E-15 * second;
    static const Unit attosecond = 1E-18 * second;
    static const Unit zeptosecond = 1E-21 * second;
    static const Unit yoctosecond = 1E-24 * second;

    // Electric Current
    static const Unit yottaampere = 1E+24 * ampere;
    static const Unit zettaampere = 1E+21 * ampere;
    static const Unit exaampere = 1E+18 * ampere;
    static const Unit petaampere = 1E+15 * ampere;
    static const Unit teraampere = 1E+12 * ampere;
    static const Unit gigaampere = 1E+9 * ampere;
    static const Unit megaampere = 1E+6 * ampere;
    static const Unit kiloampere = 1E+3 * ampere;
    static const Unit hectoampere = 1E+2 * ampere;
    static const Unit decaampere = 1E+1 * ampere;
    // ampere
    static const Unit deciampere = 1E-1 * ampere;
    static const Unit centiampere = 1E-2 * ampere;
    static const Unit milliampere = 1E-3 * ampere;
    static const Unit microampere = 1E-6 * ampere;
    static const Unit nanoampere = 1E-9 * ampere;
    static const Unit picoampere = 1E-12 * ampere;
    static const Unit femtoampere = 1E-15 * ampere;
    static const Unit attoampere = 1E-18 * ampere;
    static const Unit zeptoampere = 1E-21 * ampere;
    static const Unit yoctoampere = 1E-24 * ampere;

    // Thermodynamic Temperature
    static const Unit yottakelvin = 1E+24 * kelvin;
    static const Unit zettakelvin = 1E+21 * kelvin;
    static const Unit exakelvin = 1E+18 * kelvin;
    static const Unit petakelvin = 1E+15 * kelvin;
    static const Unit terakelvin = 1E+12 * kelvin;
    static const Unit gigakelvin = 1E+9 * kelvin;
    static const Unit megakelvin = 1E+6 * kelvin;
    static const Unit kilokelvin = 1E+3 * kelvin;
    static const Unit hectokelvin = 1E+2 * kelvin;
    static const Unit decakelvin = 1E+1 * kelvin;
    // kelvin
    static const Unit decikelvin = 1E-1 * kelvin;
    static const Unit centikelvin = 1E-2 * kelvin;
    static const Unit millikelvin = 1E-3 * kelvin;
    static const Unit microkelvin = 1E-6 * kelvin;
    static const Unit nanokelvin = 1E-9 * kelvin;
    static const Unit picokelvin = 1E-12 * kelvin;
    static const Unit femtokelvin = 1E-15 * kelvin;
    static const Unit attokelvin = 1E-18 * kelvin;
    static const Unit zeptokelvin = 1E-21 * kelvin;
    static const Unit yoctokelvin = 1E-24 * kelvin;

    // Amount of Substance
    static const Unit yottamole = 1E+24 * mole;
    static const Unit zettamole = 1E+21 * mole;
    static const Unit examole = 1E+18 * mole;
    static const Unit petamole = 1E+15 * mole;
    static const Unit teramole = 1E+12 * mole;
    static const Unit gigamole = 1E+9 * mole;
    static const Unit megamole = 1E+6 * mole;
    static const Unit kilomole = 1E+3 * mole;
    static const Unit hectomole = 1E+2 * mole;
    static const Unit decamole = 1E+1 * mole;
    // mole
    static const Unit decimole = 1E-1 * mole;
    static const Unit centimole = 1E-2 * mole;
    static const Unit millimole = 1E-3 * mole;
    static const Unit micromole = 1E-6 * mole;
    static const Unit nanomole = 1E-9 * mole;
    static const Unit picomole = 1E-12 * mole;
    static const Unit femtomole = 1E-15 * mole;
    static const Unit attomole = 1E-18 * mole;
    static const Unit zeptomole = 1E-21 * mole;
    static const Unit yoctomole = 1E-24 * mole;

    // Luminous Intensity
    static const Unit yottacandela = 1E+24 * candela;
    static const Unit zettacandela = 1E+21 * candela;
    static const Unit exacandela = 1E+18 * candela;
    static const Unit petacandela = 1E+15 * candela;
    static const Unit teracandela = 1E+12 * candela;
    static const Unit gigacandela = 1E+9 * candela;
    static const Unit megacandela = 1E+6 * candela;
    static const Unit kilocandela = 1E+3 * candela;
    static const Unit hectocandela = 1E+2 * candela;
    static const Unit decacandela = 1E+1 * candela;
    // candela
    static const Unit decicandela = 1E-1 * candela;
    static const Unit centicandela = 1E-2 * candela;
    static const Unit millicandela = 1E-3 * candela;
    static const Unit microcandela = 1E-6 * candela;
    static const Unit nanocandela = 1E-9 * candela;
    static const Unit picocandela = 1E-12 * candela;
    static const Unit femtocandela = 1E-15 * candela;
    static const Unit attocandela = 1E-18 * candela;
    static const Unit zeptocandela = 1E-21 * candela;
    static const Unit yoctocandela = 1E-24 * candela;

    // STANDARD TIME UNITS
    static const Unit minute = 60 * second;
    static const Unit hour = 60 * minute;
    static const Unit day = 24 * hour;
    static const Unit year = 365.25 * day;

    // ASTRONOMICAL SYSTEM OF UNITS
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
