//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2016 Pivotal Inc.
//
//	@filename:
//		CMDUtilsGPDB.h
//
//	@doc:
//		Utils function that are used by GPDB related metadata
//
//---------------------------------------------------------------------------

#ifndef GPMD_CMDUtilsGPDB_H
#define GPMD_CMDUtilsGPDB_H

#include "gpos/base.h"

#include "naucrates/md/IMDRelation.h"

namespace gpmd
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CMDUtilsGPDB
	//
	//	@doc:
	//		Utils function that are used by GPDB related metadata
	//
	//---------------------------------------------------------------------------
	class CMDUtilsGPDB
	{
		public:

			// initialize the attribute number to column array position mapping
			static
			void InitializeAttrNumToArrayPositionMap
				(
				IMemoryPool *pmp,
				DrgPmdcol *pdrgpmdcol,
				HMIUl *phmiulAttno2Pos
				);

	};

}

#endif // !GPMD_CMDUtilsGPDB_H

// EOF
