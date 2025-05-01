#ifndef MATERIAL_SOLID_HPP_
#define MATERIAL_SOLID_HPP_

#include "material_base.hpp"

namespace material
{
	class MaterialSolid;
	using MaterialSolidPtr = std::shared_ptr< MaterialSolid >;
	using ConstMaterialSolidPtr = std::shared_ptr< const MaterialSolid >;

	MaterialSolidPtr CreateMaterialSolid(Tag materialTag);

	class MaterialSolid : public IMaterialSolid, virtual public std::enable_shared_from_this<MaterialSolid>
	{
	public:
		virtual ~MaterialSolid() = default;

		static MaterialSolidPtr Create();
		MaterialSolidPtr GetPtr();
		ConstMaterialSolidPtr GetPtr() const;

		Tag GetTag() const override;
		Type GetType() const override;
		String GetClass() const override;
		String GetGroup() const override;
		String GetDescription() const override;
		String GetName() const override;

		Scalar GetDensity(Scalar temperature, Scalar pressure) const override;
		Scalar GetSpecificHeat(Scalar temperature, Scalar pressure) const override;
		Scalar GetThermalConductivity(Scalar temperature, Scalar pressure) const override;
		Scalar GetThermalExpansion(Scalar temperature, Scalar pressure) const override;
		Scalar GetPoissonRatio(Scalar temperature, Scalar pressure) const override;
		Scalar GetElasticModulus(Scalar temperature, Scalar pressure) const override;
		IValuePtr GetProperty(String key) const override;

		void SetClass(IStringPtr value) override;
		void SetGroup(IStringPtr value) override;
		void SetDescription(IStringPtr value) override;
		void SetName(IStringPtr value) override;
		void SetTag(const Tag& tag) override;

		void SetDensity(IScalar2DPtr value) override;
		void SetSpecificHeat(IScalar2DPtr value) override;
		void SetThermalConductivity(IScalar2DPtr value) override;
		void SetPoissonRatio(IScalar2DPtr value) override;
		void SetThermalExpansion(IScalar2DPtr value) override;
		void SetElasticModulus(IScalar2DPtr value) override;
		void SetProperty(IValuePtr value) override;

		Matrix A(Scalar temperature, Scalar pressure) const override;
		Matrix D(Scalar temperature, Scalar pressure) const override;
		Matrix K(Scalar temperature, Scalar pressure) const override;

	protected:
		MaterialSolid();

		Tag tag_ { 0 };
		Type type_{ material_solid };

		IStringPtr class_{ nullptr };
		IStringPtr group_{ nullptr };
		IStringPtr description_{ nullptr };
		IStringPtr name_{ nullptr };
	
		IScalar2DPtr density_{ nullptr };
		IScalar2DPtr poissonRatio_{ nullptr };
		IScalar2DPtr specificHeat_{ nullptr };
		IScalar2DPtr thermalConductivity_{ nullptr };
		IScalar2DPtr thermalExpansion_{ nullptr };
		IScalar2DPtr elasticModulus_{ nullptr };

		Properties properties_;
	};
} // namespace material

#endif /* MATERIAL_SOLID_HPP_*/
