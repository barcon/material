#ifndef MATERIAL_SOLID_HPP_
#define MATERIAL_SOLID_HPP_

#include "material_base.hpp"

namespace material
{
	class MaterialSolid;
	using MaterialSolidPtr = std::shared_ptr< MaterialSolid >;
	using ConstMaterialSolidPtr = std::shared_ptr< const MaterialSolid >;

	MaterialSolidPtr CreateSolid(Tag materialTag);
	MaterialSolidPtr CreateSolidUnit(Tag materialTag);

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

		Scalar GetDensity(const Vector& state) const override;
		Scalar GetSpecificHeat(const Vector& state) const override;
		Scalar GetThermalConductivity(const Vector& state) const override;
		Scalar GetThermalExpansion(const Vector& state) const override;
		Scalar GetPoissonRatio(const Vector& state) const override;
		Scalar GetElasticModulus(const Vector& state) const override;
		IValuePtr GetProperty(String key) const override;

		void SetClass(IStringPtr value) override;
		void SetGroup(IStringPtr value) override;
		void SetDescription(IStringPtr value) override;
		void SetName(IStringPtr value) override;
		void SetTag(const Tag& tag) override;

		void SetDensity(IScalarCoordinatesPtr value) override;
		void SetSpecificHeat(IScalarCoordinatesPtr value) override;
		void SetThermalConductivity(IScalarCoordinatesPtr value) override;
		void SetPoissonRatio(IScalarCoordinatesPtr value) override;
		void SetThermalExpansion(IScalarCoordinatesPtr value) override;
		void SetElasticModulus(IScalarCoordinatesPtr value) override;
		void SetProperty(IValuePtr value) override;

		Matrix A(const Vector& state) const override;
		Matrix D(const Vector& state) const override;
		Matrix K(const Vector& state) const override;

	protected:
		MaterialSolid();

		Tag tag_ { 0 };
		Type type_{ material_solid };

		IStringPtr class_{ nullptr };
		IStringPtr group_{ nullptr };
		IStringPtr description_{ nullptr };
		IStringPtr name_{ nullptr };
	
		IScalarCoordinatesPtr density_{ nullptr };
		IScalarCoordinatesPtr poissonRatio_{ nullptr };
		IScalarCoordinatesPtr specificHeat_{ nullptr };
		IScalarCoordinatesPtr thermalConductivity_{ nullptr };
		IScalarCoordinatesPtr thermalExpansion_{ nullptr };
		IScalarCoordinatesPtr elasticModulus_{ nullptr };

		Properties properties_;
	};
} // namespace material

#endif /* MATERIAL_SOLID_HPP_*/
