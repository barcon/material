#include "material_fluid.hpp"

namespace material
{
	Scalar DensityOil(Scalar temperature, Scalar pressure)
	{
		Scalar rho_oil = 872.0;
		Scalar T_oil = 288.15;

		return rho_oil * (1.0 - 0.00065 * (temperature - T_oil));
	}
	Scalar SpecificHeatOil(Scalar temperature, Scalar pressure)
	{
		Scalar rho_oil = 872.0;
		Scalar T_ref = 273.15;

		if (DensityOil(temperature, pressure) > 896.0)
			return 3856.0 - 2.345 * rho_oil + 4.605 * (temperature - T_ref);
		else
			return 2910.0 - 1.29 * rho_oil + 4.605 * (temperature - T_ref);
	}
	Scalar DynamicViscosityOilVG32(Scalar temperature, Scalar pressure)
	{
		Scalar T_ref = 273.15;
		Scalar nx = 1.8e-4;
		Scalar rho = DensityOil(temperature, pressure);
		Scalar ISO = 32.0;

		return nx * std::pow((rho * ISO / (nx * 1.0e+6)), (159.56 / ((temperature - T_ref) + 95.0)) - 0.181913 );
	}
	Scalar DynamicViscosityOilVG46(Scalar temperature, Scalar pressure)
	{
		Scalar T_ref = 273.15;
		Scalar nx = 1.8e-4;
		Scalar rho = DensityOil(temperature, pressure);
		Scalar ISO = 46.0;

		return nx * std::pow((rho * ISO / (nx * 1.0e+6)), (159.56 / ((temperature - T_ref) + 95.0)) - 0.181913);
	}
	Scalar DynamicViscosityOilVG68(Scalar temperature, Scalar pressure)
	{
		Scalar T_ref = 273.15;
		Scalar nx = 1.8e-4;
		Scalar rho = DensityOil(temperature, pressure);
		Scalar ISO = 68.0;

		return nx * std::pow((rho * ISO / (nx * 1.0e+6)), (159.56 / ((temperature - T_ref) + 95.0)) - 0.181913);
	}
	Scalar ThermalConductivityOil(Scalar temperature, Scalar pressure)
	{
		return 0.129;
	}

	MaterialFluidPtr CreateOilVG32(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(values::CreateValueString("Fluid"));
		res->SetGroup(values::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(values::CreateValueString("Oil ISO VG 32"));
		res->SetName(values::CreateValueString("Oil ISO VG 32"));

		res->SetSpecificHeat(values::CreateValueScalar2D(SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(values::CreateValueScalar2D(DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(values::CreateValueScalar2DFunction(&DynamicViscosityOilVG32));
		res->SetThermalConductivity(values::CreateValueScalar2D(ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}
	MaterialFluidPtr CreateOilVG46(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(values::CreateValueString("Fluid"));
		res->SetGroup(values::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(values::CreateValueString("Oil ISO VG 46"));
		res->SetName(values::CreateValueString("Oil ISO VG 46"));

		res->SetSpecificHeat(values::CreateValueScalar2D(SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(values::CreateValueScalar2D(DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(values::CreateValueScalar2DFunction(&DynamicViscosityOilVG46));
		res->SetThermalConductivity(values::CreateValueScalar2D(ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}
	MaterialFluidPtr CreateOilVG68(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(values::CreateValueString("Fluid"));
		res->SetGroup(values::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(values::CreateValueString("Oil ISO VG 68"));
		res->SetName(values::CreateValueString("Oil ISO VG 68"));

		res->SetSpecificHeat(values::CreateValueScalar2D(SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(values::CreateValueScalar2D(DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(values::CreateValueScalar2DFunction(&DynamicViscosityOilVG68));
		res->SetThermalConductivity(values::CreateValueScalar2D(ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}
} // namespace material