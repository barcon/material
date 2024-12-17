#ifndef MATERIAL_LOAD_HPP_
#define MATERIAL_LOAD_HPP_

#include "material_types.hpp"
#include "material_solid.hpp"
#include "material_fluid.hpp"

namespace material
{
	MaterialSolidPtr LoadMaterialSolidXML(Tag tag, String fileName, Status& status);
	MaterialFluidPtr LoadMaterialFluidXML(Tag tag, String fileName, Status& status);
} // namespace material

#endif /* MATERIAL_LOAD_HPP_*/