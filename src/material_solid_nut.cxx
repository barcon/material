#include "material_solid_nut.hpp"

namespace material
{
	MaterialNutPtr CreateMaterialNut(Tag materialTag, String grade, Scalar diameter)
	{
		auto res = MaterialNut::Create();

		res->SetTag(materialTag);
		res->SetGrade(grade);
		res->SetDiameter(diameter);

		return res;
	}
	MaterialNut::MaterialNut()
	{
		grade_ = CreatePropertyString("Grade", "grade", "8");
		diameter_ = CreatePropertyScalar("Diameter", "diameter", 0.0);

		UpdateProperties();
	}
	MaterialNutPtr MaterialNut::Create()
	{
		class MakeSharedEnabler : public MaterialNut
		{
		};

		auto res = std::make_shared<MakeSharedEnabler>();

		return res;
	}
	MaterialNutPtr MaterialNut::GetPtr()
	{
		return std::dynamic_pointer_cast<MaterialNut>(MaterialNut::shared_from_this());
	}
	ConstMaterialNutPtr MaterialNut::GetPtr() const
	{
		return const_cast<MaterialNut*>(this)->GetPtr();
	}
	void MaterialNut::SetGrade(String grade)
	{
		if (!(grade == "8" || grade == "10" || grade == "12") )
		{
			throw std::invalid_argument("Invalid nut grade");
		}

		grade_->SetValue(grade);
		UpdateProperties();
	}
	void MaterialNut::SetDiameter(Scalar diameter)
	{
		if (diameter < 0.0)
		{
			throw std::invalid_argument( "Invalid nut diameter");
		}

		diameter_->SetValue(diameter);
		UpdateProperties();
	}
	void MaterialNut::UpdateProperties()
	{
		if ( grade_ && diameter_ )
		{
			auto grade = grade_->GetValue();
			auto diameter = diameter_->GetValue(T_ref, p_ref);

			if(grade == "8")
			{
				class_->SetValue(String("MaterialNut"));
				group_->SetValue(String("Carbon steel"));
				description_->SetValue(String("ISO 898-2"));
				name_->SetValue(String("Grade 8"));

				density_->SetValue(7850.0);
				poissonRatio_->SetValue(0.30);
				specificHeat_->SetValue(470.0);
				thermalConductivity_->SetValue(42.5);
				thermalExpansion_->SetValue(1.11E-05);
				elasticModulus_->SetValue(2.05e+11);
				yieldStrength_->SetValue(6.40E+08);
				tensileStrength_->SetValue(8.00E+08);
				shearStrength_->SetValue(0.65 * tensileStrength_->GetValue(T_ref, p_ref));

			}
			else if (grade == "10")
			{
				class_->SetValue(String("MaterialNut"));
				group_->SetValue(String("Carbon steel"));
				description_->SetValue(String("ISO 898-2"));
				name_->SetValue(String("Grade 10"));;

				density_->SetValue(7850.0);
				poissonRatio_->SetValue(0.30);
				specificHeat_->SetValue(470.0);
				thermalConductivity_->SetValue(42.5);
				thermalExpansion_->SetValue(1.11E-05);
				elasticModulus_->SetValue(2.05e+11);
				yieldStrength_->SetValue(9.40E+08);
				tensileStrength_->SetValue(1.04E+09);
				shearStrength_->SetValue(0.62 * tensileStrength_->GetValue(T_ref, p_ref));
			}
			else if (grade == "12")
			{
				class_->SetValue(String("MaterialNut"));
				group_->SetValue(String("Carbon steel"));
				description_->SetValue(String("ISO 898-2"));
				name_->SetValue(String("Grade 12"));

				density_->SetValue(7850.0);
				poissonRatio_->SetValue(0.30);
				specificHeat_->SetValue(470.0);
				thermalConductivity_->SetValue(42.5);
				thermalExpansion_->SetValue(1.11E-05);
				elasticModulus_->SetValue(2.05e+11);
				yieldStrength_->SetValue(1.10E+09);
				tensileStrength_->SetValue(1.22E+09);
				shearStrength_->SetValue(0.60 * tensileStrength_->GetValue(T_ref, p_ref));
			}
		}
	}
} // namespace material