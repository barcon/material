#ifndef MATERIAL_FLUID_HPP_
#define MATERIAL_FLUID_HPP_

#include "material_base.hpp"

namespace material
{

	class MaterialFluid;
	using MaterialFluidPtr = std::shared_ptr< MaterialFluid >;
	using ConstMaterialFluidPtr = std::shared_ptr< const MaterialFluid >;

	MaterialFluidPtr CreateMaterialFluid(Tag materialTag);

	class MaterialFluid : public IMaterialFluid, virtual public std::enable_shared_from_this<MaterialFluid>
	{
	public:
		virtual ~MaterialFluid() = default;

		static MaterialFluidPtr Create();
		MaterialFluidPtr GetPtr();
		ConstMaterialFluidPtr GetPtr() const;

		Tag GetTag() const override;
		Type GetType() const override;
		String GetClass() const override;
		String GetGroup() const override;
		String GetDescription() const override;
		String GetName() const override;

		Scalar GetDensity(Scalar temperature, Scalar pressure) const override;
		Scalar GetSpecificHeat(Scalar temperature, Scalar pressure) const override;
		Scalar GetThermalConductivity(Scalar temperature, Scalar pressure) const override;
		Scalar GetDynamicViscosity(Scalar temperature, Scalar pressure) const override;
		IValuePtr GetProperty(String key) const override;

		void SetClass(IStringPtr value) override;
		void SetGroup(IStringPtr value) override;
		void SetDescription(IStringPtr value) override;
		void SetName(IStringPtr value) override;
		void SetTag(const Tag& tag) override;

		void SetDensity(IScalar2DPtr value) override;
		void SetSpecificHeat(IScalar2DPtr value) override;
		void SetThermalConductivity(IScalar2DPtr value) override;
		void SetDynamicViscosity(IScalar2DPtr value) override;
		void SetProperty(IValuePtr value) override;

		Matrix D(Scalar temperature, Scalar pressure) const override;
		Matrix K(Scalar temperature, Scalar pressure) const override;

	protected:
		MaterialFluid();

		Tag tag_{ 0 };
		Type type_{ material_fluid };

		Matrix m_;
		Matrix I0_;
		Matrix Id_;

		IStringPtr class_{ nullptr };
		IStringPtr group_{ nullptr };
		IStringPtr description_{ nullptr };
		IStringPtr name_{ nullptr };

		IScalar2DPtr density_{ nullptr };
		IScalar2DPtr specificHeat_{ nullptr };
		IScalar2DPtr thermalConductivity_{ nullptr };
		IScalar2DPtr dynamicViscosity_{ nullptr };

		Properties properties;
	};
	
} // namespace material

#endif /* MATERIAL_FLUID_HPP_*/
