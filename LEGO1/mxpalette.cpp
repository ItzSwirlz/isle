#include "mxpalette.h"

// OFFSET: LEGO1 0x100bf150
MxResult MxPalette::GetEntries(LPPALETTEENTRY p_entries)
{
  memcpy(p_entries, this->m_entries, sizeof(this->m_entries));
  return SUCCESS;
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
  // TODO
}
