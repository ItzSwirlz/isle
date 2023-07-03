#ifndef MXPALETTE_H
#define MXPALETTE_H

#include <ddraw.h>

#include "mxcore.h"
#include "mxtypes.h"

// VTABLE 0x100dc848
// SIZE 0x414
class MxPalette : public MxCore
{
public:
  __declspec(dllexport) MxBool operator==(MxPalette &);
  __declspec(dllexport) void Detach();

  // there might be a method in between these two
  MxResult GetEntries(LPPALETTEENTRY p_entries);
  int SetSkyColor(LPPALETTEENTRY p_sky_color);
private:
  LPDIRECTDRAWPALETTE m_pDirectDrawPalette;
  PALETTEENTRY m_entries[256];
  MxBool m_unk40C;
  PALETTEENTRY m_skyColor;
};

#endif // MXPALETTE_H
