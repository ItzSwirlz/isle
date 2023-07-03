#include "mxpalette.h"

// OFFSET: LEGO1 0x100bf150
MxResult MxPalette::GetEntries(LPPALETTEENTRY p_entries)
{
  memcpy(p_entries, this->m_entries, sizeof(this->m_entries));
  return SUCCESS;
}

// OFFSET: LEGO1 0x100bf2d0
int MxPalette::SetSkyColor(LPPALETTEENTRY p_sky_color)
{
  // not 100% matching yet, register allocation is being weird
  LPDIRECTDRAWPALETTE palette = this->m_pDirectDrawPalette;
  if ( palette )
  {
    this->m_entries[141].peRed = p_sky_color->peRed;
    this->m_entries[141].peGreen = p_sky_color->peGreen;
    this->m_entries[141].peBlue = p_sky_color->peBlue;
    this->m_skyColor = this->m_entries[141];
    
    if ( palette->SetEntries(0, 141, 1, &this->m_skyColor) )
      return -1;
  }
  return 0;
}

// OFFSET: LEGO1 0x100bf340
MxBool MxPalette::operator==(MxPalette &other)
{
  int i;
  for (i = 0; i < 256; i++)
  {
    if (this->m_entries[i].peRed != other.m_entries[i].peRed)
      return FALSE;
    if (this->m_entries[i].peGreen != other.m_entries[i].peGreen)
      return FALSE;
    if (this->m_entries[i].peBlue != other.m_entries[i].peBlue)
      return FALSE;
  }
  return TRUE;
}

// OFFSET: LEGO1 0x100bf330
void MxPalette::Detach()
{
  this->m_pDirectDrawPalette = NULL;
}
