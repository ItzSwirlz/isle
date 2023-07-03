#include "mxpalette.h"

// OFFSET: LEGO1 0x100bee30
MxPalette::MxPalette()
{
  this->m_overrideSkyColor = FALSE;
  this->m_palette = NULL;
  GetDefaultPalette(this->m_entries);
  this->m_skyColor = this->m_entries[141];
}

// OFFSET: LEGO1 100bef90
MxPalette::~MxPalette()
{
  if (m_palette) {
    m_palette->Release();
  }
}

// OFFSET: LEGO1 0x100bf390
void MxPalette::ApplySystemEntriesToPalette(LPPALETTEENTRY p_entries)
{
  // FIXME: incomplete
  HDC hdc = GetDC(NULL);
  int rastercaps = GetDeviceCaps(hdc, RASTERCAPS);
  int sizepalettecaps;
  if ((rastercaps & RC_PALETTE) != 0) {
    sizepalettecaps = GetDeviceCaps(hdc, SIZEPALETTE);
    if(sizepalettecaps = 256) {
      GetSystemPaletteEntries(hdc,0,10,p_entries);
      GetSystemPaletteEntries(hdc,246,10,p_entries + 0xf6);
      ReleaseDC(NULL, hdc);
    }
  }
  // FIXME: we get g_defaultPalette here, we need to define that, then we cna do the memcpy's
}

// OFFSET: LEGO1 100bf0b0
MxPalette* MxPalette::Clone()
{
  // FIXME: doesnt match
  MxPalette *pal = (MxPalette *) malloc(0x414);
  if(pal != NULL) {
    GetEntries(pal->m_entries);
    pal->m_overrideSkyColor = m_overrideSkyColor;
  }
  return pal;
}

// OFFSET: LEGO1 0x100beed0
MxPalette* MxPalette::FromBitmapPalette(RGBQUAD* p_bmp)
{
  // FIXME: Incomplete
  this->m_overrideSkyColor = FALSE;
  ApplySystemEntriesToPalette(this->m_entries);
  memcpy(this->m_entries + 10, &p_bmp[10], 246);
  this->m_skyColor = this->m_entries[141];
  return this;
}

// OFFSET: LEGO1 0x100bf150
MxResult MxPalette::GetEntries(LPPALETTEENTRY p_entries)
{
  memcpy(p_entries, this->m_entries, sizeof(this->m_entries));
  return SUCCESS;
}

// OFFSET: LEGO1 0x100bf2d0
MxResult MxPalette::SetSkyColor(LPPALETTEENTRY p_entries)
{
  // FIXME: doesnt match
  MxResult ret = SUCCESS;
  this->m_entries[141].peRed = p_entries->peRed;
  this->m_entries[141].peGreen = p_entries->peGreen;
  this->m_entries[141].peBlue = p_entries->peBlue;
  this->m_skyColor = this->m_entries[141];
  return ret;
}

// OFFSET: LEGO1 0x100bf420
void MxPalette::GetDefaultPalette(LPPALETTEENTRY p_entries)
{
  HDC hdc = GetDC((HWND) NULL);
  int rasterCaps = GetDeviceCaps(hdc, RASTERCAPS);
  LPPALETTEENTRY src;
  MxS32 count;
  
  if ((rasterCaps & RC_PALETTE) != 0 && GetDeviceCaps(hdc, SIZEPALETTE) == 256) {
    GetSystemPaletteEntries(hdc, 0, 256, p_entries);
    count = 256 - 2 * 10;
    src = (LPPALETTEENTRY) &m_palette[10];
    p_entries += 10;
  } else {
    src = (LPPALETTEENTRY) m_palette;
    count = 256;
  }
  void* dest;
  memcpy(dest, p_entries, count * sizeof(PALETTEENTRY));
  ReleaseDC((HWND) NULL, hdc);
}

// OFFSET: LEGO1 0x100bf340
MxBool MxPalette::operator==(MxPalette *p_palette)
{
  // FIXME: ok, idk what is happening here: trying memcpy in different ways showed 0.00% match. Here is literally what it does.
  // My guess is that memcpy doesn't break its loop when something is incorrect, and this function is only intended to check
  // the RGB and memcpy does everything? The paramater 'rhs' in ghidra suggests it was likely some memcmp. For now,
  // this is literally down to instruction swap.
  int i = 0;
  PALETTEENTRY *our = this->m_entries;
  PALETTEENTRY *their = p_palette->m_entries;
  do {
    if(our->peRed != their->peRed) return FALSE;
    if(our->peGreen != their->peGreen) return FALSE;
    if(our->peBlue != their->peBlue) return FALSE;
    their += 1;
    our += 1;
    i += 1;
  } while (i < 256);
  return TRUE;
}

// OFFSET: LEGO1 0x100bf330
void MxPalette::Detach()
{
  this->m_palette = NULL;
}
  
