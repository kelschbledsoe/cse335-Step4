/**
 * \file BuildingCounter.h
 *
 * \author Charles Owen
 *
 * Visitor that counts buildings
 */

#pragma once
#include "TileVisitor.h"


/**
 * Keeps count of number of buildings in the city
 */
class CBuildingCounter : public CTileVisitor
{
public:
	CBuildingCounter();
	virtual ~CBuildingCounter();

	/** Get the number of buildings
	 * \returns Number of buildings */
	int GetNumBuildings() const { return mNumBuildings; }

	void VisitBuilding(CTileBuilding* building);

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

