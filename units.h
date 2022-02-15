#include <vector>
#include <algorithm>
#pragma once

namespace cunits {
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
}