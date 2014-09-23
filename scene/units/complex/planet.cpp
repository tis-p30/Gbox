/* Gravity newton box project.
 * File purpose: Complex units.
 *               Unit planet source file.
 * Authors: Tikhonenko Iliya (tis-p30) <iliya.t@mail.ru>,
 *          Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */


#include "planet.h"

// Default constructor
gbox::units::UnitPlanet::UnitPlanet() :
  Sphere(GVec(0)), regime(MODE_SETTING)
{
}

// Response for 'Setting' regime function
void gbox::units::UnitPlanet::responseModeSet()
{
}

// Response for 'Active' regime function
void gbox::units::UnitPlanet::responseModeAct()
{
}

// Response callback function
void gbox::units::UnitPlanet::response()
{
}

// Render callback function
void gbox::units::UnitPlanet::render()
{
}

