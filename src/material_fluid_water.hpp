#ifndef MATERIAL_FLUID_WATER_HPP_
#define MATERIAL_FLUID_WATER_HPP_

#include "material_fluid.hpp"

namespace material
{
	MaterialFluidPtr CreateWater(Tag materialTag);
	MaterialFluidPtr CreateWater(Tag materialTag, Scalar T_ref, Scalar p_ref);

} // namespace material

#endif /* MATERIAL_FLUID_WATER_HPP_*/
