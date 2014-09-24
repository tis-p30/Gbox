/* Gravity newton box project.
 * File purpose: Units control.
 *               Scene controller unit file header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#ifndef GBOX_SCCONTROL_H
#define GBOX_SCCONTROL_H

#include "../../scene.h"

#include "../complex/planet.h"

namespace gbox
{
  namespace units
  {
    // Default unit
    class UnitScControl : public Scene::UnitDef
    {
    private:
      bool IsDrawAxis;
    public:
      // default constructor
      UnitScControl();
      // unit response function
      void response(Scene &SrcSc);
      // unit drawing function
      void render(Scene &SrcSc);

      // Changing axis draw flag function
      void SetAxisDrawFlag(const bool NewFlag);
    }; // End of 'UnitScControl' class
  } // End of 'units' namespace
} // End of 'gbox' namespace

#endif // GBOX_SCCONTROL_H
