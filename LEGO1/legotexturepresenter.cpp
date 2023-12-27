#include "legotexturepresenter.h"

#include "legoomni.h"
#include "legovideomanager.h"
#include "mxcompositepresenter.h"

// FUNCTION: LEGO1 0x1004eb40
LegoTexturePresenter::~LegoTexturePresenter()
{
	VideoManager()->RemovePresenter(*this);
}

// FUNCTION: LEGO1 0x1004ebb0
MxResult LegoTexturePresenter::AddToManager()
{
	VideoManager()->AddPresenter(*this);
	return SUCCESS;
}

// STUB: LEGO1 0x1004fc60
MxResult LegoTexturePresenter::PutData()
{
	// TODO
	return FAILURE;
}

// FUNCTION: LEGO1 0x1004fcb0
void LegoTexturePresenter::DoneTickle()
{
	if (this->m_compositePresenter) {
		if (this->m_compositePresenter->VTable0x64(2) == 0) {
			SetTickleState(TickleState_Idle);
			return;
		}
	}
	MxMediaPresenter::DoneTickle();
}
