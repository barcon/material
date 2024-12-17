
#include "material_solid.hpp"

namespace material
{
	MaterialSolidPtr CreateMaterialSolid(Tag materialTag)
	{
		auto res = MaterialSolid::Create();

		res->SetTag(materialTag);

		return res;
	}
	MaterialSolid::MaterialSolid()
	{
		class_ = std::dynamic_pointer_cast<values::IString>(values::CreateValueString("", "Class", "class"));
		group_ = std::dynamic_pointer_cast<values::IString>(values::CreateValueString("", "Group", "group"));
		description_ = std::dynamic_pointer_cast<values::IString>(values::CreateValueString("", "Description", "description"));
		name_ = std::dynamic_pointer_cast<values::IString>(values::CreateValueString("", "Name", "name"));
		
		density_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Density", "rho"));
		poissonRatio_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Poisson's Ratio", "nu"));
		specificHeat_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Specific Heat", "cp"));
		thermalConductivity_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Thermal Conductivity", "k"));
		thermalExpansion_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Coefficient Thermal Expansion", "alpha"));
		elasticModulus_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Young's Modulus", "E"));
		tensileStrength_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Tensile Strength", "Rm"));
		yieldStrength_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Yield Strength", "Re"));
		shearStrength_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Shear Strength", "tau_B"));
		limitingSurfacePressure_ = std::dynamic_pointer_cast<values::IScalar2D>(values::CreateValueScalar2D(0.0, "Limiting Surface Pressure", "p_G"));
	}
	MaterialSolidPtr MaterialSolid::Create()
	{
		class MakeSharedEnabler : public MaterialSolid
		{
		};

		auto res = std::make_shared<MakeSharedEnabler>();

		return res;
	}
	MaterialSolidPtr MaterialSolid::GetPtr()
	{
		return std::dynamic_pointer_cast<MaterialSolid>(MaterialSolid::shared_from_this());
	}
	ConstMaterialSolidPtr MaterialSolid::GetPtr() const
	{
		return const_cast<MaterialSolid*>(this)->GetPtr();
	}
	Tag MaterialSolid::GetTag() const
	{
		return tag_;
	}
	Type MaterialSolid::GetType() const
	{
		return type_;
	}
	String MaterialSolid::GetClass() const
	{
		return class_->GetValue();
	}
	String MaterialSolid::GetGroup() const
	{
		return group_->GetValue();
	}
	String MaterialSolid::GetDescription() const
	{
		return description_->GetValue();
	}
	String MaterialSolid::GetName() const
	{
		return name_->GetValue();
	}
	void MaterialSolid::SetTag(const Tag& tag)
	{
		tag_ = tag;
	}
	void MaterialSolid::SetClass(IStringPtr value)
	{
		class_ = value;
	}
	void MaterialSolid::SetGroup(IStringPtr value)
	{
		group_ = value;
	}
	void MaterialSolid::SetDescription(IStringPtr value)
	{
		description_ = value;
	}
	void MaterialSolid::SetName(IStringPtr value)
	{
		name_ = value;
	}
	Scalar MaterialSolid::GetDensity(Scalar temperature, Scalar pressure) const
	{
		return density_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetPoissonRatio(Scalar temperature, Scalar pressure) const
	{
		return poissonRatio_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetSpecificHeat(Scalar temperature, Scalar pressure) const
	{
		return specificHeat_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetThermalConductivity(Scalar temperature, Scalar pressure) const
	{
		return thermalConductivity_->GetValue(temperature, pressure);
	}
	void MaterialSolid::SetDensity(IScalar2DPtr value)
	{
		density_ = value;
	}
	void MaterialSolid::SetSpecificHeat(IScalar2DPtr value)
	{
		specificHeat_ = value;
	}
	void MaterialSolid::SetThermalConductivity(IScalar2DPtr value)
	{
		thermalConductivity_ = value;
	}
	Scalar MaterialSolid::GetThermalExpansion(Scalar temperature, Scalar pressure) const
	{
		return thermalExpansion_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetElasticModulus(Scalar temperature, Scalar pressure) const
	{
		return elasticModulus_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetTensileStrength(Scalar temperature, Scalar pressure) const
	{
		return tensileStrength_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetYieldStrength(Scalar temperature, Scalar pressure) const
	{
		return yieldStrength_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetShearStrength(Scalar temperature, Scalar pressure) const
	{
		return shearStrength_->GetValue(temperature, pressure);
	}
	Scalar MaterialSolid::GetLimitingSurfacePressure(Scalar temperature, Scalar pressure) const
	{
		return limitingSurfacePressure_->GetValue(temperature, pressure);
	}
	void MaterialSolid::SetPoissonRatio(IScalar2DPtr value)
	{
		poissonRatio_ = value;
	}
	void MaterialSolid::SetThermalExpansion(IScalar2DPtr value)
	{
		thermalExpansion_ = value;
	}
	void MaterialSolid::SetElasticModulus(IScalar2DPtr value)
	{
		elasticModulus_ = value;
	}
	void MaterialSolid::SetTensileStrength(IScalar2DPtr value)
	{
		tensileStrength_ = value;
	}
	void MaterialSolid::SetYieldStrength(IScalar2DPtr value)
	{
		yieldStrength_ = value;
	}
	void MaterialSolid::SetShearStrength(IScalar2DPtr value)
	{
		shearStrength_ = value;
	}
	void MaterialSolid::SetLimitingSurfacePressure(IScalar2DPtr value)
	{
		limitingSurfacePressure_ = value;
	}
	Matrix MaterialSolid::A(Scalar temperature, Scalar pressure) const
	{
		Matrix res(6, 1, 0.0);

		res(0, 0) = GetThermalExpansion(temperature, pressure);
		res(1, 0) = res(0, 0);
		res(2, 0) = res(0, 0);

		return res;
	}
	Matrix MaterialSolid::D(Scalar temperature, Scalar pressure) const
	{
		Scalar d;
		Scalar nu = GetPoissonRatio(temperature, pressure);
		Scalar E = GetElasticModulus(temperature, pressure);
		Matrix res(6, 6, 0.0);

		d = (1.0 + nu) * (1.0 - 2.0 * nu);

		res(0, 0) = 1.0 - nu;
		res(1, 1) = res(0, 0);
		res(2, 2) = res(0, 0);
		res(3, 3) = (1.0 - 2.0 * nu) / 2.0;
		res(4, 4) = res(3, 3);
		res(5, 5) = res(3, 3);

		res(0, 1) = nu;
		res(0, 2) = nu;
		res(1, 2) = nu;

		res(1, 0) = nu;
		res(2, 0) = nu;
		res(2, 1) = nu;

		return (E / d) * res;
	}
	Matrix MaterialSolid::K(Scalar temperature, Scalar pressure) const
	{
		Matrix res(3, 3, 0.0);

		res(0, 0) = GetThermalConductivity(temperature, pressure);
		res(1, 1) = res(0, 0);
		res(2, 2) = res(0, 0);

		return res;
	}

} // namespace material