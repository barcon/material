#include "material_fluid_mineral_oil.hpp"

namespace material
{
	Scalar DensityOil(Scalar temperature, Scalar pressure)
	{
		Scalar rho_oil = 900.0;
		Scalar T_oil = 288.15;

		return rho_oil * (1.0 - 0.00065 * (temperature - T_oil));
	}
	Scalar SpecificHeatOil(Scalar temperature, Scalar pressure)
	{
		Scalar T_ref = 273.15;
		Scalar rho_oil = DensityOil(T_ref + 15.0, pressure);

		if (DensityOil(temperature, pressure) > 896.0)
			return 3856.0 - 2.345 * rho_oil + 4.605 * (temperature - T_ref);
		else
			return 2910.0 - 1.29 * rho_oil + 4.605 * (temperature - T_ref);
	}
	Scalar ThermalConductivityOil(Scalar temperature, Scalar pressure)
	{
		return 0.129;
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
	Scalar DynamicViscosityOilVG100(Scalar temperature, Scalar pressure)
	{
		Scalar T_ref = 273.15;
		Scalar nx = 1.8e-4;
		Scalar rho = DensityOil(temperature, pressure);
		Scalar ISO = 100.0;

		return nx * std::pow((rho * ISO / (nx * 1.0e+6)), (159.56 / ((temperature - T_ref) + 95.0)) - 0.181913);
	}

	MaterialFluidPtr CreateOilVG32(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 32"));
		res->SetName(value::CreateValueString("Oil ISO VG 32"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinatesFunction(& SpecificHeatOil));
		res->SetDensity(value::CreateValueScalarCoordinatesFunction(&DensityOil));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG32));
		res->SetThermalConductivity(value::CreateValueScalarCoordinatesFunction(&ThermalConductivityOil));

		return res;
	}
	MaterialFluidPtr CreateOilVG32(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 32"));
		res->SetName(value::CreateValueString("Oil ISO VG 32"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(value::CreateValueScalarCoordinates(2, DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG32));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}

	MaterialFluidPtr CreateOilVG46(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 46"));
		res->SetName(value::CreateValueString("Oil ISO VG 46"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinatesFunction(&SpecificHeatOil));
		res->SetDensity(value::CreateValueScalarCoordinatesFunction(&DensityOil));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG46));
		res->SetThermalConductivity(value::CreateValueScalarCoordinatesFunction(&ThermalConductivityOil));

		return res;
	}
	MaterialFluidPtr CreateOilVG46(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 46"));
		res->SetName(value::CreateValueString("Oil ISO VG 46"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(value::CreateValueScalarCoordinates(2, DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG46));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}

	MaterialFluidPtr CreateOilVG68(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 68"));
		res->SetName(value::CreateValueString("Oil ISO VG 68"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinatesFunction(&SpecificHeatOil));
		res->SetDensity(value::CreateValueScalarCoordinatesFunction(&DensityOil));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG68));
		res->SetThermalConductivity(value::CreateValueScalarCoordinatesFunction(&ThermalConductivityOil));

		return res;
	}
	MaterialFluidPtr CreateOilVG68(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 68"));
		res->SetName(value::CreateValueString("Oil ISO VG 68"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(value::CreateValueScalarCoordinates(2, DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG68));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}

	MaterialFluidPtr CreateOilVG100(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 100"));
		res->SetName(value::CreateValueString("Oil ISO VG 100"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinatesFunction(&SpecificHeatOil));
		res->SetDensity(value::CreateValueScalarCoordinatesFunction(&DensityOil));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG100));
		res->SetThermalConductivity(value::CreateValueScalarCoordinatesFunction(&ThermalConductivityOil));

		return res;
	}
	MaterialFluidPtr CreateOilVG100(Tag materialTag, Scalar T_ref, Scalar p_ref)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetClass(value::CreateValueString("Fluid"));
		res->SetGroup(value::CreateValueString("Mineral Hydraulic Oil"));
		res->SetDescription(value::CreateValueString("Oil ISO VG 100"));
		res->SetName(value::CreateValueString("Oil ISO VG 100"));

		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, SpecificHeatOil(T_ref, p_ref)));
		res->SetDensity(value::CreateValueScalarCoordinates(2, DensityOil(T_ref, p_ref)));
		res->SetDynamicViscosity(value::CreateValueScalarCoordinatesFunction(&DynamicViscosityOilVG100));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, ThermalConductivityOil(T_ref, p_ref)));

		return res;
	}
} // namespace material