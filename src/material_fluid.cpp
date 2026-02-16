#include "material_fluid.hpp"

namespace material
{
	MaterialFluidPtr CreateMaterialFluid(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);

		return res;
	}
	MaterialFluid::MaterialFluid()
	{
		class_ = values::CreateValueString("");
		class_->SetName("Class");
		class_->SetKey("class");

		group_ = values::CreateValueString("");
		group_->SetName("Group");
		group_->SetKey("group");

		description_ = values::CreateValueString("");
		description_->SetName("Description");
		description_->SetKey("description");

		name_ = values::CreateValueString("");
		name_->SetName("Name");
		name_->SetKey("name");

		density_ = values::CreateValueScalar2D(0.0);
		density_->SetName("Density");
		density_->SetKey("rho");

		specificHeat_ = values::CreateValueScalar2D(0.0);
		specificHeat_->SetName("Specific Heat");
		specificHeat_->SetKey("cp");

		thermalConductivity_ = values::CreateValueScalar2D(0.0);
		thermalConductivity_->SetName("Thermal Conductivity");
		thermalConductivity_->SetKey("k");

		dynamicViscosity_ = values::CreateValueScalar2D(0.0);
		dynamicViscosity_->SetName("Dynamic Viscosity");
		dynamicViscosity_->SetKey("mu");

		m_ = Matrix(6, 1, eilig::matrix_zeros);
		m_(0, 0) = 1.0;
		m_(1, 0) = 1.0;
		m_(2, 0) = 1.0;

		I0_ = Matrix(6, 6, eilig::matrix_zeros);
		I0_(0, 0) = 2.0;
		I0_(1, 1) = 2.0;
		I0_(2, 2) = 2.0;
		I0_(3, 3) = 1.0;
		I0_(4, 4) = 1.0;
		I0_(5, 5) = 1.0;

		Id_ = (I0_ - 2.0 / 3.0 * m_ * m_.Transpose());
	}
	MaterialFluidPtr MaterialFluid::Create()
	{
		class MakeSharedEnabler : public MaterialFluid
		{
		};

		auto res = std::make_shared<MakeSharedEnabler>();

		return res;
	}
	MaterialFluidPtr MaterialFluid::GetPtr()
	{
		return std::dynamic_pointer_cast<MaterialFluid>(shared_from_this());
	}
	ConstMaterialFluidPtr MaterialFluid::GetPtr() const
	{
		return const_cast<MaterialFluid*>(this)->GetPtr();
	}
	Tag MaterialFluid::GetTag() const
	{
		return tag_;
	}
	Type MaterialFluid::GetType() const
	{
		return type_;
	}
	String MaterialFluid::GetClass() const
	{
		return class_->GetValue();
	}
	String MaterialFluid::GetGroup() const
	{
		return group_->GetValue();
	}
	String MaterialFluid::GetDescription() const
	{
		return description_->GetValue();
	}
	String MaterialFluid::GetName() const
	{
		return name_->GetValue();
	}
	Scalar MaterialFluid::GetDensity(Scalar temperature, Scalar pressure) const
	{
		return density_->GetValue(temperature, pressure);
	}
	Scalar MaterialFluid::GetSpecificHeat(Scalar temperature, Scalar pressure) const
	{
		return specificHeat_->GetValue(temperature, pressure);
	}
	Scalar MaterialFluid::GetThermalConductivity(Scalar temperature, Scalar pressure) const
	{
		return thermalConductivity_->GetValue(temperature, pressure);
	}
	Scalar MaterialFluid::GetDynamicViscosity(Scalar temperature, Scalar pressure) const
	{
		return dynamicViscosity_->GetValue(temperature, pressure);
	}
	IValuePtr MaterialFluid::GetProperty(String key) const
	{
		auto property = properties_.find(key);

		if (property == properties_.end())
		{
			return nullptr;
		}

		return property->second;
	}
	void MaterialFluid::SetTag(const Tag& tag)
	{
		tag_ = tag;
	}
	void MaterialFluid::SetClass(IStringPtr value)
	{
		class_ = value;
	}
	void MaterialFluid::SetGroup(IStringPtr value)
	{
		group_ = value;
	}
	void MaterialFluid::SetDescription(IStringPtr value)
	{
		description_ = value;
	}
	void MaterialFluid::SetName(IStringPtr value)
	{
		name_ = value;
	}
	void MaterialFluid::SetDensity(IScalar2DPtr value)
	{
		density_ = value;
	}
	void MaterialFluid::SetSpecificHeat(IScalar2DPtr value)
	{
		specificHeat_ = value;
	}
	void MaterialFluid::SetThermalConductivity(IScalar2DPtr value)
	{
		thermalConductivity_ = value;
	}
	void MaterialFluid::SetDynamicViscosity(IScalar2DPtr value)
	{
		dynamicViscosity_ = value;
	}
	void MaterialFluid::SetProperty(IValuePtr value)
	{
		properties_.insert({ value->GetKey(), value });
	}
	Matrix MaterialFluid::D(Scalar temperature, Scalar pressure) const
	{
		Scalar mu = GetDynamicViscosity(temperature, pressure);

		return mu * Id_;
	}
	Matrix MaterialFluid::K(Scalar temperature, Scalar pressure) const
	{
		Matrix res(3, 3, eilig::matrix_zeros);

		res(0, 0) = GetThermalConductivity(temperature, pressure);
		res(1, 1) = GetThermalConductivity(temperature, pressure);
		res(2, 2) = GetThermalConductivity(temperature, pressure);

		return res;
	}
} // namespace material