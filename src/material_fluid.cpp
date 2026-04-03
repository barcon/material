#include "material_fluid.hpp"

namespace material
{
	MaterialFluidPtr CreateMaterialFluid(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);

		return res;
	}
	MaterialFluidPtr CreateMaterialFluidUnit(Tag materialTag)
	{
		auto res = MaterialFluid::Create();

		res->SetTag(materialTag);
		res->SetDensity(values::CreateValueScalarCoordinates(2, 1.0));
		res->SetSpecificHeat(values::CreateValueScalarCoordinates(2, 1.0));
		res->SetThermalConductivity(values::CreateValueScalarCoordinates(2, 1.0));
		res->SetDynamicViscosity(values::CreateValueScalarCoordinates(2, 1.0));

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

		density_ = values::CreateValueScalarCoordinates(2, 0.0);
		density_->SetName("Density");
		density_->SetKey("rho");

		specificHeat_ = values::CreateValueScalarCoordinates(2, 0.0);
		specificHeat_->SetName("Specific Heat");
		specificHeat_->SetKey("cp");

		thermalConductivity_ = values::CreateValueScalarCoordinates(2, 0.0);
		thermalConductivity_->SetName("Thermal Conductivity");
		thermalConductivity_->SetKey("k");

		dynamicViscosity_ = values::CreateValueScalarCoordinates(2, 0.0);
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
	Scalar MaterialFluid::GetDensity(const Vector& state) const
	{
		return density_->GetValue(state);
	}
	Scalar MaterialFluid::GetSpecificHeat(const Vector& state) const
	{
		return specificHeat_->GetValue(state);
	}
	Scalar MaterialFluid::GetThermalConductivity(const Vector& state) const
	{
		return thermalConductivity_->GetValue(state);
	}
	Scalar MaterialFluid::GetDynamicViscosity(const Vector& state) const
	{
		return dynamicViscosity_->GetValue(state);
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
	void MaterialFluid::SetDensity(IScalarCoordinatesPtr value)
	{
		if(value == nullptr)
		{
			throw std::invalid_argument("Density value cannot be null.");
		}

		if(value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Density value must have 2 coordinates (temperature and pressure).");
		}

		density_ = value;
	}
	void MaterialFluid::SetSpecificHeat(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Specific Heat value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Specific Heat value must have 2 coordinates (temperature and pressure).");
		}

		specificHeat_ = value;
	}
	void MaterialFluid::SetThermalConductivity(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Thermal Conductivity value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Thermal Conductivity value must have 2 coordinates (temperature and pressure).");
		}

		thermalConductivity_ = value;
	}
	void MaterialFluid::SetDynamicViscosity(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Dynamic Viscosity value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Specific Heat value must have 2 coordinates (temperature and pressure).");
		}

		dynamicViscosity_ = value;
	}
	void MaterialFluid::SetProperty(IValuePtr value)
	{
		properties_.insert({ value->GetKey(), value });
	}
	Matrix MaterialFluid::D(const Vector& state) const
	{
		Scalar mu = GetDynamicViscosity(state);

		return mu * Id_;
	}
	Matrix MaterialFluid::K(const Vector& state) const
	{
		Matrix res(3, 3, eilig::matrix_zeros);

		res(0, 0) = GetThermalConductivity(state);
		res(1, 1) = GetThermalConductivity(state);
		res(2, 2) = GetThermalConductivity(state);

		return res;
	}
} // namespace material