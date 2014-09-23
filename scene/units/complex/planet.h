/* Gravity newton box project.
 * File purpose: Complex units.
 *               Unit planet source file.
 * Authors: Tikhonenko Iliya (tis-p30) <iliya.t@mail.ru>,
 *          Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_PLANET_H
#define GBOX_PLANET_H

#include "../base/sphere.h"

namespace gbox
{
  namespace units
  {
    // Default planet class
    class UnitPlanet : public units::Sphere
    {
    private:
      enum
      {
        MODE_SETTING, MODE_ACTIVE
      } regime;

      // Response for 'Setting' regime function
      void responseModeSet();
      // Response for 'Active' regime function
      void responseModeAct();
    public:
      // Default constructor
      UnitPlanet();

      // Response callback function
      void response();
      // Render callback function
      void render();
    }; // End of 'UnitPlanet' class
  } // End of 'units' namespace
} // End of 'gbox' namespace
#endif // GBOX_PLANET_H
