/**
* \file PointHistory.cpp
*
* \author Gabriella Kelsch Bledsoe
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);


protected:
    /**
    * Nested class that stores up to five points in a bin.
    */
    class PointBin
    {
    public:
        PointBin(int max);
        virtual ~PointBin();

        /// Get the current count of items in this bin
        /// \return Count (zero to MaxPoints)
        int GetCnt() { return mCnt; }

        /// Get the maximum points we allow in this bin
        /// \return Maximum integer value
        int GetMax() { return mMax; }

        bool Add(Gdiplus::Point point);

        /// Get a stored point
        /// \param i Index to the point (0 to mCnt-1)
        /// \return Stored point value
        Gdiplus::Point Get(int i) { return mPoints[i]; }

        /// Get the next bin in the list
        /// \return Pointer to next bin or null if none
        std::shared_ptr<PointBin> GetNext() { return mNext; }

        /// Set the next bin in the list
        /// \param next Next pointer to set
        void SetNext(std::shared_ptr<PointBin> next) { mNext = next; }

    private:
        PointBin() = delete;

        /// Array to store the points
        Gdiplus::Point *mPoints;

        /// Maximum number of elements we can store in the array
        int mMax;

        /// Number of elements currently stored in array
        int mCnt = 0;

        /// Next bin
        std::shared_ptr<PointBin> mNext;
    };


    /// Pointer to the head of the linked list of bins
    std::shared_ptr<PointBin> mHead;

private:
    int MakeSize();

    /// Random number generator
    std::mt19937 mGen;

    /// Pointer to the tail of the linked list of bins (last node)
    std::shared_ptr<PointBin> mTail;

public:
	/**
	 * Class for an iterator that iterates over a history of mouse movement 
	*/
	class Iter
	{
	public:
		/** Constructor
		* \param history The CPointHistory object we are iterating over 
		* \param pos The position in the collection
		* \param binPos The position in the bin */
		Iter(CPointHistory* history, std::shared_ptr<PointBin> pos, int binPos) : 
			mHistory(history), mPos(pos), mBinPos(binPos) {};

		/** Get value at current position
		* \returns value at mPos in the collection */
		Gdiplus::Point operator *() const { return mPos->Get(mBinPos); }
		
		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++();

		/** Test for end of iterator
		* \param other The object on the right of the != operator
		* \returns True if positions are not equal */
		bool operator!=(const Iter& other) const
		{
			return mPos != other.mPos;
		}

	private:
		CPointHistory* mHistory; ///< City iterating over
		std::shared_ptr<PointBin> mPos; ///< Position in the collection
		int mBinPos; ///< Position in the bin
	};

	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */
	Iter begin(){return Iter(this, mHead, 0);}

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this, nullptr, 0); }
};

