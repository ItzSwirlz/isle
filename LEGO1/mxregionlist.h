#ifndef MXREGIONLIST_H
#define MXREGIONLIST_H

#include "mxlist.h"

// SIZE 0x08
struct MxRegionLeftRight {
	MxRegionLeftRight(MxS32 p_left, MxS32 p_right)
	{
		m_left = p_left;
		m_right = p_right;
	}

	MxRegionLeftRight* Clone() { return new MxRegionLeftRight(m_left, m_right); }

	inline MxS32 GetLeft() { return m_left; }
	inline MxS32 GetRight() { return m_right; }

	inline void SetLeft(MxS32 p_left) { m_left = p_left; }
	inline void SetRight(MxS32 p_right) { m_right = p_right; }

private:
	MxS32 m_left;
	MxS32 m_right;
};

// VTABLE: LEGO1 0x100dcc40
// class MxCollection<MxRegionLeftRight *>

// VTABLE: LEGO1 0x100dcc58
// class MxList<MxRegionLeftRight *>

// VTABLE: LEGO1 0x100dcc70
// class MxPtrList<MxRegionLeftRight>

// VTABLE: LEGO1 0x100dcc88
// SIZE 0x18
class MxRegionLeftRightList : public MxPtrList<MxRegionLeftRight> {
public:
	MxRegionLeftRightList() : MxPtrList<MxRegionLeftRight>(TRUE) {}
};

// VTABLE: LEGO1 0x100dcbf8
// class MxPtrListCursor<MxRegionLeftRight>

// VTABLE: LEGO1 0x100dcc28
// class MxListCursor<MxRegionLeftRight *>

// VTABLE: LEGO1 0x100dcc10
class MxRegionLeftRightListCursor : public MxPtrListCursor<MxRegionLeftRight> {
public:
	MxRegionLeftRightListCursor(MxRegionLeftRightList* p_list) : MxPtrListCursor<MxRegionLeftRight>(p_list){};
};

// SIZE 0x0c
struct MxRegionTopBottom {
	MxRegionTopBottom(MxRect32& p_rect);
	MxRegionTopBottom(MxS32 p_top, MxS32 p_bottom);
	~MxRegionTopBottom() { delete m_leftRightList; }

	MxRegionTopBottom* Clone();
	void FUN_100c5280(MxS32 p_left, MxS32 p_right);
	MxBool FUN_100c57b0(MxRect32& p_rect);

	inline MxS32 GetTop() { return m_top; }
	inline MxS32 GetBottom() { return m_bottom; }

	inline void SetTop(MxS32 p_top) { m_top = p_top; }
	inline void SetBottom(MxS32 p_bottom) { m_bottom = p_bottom; }

	friend class MxRegionList;

private:
	MxS32 m_top;
	MxS32 m_bottom;
	MxRegionLeftRightList* m_leftRightList;
};

// VTABLE: LEGO1 0x100dcb10
// class MxCollection<MxRegionTopBottom *>

// VTABLE: LEGO1 0x100dcb28
// class MxList<MxRegionTopBottom *>

// VTABLE: LEGO1 0x100dcb40
// class MxPtrList<MxRegionTopBottom>

// VTABLE: LEGO1 0x100dcb58
// SIZE 0x18
class MxRegionList : public MxPtrList<MxRegionTopBottom> {
public:
	MxRegionList() : MxPtrList<MxRegionTopBottom>(TRUE) {}
};

// VTABLE: LEGO1 0x100dcb70
// class MxPtrListCursor<MxRegionTopBottom>

// VTABLE: LEGO1 0x100dcba0
// class MxListCursor<MxRegionTopBottom *>

// TODO: The initialize list param type should be MxRegionList, but doing that
// drastically reduced the match percentage for MxRegion::VTable0x18.
// It also works with MxPtrList, so we'll do that until we figure this out.

// VTABLE: LEGO1 0x100dcb88
class MxRegionListCursor : public MxPtrListCursor<MxRegionTopBottom> {
public:
	MxRegionListCursor(MxPtrList<MxRegionTopBottom>* p_list) : MxPtrListCursor<MxRegionTopBottom>(p_list){};
};

// TEMPLATE: LEGO1 0x100c32e0
// MxCollection<MxRegionTopBottom *>::Compare

// TEMPLATE: LEGO1 0x100c3340
// MxCollection<MxRegionTopBottom *>::Destroy

// TEMPLATE: LEGO1 0x100c33e0
// MxPtrList<MxRegionTopBottom>::Destroy

// SYNTHETIC: LEGO1 0x100c34d0
// MxCollection<MxRegionTopBottom *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c3540
// MxList<MxRegionTopBottom *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c35f0
// MxPtrList<MxRegionTopBottom>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c3be0
// MxRegionListCursor::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c3c50
// MxPtrListCursor<MxRegionTopBottom>::~MxPtrListCursor<MxRegionTopBottom>

// SYNTHETIC: LEGO1 0x100c3ca0
// MxListCursor<MxRegionTopBottom *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c3d10
// MxPtrListCursor<MxRegionTopBottom>::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c3d80
// MxListCursor<MxRegionTopBottom *>::~MxListCursor<MxRegionTopBottom *>

// FUNCTION: LEGO1 0x100c3dd0
// MxRegionListCursor::~MxRegionListCursor

// SYNTHETIC: LEGO1 0x100c4790
// MxRegionLeftRightListCursor::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c4800
// MxPtrListCursor<MxRegionLeftRight>::~MxPtrListCursor<MxRegionLeftRight>

// SYNTHETIC: LEGO1 0x100c4850
// MxListCursor<MxRegionLeftRight *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c48c0
// MxPtrListCursor<MxRegionLeftRight>::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c4930
// MxListCursor<MxRegionLeftRight *>::~MxListCursor<MxRegionLeftRight *>

// TEMPLATE: LEGO1 0x100c4d80
// MxCollection<MxRegionLeftRight *>::Compare

// TEMPLATE: LEGO1 0x100c4de0
// MxCollection<MxRegionLeftRight *>::Destroy

// SYNTHETIC: LEGO1 0x100c4f50
// MxCollection<MxRegionLeftRight *>::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c4e80
// MxPtrList<MxRegionLeftRight>::Destroy

// SYNTHETIC: LEGO1 0x100c4fc0
// MxList<MxRegionLeftRight *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c5070
// MxPtrList<MxRegionLeftRight>::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x100c54f0
// MxListCursor<MxRegionLeftRight *>::MxListCursor<MxRegionLeftRight *>

// FUNCTION: LEGO1 0x100c5560
// MxRegionLeftRightListCursor::~MxRegionLeftRightListCursor

// TEMPLATE: LEGO1 0x100c55b0
// MxListCursor<MxRegionLeftRight *>::operator=

// TEMPLATE: LEGO1 0x100c58c0
// MxList<MxRegionLeftRight *>::InsertEntry

// TEMPLATE: LEGO1 0x100c5970
// MxList<MxRegionTopBottom *>::InsertEntry

// TEMPLATE: LEGO1 0x100c5a20
// MxListEntry<MxRegionTopBottom *>::MxListEntry<MxRegionTopBottom *>

// TEMPLATE: LEGO1 0x100c5a40
// MxList<MxRegionLeftRight *>::DeleteEntry

#endif // MXREGIONLIST_H
