#ifndef MATERIAL_FLUID_HPP_
#define MATERIAL_FLUID_HPP_

#include "material_base.hpp"

namespace material
{

	class MaterialFluid;
	using MaterialFluidPtr = std::shared_ptr< MaterialFluid >;
	using ConstMaterialFluidPtr = std::shared_ptr< const MaterialFluid >;

	MaterialFluidPtr CreateMaterialFluid(Tag materialTag);
	MaterialFluidPtr CreateMaterialFluidUnit(Tag materialTag);

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

		Scalar GetDensity(const Vector& state) const override;
		Scalar GetSpecificHeat(const Vector& state) const override;
		Scalar GetThermalConductivity(const Vector& state) const override;
		Scalar GetDynamicViscosity(const Vector& state) const override;
		IValuePtr GetProperty(String key) const override;

		void SetClass(IStringPtr value) override;
		void SetGroup(IStringPtr value) override;
		void SetDescription(IStringPtr value) override;
		void SetName(IStringPtr value) override;
		void SetTag(const Tag& tag) override;

		void SetDensity(IScalarCoordinatesPtr value) override;
		void SetSpecificHeat(IScalarCoordinatesPtr value) override;
		void SetThermalConductivity(IScalarCoordinatesPtr value) override;
		void SetDynamicViscosity(IScalarCoordinatesPtr value) override;
		void SetProperty(IValuePtr value) override;

		Matrix D(const Vector& state) const override;
		Matrix K(const Vector& state) const override;

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

		IScalarCoordinatesPtr density_{ nullptr };
		IScalarCoordinatesPtr specificHeat_{ nullptr };
		IScalarCoordinatesPtr thermalConductivity_{ nullptr };
		IScalarCoordinatesPtr dynamicViscosity_{ nullptr };

		Properties properties_;
	};
	
} // namespace material

#endif /* MATERIAL_FLUID_HPP_*/
