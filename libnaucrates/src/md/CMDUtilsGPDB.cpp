//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2016 Pivotal Inc.
//
//	@filename:
//		CMDUtilsGPDB.cpp
//
//	@doc:
//		Implementation of utils function that are used by GPDB related metadata
//
//---------------------------------------------------------------------------

#include "naucrates/md/CMDUtilsGPDB.h"

using namespace gpdxl;
using namespace gpmd;

//---------------------------------------------------------------------------
//	@function:
//		CMDUtilsGPDB::InitializeAttrNumToArrayPositionMap
//
//	@doc:
//		Initialize the attribute number to column array position mapping
//
//---------------------------------------------------------------------------
void
CMDUtilsGPDB::InitializeAttrNumToArrayPositionMap
	(
	IMemoryPool *pmp,
	DrgPmdcol *pdrgpmdcol,
	HMIUl *phmiulAttno2Pos
	)
{
	GPOS_ASSERT(NULL != pdrgpmdcol);
	GPOS_ASSERT(NULL != phmiulAttno2Pos);

	const ULONG ulArity = pdrgpmdcol->UlLength();
	for (ULONG ul = 0; ul < ulArity; ul++)
	{
		const IMDColumn *pmdcol = (*pdrgpmdcol)[ul];

		(void) phmiulAttno2Pos->FInsert
								(
								GPOS_NEW(pmp) INT(pmdcol->IAttno()),
								GPOS_NEW(pmp) ULONG(ul)
								);
	}
}

// EOF
