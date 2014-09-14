/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Scene controller unit file header.
 */

#ifndef SCCONTROL_H
#define SCCONTROL_H

#include "../../scene.h"

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

#endif // SCCONTROL_H
