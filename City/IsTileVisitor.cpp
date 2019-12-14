/**
 * \file IsTileVisitor.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */


#include "pch.h"
#include "IsTileVisitor.h"
#include "IsRoadVisitor.h"
#include "TileRoad.h"

/** \brief Visit a CTileRoad object
* \param road Road tile we are visiting */
void CIsTileVisitor::VisitRoad(CTileRoad* road)
{
	auto upperLeft = true;
	auto upperRight = true;
	auto lowerLeft = true;
	auto lowerRight = true;

	auto upperLeftAdjacent = road->GetAdjacent(-1, -1);
	auto upperRightAdjacent = road->GetAdjacent(1, -1);
	auto lowerLeftAdjacent = road->GetAdjacent(-1, 1);
	auto lowerRightAdjacent = road->GetAdjacent(1, 1);

	if (upperLeftAdjacent == nullptr)
	{
		upperLeft = false;
	}
	else
	{
		CIsRoadVisitor visitor1;
		upperLeftAdjacent->Accept(&visitor1);
		if (!visitor1.IsRoad())
		{
			upperLeft = false;
		}
	}

	if (upperRightAdjacent == nullptr)
	{
		upperRight = false;
	}
	else
	{
		CIsRoadVisitor visitor2;
		upperRightAdjacent->Accept(&visitor2);
		if (!visitor2.IsRoad())
		{
			upperRight = false;
		}
	}

	if (lowerLeftAdjacent == nullptr)
	{
		lowerLeft = false;
	}
	else
	{
		CIsRoadVisitor visitor3;
		lowerLeftAdjacent->Accept(&visitor3);
		if (!visitor3.IsRoad())
		{
			lowerLeft = false;
		}
	}
	if (lowerRightAdjacent == nullptr)
	{
		lowerRight = false;
	}
	else
	{
		CIsRoadVisitor visitor4;
		lowerRightAdjacent->Accept(&visitor4);
		if (!visitor4.IsRoad())
		{
			lowerRight = false;
		}
	}

	road->CTileRoad::SetAdjacencies(upperLeft, upperRight, lowerLeft, lowerRight);
}
