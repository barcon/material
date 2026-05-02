
#include "material_solid.hpp"

namespace material
{
	MaterialSolidPtr CreateSolid(Tag materialTag)
	{
		auto res = MaterialSolid::Create();

		res->SetTag(materialTag);

		return res;
	}
	MaterialSolidPtr CreateSolidUnit(Tag materialTag)
	{
		auto res = MaterialSolid::Create();

		res->SetTag(materialTag);
		res->SetDensity(value::CreateValueScalarCoordinates(2, 1.0));
		res->SetSpecificHeat(value::CreateValueScalarCoordinates(2, 1.0));
		res->SetPoissonRatio(value::CreateValueScalarCoordinates(2, 1.0));
		res->SetElasticModulus(value::CreateValueScalarCoordinates(2, 1.0));
		res->SetThermalExpansion(value::CreateValueScalarCoordinates(2, 1.0));
		res->SetThermalConductivity(value::CreateValueScalarCoordinates(2, 1.0));

		return res;
	}
	MaterialSolid::MaterialSolid()
	{
		class_ = value::CreateValueString("");
		class_->SetName("Class");
		class_->SetKey("class");

		group_ = value::CreateValueString("");
		group_->SetName("Group");
		group_->SetKey("group");

		description_ = value::CreateValueString("");
		description_->SetName("Description");
		description_->SetKey("description");

		name_ = value::CreateValueString("");
		name_->SetName("Name");
		name_->SetKey("name");
		
		density_ = value::CreateValueScalarCoordinates(2, 0.0);
		density_->SetName("Density");
		density_->SetKey("rho");

		specificHeat_ = value::CreateValueScalarCoordinates(2, 0.0);
		specificHeat_->SetName("Specific Heat");
		specificHeat_->SetKey("cp");

		thermalConductivity_ = value::CreateValueScalarCoordinates(2, 0.0);
		thermalConductivity_->SetName("Thermal Conductivity");
		thermalConductivity_->SetKey("k");
		
		poissonRatio_ = value::CreateValueScalarCoordinates(2, 0.0);
		poissonRatio_->SetName("Poisson's Ratio");
		poissonRatio_->SetKey("nu");

		thermalExpansion_ = value::CreateValueScalarCoordinates(2, 0.0);
		thermalExpansion_->SetName("Coefficient Thermal Expansion");
		thermalExpansion_->SetKey("alpha");

		elasticModulus_ = value::CreateValueScalarCoordinates(2, 0.0);
		elasticModulus_->SetName("Young's Modulus");
		elasticModulus_->SetKey("E");
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
	Scalar MaterialSolid::GetDensity(const Vector& state) const
	{
		return density_->GetValue(state);
	}
	Scalar MaterialSolid::GetPoissonRatio(const Vector& state) const
	{
		return poissonRatio_->GetValue(state);
	}
	Scalar MaterialSolid::GetSpecificHeat(const Vector& state) const
	{
		return specificHeat_->GetValue(state);
	}
	Scalar MaterialSolid::GetThermalConductivity(const Vector& state) const
	{
		return thermalConductivity_->GetValue(state);
	}
	Scalar MaterialSolid::GetThermalExpansion(const Vector& state) const
	{
		return thermalExpansion_->GetValue(state);
	}
	Scalar MaterialSolid::GetElasticModulus(const Vector& state) const
	{
		return elasticModulus_->GetValue(state);
	}
	IValuePtr MaterialSolid::GetProperty(String key) const
	{
		auto property = properties_.find(key);

		if (property == properties_.end())
		{
			return nullptr;
		}

		return property->second;
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
	void MaterialSolid::SetDensity(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Density value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Density value must have 2 coordinates (temperature and pressure).");
		}

		density_ = value;
	}
	void MaterialSolid::SetSpecificHeat(IScalarCoordinatesPtr value)
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
	void MaterialSolid::SetThermalConductivity(IScalarCoordinatesPtr value)
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
	void MaterialSolid::SetPoissonRatio(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Poisson Ratio value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Poisson Ratio value must have 2 coordinates (temperature and pressure).");
		}

		poissonRatio_ = value;
	}
	void MaterialSolid::SetThermalExpansion(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Thermal Expansion value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Thermal Expansion value must have 2 coordinates (temperature and pressure).");
		}

		thermalExpansion_ = value;
	}
	void MaterialSolid::SetElasticModulus(IScalarCoordinatesPtr value)
	{
		if (value == nullptr)
		{
			throw std::invalid_argument("Elastic Modulus value cannot be null.");
		}

		if (value->GetNumberCoordinates() != 2)
		{
			throw std::invalid_argument("Elastic Modulus value must have 2 coordinates (temperature and pressure).");
		}

		elasticModulus_ = value;
	}
	void MaterialSolid::SetProperty(IValuePtr value)
	{
		properties_.insert({ value->GetKey(), value });
	}
	Matrix MaterialSolid::A(const Vector& state) const
	{
		Matrix res(6, 1, eilig::matrix_zeros);

		res(0, 0) = GetThermalExpansion(state);
		res(1, 0) = res(0, 0);
		res(2, 0) = res(0, 0);

		return res;
	}
	Matrix MaterialSolid::D(const Vector& state) const
	{
		Scalar d;
		Scalar nu = GetPoissonRatio(state);
		Scalar E = GetElasticModulus(state);
		Matrix res(6, 6, eilig::matrix_zeros);

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
	Matrix MaterialSolid::K(const Vector& state) const
	{
		Matrix res(3, 3, eilig::matrix_zeros);

		res(0, 0) = GetThermalConductivity(state);
		res(1, 1) = res(0, 0);
		res(2, 2) = res(0, 0);

		return res;
	}

} // namespace material