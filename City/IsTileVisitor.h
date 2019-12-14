/**
 * \file IsTileVisitor.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class for tile visitor
 */

#pragma once
#include "TileVisitor.h"

/**
 * Class for a tile visitor
 */
class CIsTileVisitor : public CTileVisitor
{
public:
	virtual void VisitRoad(CTileRoad* road) override;
};

