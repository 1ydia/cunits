#include <vector>
#include <map>
#include <algorithm>
#pragma once

namespace cunits {
    /* Ideas for new features:
    * 1. Uncertainty (a±b)
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
    static bool operator ==(UnitPart a, UnitPart b) {
        return a.type == b.type && a.exp == b.exp;
    }

    class Unit {
    public:
        std::vector<UnitPart> parts;
        double value;
        Unit(double _value) {
            value = _value;
        }
        Unit(std::vector<UnitPart> _parts, double _value) {
            parts = _parts;
            value = _value;
        }
        Unit(BaseUnit _type, double _value) {
            parts.push_back(UnitPart(_type, 1));
            value = _value;
        }
    };
    // Unit Instance Functions
    void simplify() {
        this = this.simplified();
    }
    Unit simplified() {
        std::vector<UnitPart> newparts;
        for (UnitPart p : parts) {
            auto isSameType = [](UnitPart up) { return up.type == p.type; }
            std::vector<UnitPart>::iterator itr = std::ranges::find_if(newparts, isSamePart);
            size_t index = std::distance(parts.begin(), itr);
            if (index == parts.cend()) {
                newparts.push_back(p);
            }
            else {
                newparts.at(index).exp += p.exp;
            }
        }
        std::vector<UnitPart> trimmedparts;
        for (UnitPart p : newparts) {
            if (p.exp != 0) {
                trimmedparts.push_back(p);
            }
        }
        return Unit(trimmedparts, value);
    }
    
    // Unit Operators
    static Unit operator *(Unit a, Unit b) {
        std::vector<UnitPart> newparts = a.parts;
        for (UnitPart& part : b.parts) {
            std::vector<UnitPart>::iterator it = std::ranges::find(newparts, part);
            if (it == newparts.end()) {
                newparts.push_back(part);
            }
            else {
                newpart.exp *= next(it)->exp;
            }
        }
        return Unit(parts, a.value * b.value);
        return a;
    }
    static Unit operator *(Unit u, double d) {
        return Unit(u.parts, u.value * d);
    }
    static Unit operator *(double d, Unit u) {
        return Unit(u.parts, u.value * d);
    }

    static Unit operator /(Unit a, Unit b) {
        for (UnitPart& p : b.parts) {
            p.exp *= -1;
        }
        b.value = 1 / b.value;
        return a * b;
    }
    static Unit operator /(Unit u, double d) {
        u.value /= d;
        return u;
    }
    static Unit operator /(double d, Unit u) {
        for (UnitPart& p : u.parts) {
            p.exp *= -1;
        }
        u.value = d / u.value;
        return u;
    }

    Unit operator "" c(unsigned long long int i) {
        return Unit(i);
    }
    Unit operator "" c(long double d) {
        return Unit(d);
    }
}