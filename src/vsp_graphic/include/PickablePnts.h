#ifndef _VSP_GRAPHIC_POINTCLOUD_CONTROLPOINTS_H
#define _VSP_GRAPHIC_POINTCLOUD_CONTROLPOINTS_H

#include "Pickable.h"
#include "glm/glm.hpp"

#include <vector>

namespace VSPGraphic
{
class Renderable;

/*!
* Pickable Points.  Derived from Pickable.  This class
* makes all vertices on geometry pickable.
*/
class PickablePnts : public Pickable
{
public:
    /*!
    * Constructor.
    * source - Render source.
    */
	PickablePnts(Renderable * source);
    /*!
    * Destructor.
    */
	virtual ~PickablePnts();

public:
    /*!
    * Process picked id.  If id is picked, return true.
    */
	virtual bool processPickingResult(unsigned int pickedId);

public:
	/*!
	* Get highlighted buffer index.  If nothing is highlighted, return 0xffffffff.
	*/
	unsigned int getIndex();

public:
    /*!
    * Overrides Pickable.  Update unique color ids.
    */
	virtual void update();

public:
    /*!
    * Adjust the range of picking.
    */
	void setPickRange(float range);
    /*!
    * Adjust the size of point.
    */
    void setPointSize(float size);

protected:
    /*!
    * Overrides Pickable. Render preprocessing.
    */
	virtual void _predraw();
    /*!
    * Overrides Pickable. Draw highlighted point.
    */
	virtual void _draw();

private:
	float _pickRange;
	unsigned int _highlightedId;
    float _pointSize;
};
}
#endif