#include "material_base.hpp"

namespace material
{
    Vector CreateState(Scalar temperature, Scalar pressure)
    {
		Vector state(2);

		state(0) = temperature;
		state(1) = pressure;

        return state;
    }
}