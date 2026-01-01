#ifndef MATERIAL_FLUID_MINERAL_OIL_HPP_
#define MATERIAL_FLUID_MINERAL_OIL_HPP_

#include "material_fluid.hpp"

namespace material
{
	MaterialFluidPtr CreateOilVG32(Tag materialTag, Scalar T_ref, Scalar p_ref);
	MaterialFluidPtr CreateOilVG46(Tag materialTag, Scalar T_ref, Scalar p_ref);
	MaterialFluidPtr CreateOilVG68(Tag materialTag, Scalar T_ref, Scalar p_ref);
	MaterialFluidPtr CreateOilVG100(Tag materialTag, Scalar T_ref, Scalar p_ref);

} // namespace material

#endif /* MATERIAL_FLUID_MINERAL_OIL_HPP_*/
