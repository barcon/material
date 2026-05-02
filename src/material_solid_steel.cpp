#include "material_solid_steel.hpp"

namespace material
{
	MaterialSolidPtr CreateSteel(Tag materialTag)
	{
		auto res = MaterialSolid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Solid"));
		res->SetGroup(value::CreateValueString("Steel"));
		res->SetDescription(value::CreateValueString("Structural Steel"));
		res->SetName(value::CreateValueString("Structural Steel"));

		res->SetDensity(value::CreateValueScalarCoordinates(2, 7850.0));
		res->SetPoissonRatio(value::CreateValueScalarCoordinates(2, 0.3));
		res->SetThermalExpansion(value::CreateValueScalarCoordinates(2, 0.000012));
		res->SetElasticModulus(value::CreateValueScalarCoordinates(2, 2.07e+11));
		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, 490.0));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, 51.0));

		return res;
	}
} // namespace material