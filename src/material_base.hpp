#ifndef MATERIAL_BASE_HPP_
#define MATERIAL_BASE_HPP_

#include "material_types.hpp"

namespace material
{
	static const Type material_solid = 1;
	static const Type material_fluid = 2;

/*
		virtual void AddPropertyBool(IBoolPtr value) = 0;
		virtual void AddPropertyString(IStringPtr value) = 0;
		virtual void AddPropertyScalar(IScalarPtr value) = 0;
		virtual void AddPropertyScalar1D(IScalar1DPtr value) = 0;
		virtual void AddPropertyScalar2D(IScalar2DPtr value) = 0;
		virtual void AddPropertyScalar3D(IScalar3DPtr value) = 0;
		virtual void AddPropertyVector(IVectorPtr value) = 0;
		virtual void AddPropertyVector3D(IVector3DPtr value) = 0;
		virtual void AddPropertyMatrix(IMatrixPtr value) = 0;
		virtual void AddPropertyMatrix3D(IMatrix3DPtr value) = 0;

		virtual IBoolPtr GetPropertyBool() = 0;
		virtual IStringPtr GetPropertyString() = 0;
		virtual IScalarPtr GetPropertyScalar() = 0;
		virtual IScalar1DPtr GetPropertyScalar1D() = 0;
		virtual IScalar2DPtr GetPropertyScalar2D() = 0;
		virtual IScalar3DPtr GetPropertyScalar3D() = 0;
		virtual IVectorPtr GetPropertyVector() = 0;
		virtual IVector3DPtr GetPropertyVector3D() = 0;
		virtual IMatrixPtr GetPropertyMatrix() = 0;
		virtual IMatrix3DPtr GetPropertyMatrix3D() = 0;

*/

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

		virtual Scalar GetDensity(Scalar temperature, Scalar pressure) const = 0;
		virtual Scalar GetSpecificHeat(Scalar temperature, Scalar pressure) const = 0;
		virtual Scalar GetThermalConductivity(Scalar temperature, Scalar pressure) const = 0;

		virtual void SetDensity(IScalar2DPtr value) = 0;
		virtual void SetSpecificHeat(IScalar2DPtr value) = 0;
		virtual void SetThermalConductivity(IScalar2DPtr value) = 0;

		virtual Matrix K(Scalar temperature, Scalar pressure) const = 0;
	};

	class IMaterialFluid;
	using IMaterialFluidPtr = std::shared_ptr< IMaterialFluid >;
	using ConstIMaterialFluidPtr = std::shared_ptr< const IMaterialFluid >;

	class IMaterialFluid : public IMaterial
	{
	public:
		virtual ~IMaterialFluid() = default;

		virtual Scalar GetDynamicViscosity(Scalar temperature, Scalar pressure) const = 0;
		virtual void SetDynamicViscosity(IScalar2DPtr value) = 0;

		virtual Matrix D(Scalar temperature, Scalar pressure) const = 0;
	};

	class IMaterialSolid;
	using IMaterialSolidPtr = std::shared_ptr< IMaterialSolid >;
	using ConstIMaterialSolidPtr = std::shared_ptr< const IMaterialSolid >;

	class IMaterialSolid : public IMaterial
	{
	public:
		virtual ~IMaterialSolid() = default;

		virtual Scalar GetPoissonRatio(Scalar temperature, Scalar pressure) const = 0;
		virtual Scalar GetThermalExpansion(Scalar temperature, Scalar pressure) const = 0;
		virtual Scalar GetElasticModulus(Scalar temperature, Scalar pressure) const = 0;

		virtual void SetPoissonRatio(IScalar2DPtr value) = 0;
		virtual void SetThermalExpansion(IScalar2DPtr value) = 0;
		virtual void SetElasticModulus(IScalar2DPtr value) = 0;

		virtual Matrix A(Scalar temperature, Scalar pressure) const = 0;
		virtual Matrix D(Scalar temperature, Scalar pressure) const = 0;
	};

} // namespace material

#endif /* MATERIAL_BASE_HPP_*/