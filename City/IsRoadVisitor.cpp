/**
 * \file IsRoadVisitor.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include "IsRoadVisitor.h"
#include "TileRoad.h"


/** \brief Visit a CTileRoad object
* \param road Road tile we are visiting */
void CIsRoadVisitor::VisitRoad(CTileRoad* road)
{
	mIsRoad = true;
}
