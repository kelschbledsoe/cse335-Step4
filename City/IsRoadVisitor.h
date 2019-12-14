/**
 * \file IsRoadVisitor.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class for road visitor
 */

#pragma once
#include "TileVisitor.h"


/**
 * Class for a road visitor
 */
class CIsRoadVisitor : public CTileVisitor
{
public:
	virtual void VisitRoad(CTileRoad* road) override;

	/** Function to return the boolean member variable if the tile is a road tile 
	* \return mIsRoad true if it is a road tile */
	bool IsRoad() { return mIsRoad; }

private:
	/// bool to represent whether or not the tile is a road tile
	bool mIsRoad = false;
};

