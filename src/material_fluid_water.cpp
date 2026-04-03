#include "material_fluid_water.hpp"

#include <cmath>

namespace material
{
	Scalar DensityWater(Scalar temperature, Scalar pressure)
	{
		Scalar T_water = (temperature - 273.15);
		Scalar T_water2 = T_water * T_water;
		Scalar T_water3 = T_water2 * T_water;
		Scalar T_water4 = T_water3 * T_water;
		Scalar T_water5 = T_water4 * T_water;

		return (999.83952 + 16.945176 * T_water - 7.9870401E-3 * T_water2 - 46.170461E-6 * T_water3 + 105.56302E-9 * T_water4 - 280.54253E-12 * T_water5) / (1.0 + 16.897850E-3 * T_water);
	}
	Scalar SpecificHeatWater(Scalar temperature, Scalar pressure)
	{
		Scalar T_water = (temperature - 273.15);

		return 4185.5 * (0.996185 + 0.0002874 * std::pow((T_water + 100.0) / 100.0, 5.26) + 0.011160 * std::pow(10.0, -0.036 * T_water));
	}
	Scalar ThermalConductivityWater(Scalar temperature, Scalar pressure)
	{
		Scalar T_relative = temperature / 298.15;
		Scalar T_relative2 = T_relative * T_relative;

		return 0.6065 * (-1.48445 + 4.12292 * T_relative - 1.63866 * T_relative2);
	}	
	Scalar DynamicViscosityWater(Scalar temperature, Scalar pressure)
	{
		Scalar T_water = (temperature - 273.15);

		Scalar mu = 1002.01 / 1.0E+6;
		Scalar log = (20.0 - T_water) / (T_water + 96.0) * (1.2378 - 1.303 * 1.0E-3 * (20.0 - T_water) + 3.06 * 1.0E-6 * std::pow(20.0 - T_water, 2.0) + 2.55 * 1.0E-8 * std::pow(20.0 - T_water, 3.0));

		return mu * std::pow(10.0, log);
	}

	MaterialFluidPtr CreateWater(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(values::CreateValueString("Fluid"));
		res->SetGroup(values::CreateValueString("Water"));
		res->SetDescription(values::CreateValueString("Liquid Water (Air-Free)"));
		res->SetName(values::CreateValueString("Liquid Water"));

		res->SetSpecificHeat(values::CreateValueScalarCoordinatesFunction(SpecificHeatWater));
		res->SetDensity(values::CreateValueScalarCoordinatesFunction(DensityWater));
		res->SetDynamicViscosity(values::CreateValueScalarCoordinatesFunction(&DynamicViscosityWater));
		res->SetThermalConductivity(values::CreateValueScalarCoordinatesFunction(ThermalConductivityWater));

		return res;
	}
	MaterialFluidPtr CreateWater(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(values::CreateValueString("Fluid"));
		res->SetGroup(values::CreateValueString("Water"));
		res->SetDescription(values::CreateValueString("Liquid Water (Air-Free)"));
		res->SetName(values::CreateValueString("Liquid Water"));

		res->SetSpecificHeat(values::CreateValueScalarCoordinates(2, SpecificHeatWater(T_ref, p_ref)));
		res->SetDensity(values::CreateValueScalarCoordinates(2, DensityWater(T_ref, p_ref)));
		res->SetDynamicViscosity(values::CreateValueScalarCoordinatesFunction(&DynamicViscosityWater));
		res->SetThermalConductivity(values::CreateValueScalarCoordinates(2, ThermalConductivityWater(T_ref, p_ref)));

		return res;
	}
} // namespace material