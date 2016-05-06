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
//		CMDUtilsGPDB::InitializeMDColInfo
//
//	@doc:
//		Initialize the attribute number to column array position mapping
//
//---------------------------------------------------------------------------
void
CMDUtilsGPDB::InitializeMDColInfo
	(
	IMemoryPool *pmp,
	DrgPmdcol *pdrgpmdcol,
	HMIUl *phmiulAttno2Pos,
	HMUlUl *phmululNonDroppedCols
	)
{
	GPOS_ASSERT(NULL != pdrgpmdcol);
	GPOS_ASSERT(NULL != phmiulAttno2Pos);

	BOOL fMaintainNonDroppedCols = (NULL != phmululNonDroppedCols);
	const ULONG ulArity = pdrgpmdcol->UlLength();
	ULONG ulPosNonDropped = 0;
	for (ULONG ul = 0; ul < ulArity; ul++)
	{
		const IMDColumn *pmdcol = (*pdrgpmdcol)[ul];

		(void) phmiulAttno2Pos->FInsert
								(
								GPOS_NEW(pmp) INT(pmdcol->IAttno()),
								GPOS_NEW(pmp) ULONG(ul)
								);


		if (fMaintainNonDroppedCols && !pmdcol->FDropped())
		{
			(void) phmululNonDroppedCols->FInsert(GPOS_NEW(pmp) ULONG(ul), GPOS_NEW(pmp) ULONG(ulPosNonDropped));
			ulPosNonDropped++;
		}
	}
}

// EOF
