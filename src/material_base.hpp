#ifndef MATERIAL_BASE_HPP_
#define MATERIAL_BASE_HPP_

#include "material_types.hpp"

namespace material
{
	Vector CreateState(Scalar temperature, Scalar pressure);

	class IBase;
	using IBasePtr = std::shared_ptr<IBase>;
	using ConstIBasePtr = std::shared_ptr<const IBase>;

	class IBase
	{
	public:
		virtual ~IBase() = default;

		virtual Tag GetTag() const = 0;
		virtual Type GetType() const = 0;
		virtual String GetClass() const = 0;
		virtual String GetGroup() const = 0;
		virtual String GetDescription() const = 0;
		virtual String GetName() const = 0;
		virtual IValuePtr GetProperty(String key) const = 0;

		virtual void SetClass(IStringPtr value) = 0;
		virtual void SetGroup(IStringPtr value) = 0;
		virtual void SetDescription(IStringPtr value) = 0;
		virtual void SetName(IStringPtr value) = 0;
		virtual void SetTag(const Tag& tag) = 0;
		virtual void SetProperty(IValuePtr value) = 0;
	};

	class IMaterial;
	using IMaterialPtr = std::shared_ptr< IMaterial >;
	using ConstIMaterialPtr = std::shared_ptr< const IMaterial >;

	class IMaterial: public IBase
	{
	public:
		virtual ~IMaterial() = default;

		virtual Scalar GetDensity(const Vector& state) const = 0;
		virtual Scalar GetSpecificHeat(const Vector& state) const = 0;
		virtual Scalar GetThermalConductivity(const Vector& state) const = 0;

		virtual void SetDensity(IScalarCoordinatesPtr value) = 0;
		virtual void SetSpecificHeat(IScalarCoordinatesPtr value) = 0;
		virtual void SetThermalConductivity(IScalarCoordinatesPtr value) = 0;

		virtual Matrix K(const Vector& state) const = 0;
	};

	class IMaterialFluid;
	using IMaterialFluidPtr = std::shared_ptr< IMaterialFluid >;
	using ConstIMaterialFluidPtr = std::shared_ptr< const IMaterialFluid >;

	class IMaterialFluid : public IMaterial
	{
	public:
		virtual ~IMaterialFluid() = default;

		virtual Scalar GetDynamicViscosity(const Vector& state) const = 0;
		virtual void SetDynamicViscosity(IScalarCoordinatesPtr value) = 0;

		virtual Matrix D(const Vector& state) const = 0;
	};

	class IMaterialSolid;
	using IMaterialSolidPtr = std::shared_ptr< IMaterialSolid >;
	using ConstIMaterialSolidPtr = std::shared_ptr< const IMaterialSolid >;

	class IMaterialSolid : public IMaterial
	{
	public:
		virtual ~IMaterialSolid() = default;

		virtual Scalar GetPoissonRatio(const Vector& state) const = 0;
		virtual Scalar GetThermalExpansion(const Vector& state) const = 0;
		virtual Scalar GetElasticModulus(const Vector& state) const = 0;

		virtual void SetPoissonRatio(IScalarCoordinatesPtr value) = 0;
		virtual void SetThermalExpansion(IScalarCoordinatesPtr value) = 0;
		virtual void SetElasticModulus(IScalarCoordinatesPtr value) = 0;

		virtual Matrix A(const Vector& state) const = 0;
		virtual Matrix D(const Vector& state) const = 0;
	};

} // namespace material

#endif /* MATERIAL_BASE_HPP_*/