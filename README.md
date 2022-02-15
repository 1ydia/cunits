# `cunits` A Dimensional Analysis and Conversion Library for C++
This is a project aimed at making unit conversions and dimensional analysis quicker and more readable. In reality, this project was made in a personal attempt to learn more about the c++ language. For a more comprehensive library, I recommend [mp-units](https://github.com/mpusz/units "mp-units"). But who knows? Maybe this will be useful to someone as a lightweight alternative.

All units are implicitly converted to their base value, where then different definitions can be called.

#### Files:
- `units.h` Base unit definition file.
- `basic.h` Includes very basic units like the meter, mole, kilogram, candela, etc.
- `si.h` Includes all SI units and definitions.
- `astro.h` Includes standard static astronomical units. Measurements with uncertainty like *galactic year* and *lunar distance* are not yet included.
#### Planned Files:
- `imperial.h` Includes all basic imperial units like foot, yard, etc.
- `sci.h` Includes scientific values like the charge of the electron, planck length, the gravitational constant, etc.
